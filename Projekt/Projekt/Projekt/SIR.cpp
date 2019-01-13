
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
/*
void simulate(int N, int M, double p1, string file_name, int it) {
	
	//vector<vector<person*> > tab1(N, vector<person*>(M,new susceptible())); //dwuwymiarowy wektor wskaznikow na obiekty
//	ofstream file_;
	//tab1[N/2][M/2] = new infected();
	//file_.open(file_name);
	population testowa(file_name, N, M, p1);
	for (int iteration = 0; iteration < it; iteration++) {
	
		testowa.generate();
	//	swap(tab1, tab2);
	}
}
*/



population::population(string file_name, int N_, int M_, double p) : N(N_), M(M_), p1(p), p2(0.7*p) {
	file_.open(file_name);
//	tab1.reserve(N, vector<person*>(M, new susceptible()));
	//tab2.reserve(N);
	//tab1[N / 2][M / 2] = new infected();
}
void population::generate()//const vector<vector<person*>> & tab1,vector<vector<person*>> & tab2)
{
	//double p2 = p1*0.7;
	//vector<vector<person*> > tab2(N, vector<person*>(M));
	bool stayed_healthy;
	int count_infected, count_healthy, count_resistable;
	int current_neighbour_i, current_neighbour_j;			//Oznaczenia wspolrzednych aktualnie wyliczanej komorki sasiedniej

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
									if (sick(p1))
									{
										tab2[i][j] = new infected();
										stayed_healthy = false;
										break;
									}
									else {}
								else				//rogi sasiedztwa moore'a
									if (sick(p2)) {
										tab2[i][j] = new infected();
										stayed_healthy = false;
										break;
									}
							}
						}
					if (stayed_healthy)
					{
						tab2[i][j] = new susceptible();
						count_healthy++;
					}
					else { count_infected++; }
				}
				else
				{
					if (tab1[i][j] == dynamic_cast<infected*>(tab1[i][j]))	//jezeli osobnik jestchory
					{

						if ((--(*tab1[i][j])).get_time() == 0)
						{
							tab2[i][j] = new resistable();
							count_resistable++;
						}
						else
						{
							tab2[i][j] = tab1[i][j];
							count_infected++;
						}
					}
					else
					{
										//jezeli osobnik jest odporny
					}
					{
						if ((--(*tab1[i][j])).get_time() == 0)
						{
							tab2[i][j] = new susceptible();
							count_healthy++;
						}
						else
						{
							tab2[i][j] = tab1[i][j];
							count_resistable++;
						}
					}
				}
			}
		
		file_<< endl << "zdrowych: " << count_healthy << endl << "chorych: " << count_infected << endl << "odpornych: " << count_resistable << endl;
		file_ << endl;

}

