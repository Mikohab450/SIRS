
#include"SIR.h"
#include<cstdlib>

bool sick(double propability)
{
	double p;
	p = (double)rand() / RAND_MAX;
	if (p < propability)
		return true;
	else
		return false;
}
infected & infected::operator--() {
	t--;
	return *this;
}
resistable & resistable::operator--() {
	t--;
	return *this;
}
void resistable::dec() {
	t--;
}
void infected::dec() {
	t--;
}


infected::infected(person* &p)
{
	t = p->get_time();	//
}
resistable::resistable( person* &p)
{
	t = p->get_time();
}

population::population(string file_name, int N_, int M_, double p) : N(N_), M(M_), p1(p), p2(0.7*p) {
	file_.open(file_name);
	for (int i = 0; i < N; i++)
	{
		tab2.push_back(vector<person*>());
		tab1.push_back(vector<person*>());
		for (int j = 0; j < M; j++)
		{
			tab2[i].push_back(new susceptible());
			tab1[i].push_back(new susceptible());
		}
	}
	tab1[N / 2][M / 2] = new infected();
}

population::~population() {
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)

			delete tab1[i][j];
	}
}
void population::generate()
{
	bool stayed_healthy;
	int count_infected = 0, count_healthy = 0, count_resistable = 0;
	int current_neighbour_i, current_neighbour_j;			//Oznaczenia wspolrzednych aktualnie wyliczanej komorki sasiedniej
	//--(*tab1[1][1]);
	//tab2[1][1] = new infected(tab1[1][1]);
	
		count_infected = count_healthy = count_resistable = 0;
		for (int i = 0; i < N; i++)
			for (int j = 0; j < M; j++)
			{
				if (tab1[i][j] == dynamic_cast<susceptible*>(tab1[i][j]))			//jezeli osobnik jest zdrowy
				{
					stayed_healthy = true;
					for (int n = -1; n < 2; n++)
						for (int m = -1; m < 2; m++)
						{
							if (m == 0 && n == 0)
								continue;
							current_neighbour_i = i + n;
							current_neighbour_j = j + m;
							if (current_neighbour_i < 0)	//Sprawdzanie  czy wspolrzedne nie przekraczasja zakresu tablicy
								current_neighbour_i = N - 1;
							else
								if (current_neighbour_i > N - 1)
									current_neighbour_i = 0;
							if (current_neighbour_j < 0)
								current_neighbour_j = M - 1;
							else
								if (current_neighbour_j > M - 1)
									current_neighbour_j = 0;
							if (tab1[current_neighbour_i][current_neighbour_j] == dynamic_cast<infected*>(tab1[current_neighbour_i][current_neighbour_j])) {			//jezeli sasiad jest chory
								if (abs(n) + abs(m) == 1)	//sasiedztwo von neumanna
									if (sick(p1))					//jezeli zachorowal
									{	
										delete tab2[i][j];
										tab2[i][j] = new infected();
										stayed_healthy = false;
										break;
									}
									else {}
								else				//rogi sasiedztwa moore'a
									if (sick(p2)) {							//jezeli zachorowal
										delete tab2[i][j];
										tab2[i][j] = new infected();
										stayed_healthy = false;
										break;
									}
							}
						}
					if (stayed_healthy)									//jezeli nie zachorowal
					{
						delete tab2[i][j];
						tab2[i][j] = new susceptible();
						count_healthy++;
					}
					else { count_infected++; }
				}
				else
				{
					if (tab1[i][j] == dynamic_cast<infected*>(tab1[i][j]))	//jezeli osobnik jest chory
					{

						if ((--(*tab1[i][j])).get_time() == 0)
						{
							delete tab2[i][j];
							tab2[i][j] = new resistable();
							count_resistable++;
						}
						else
						{
							delete tab2[i][j];
							tab2[i][j] = new infected(tab1[i][j]);
							count_infected++;
						}
					}
					else	                         		//jezeli osobnik jest odporny
					{
						if ((--(*tab1[i][j])).get_time() == 0)
						{
							delete tab2[i][j];
							tab2[i][j] = new susceptible();
							count_healthy++;
						}
						else
						{
							delete tab2[i][j];
							tab2[i][j] = new resistable(tab1[i][j]);
							count_resistable++;
						}
					}
				}
			}
		swap(tab1, tab2);
		file_<< endl << "zdrowych: " << count_healthy << endl << "chorych: " << count_infected << endl << "odpornych: " << count_resistable << endl;
		file_ << endl;
}

