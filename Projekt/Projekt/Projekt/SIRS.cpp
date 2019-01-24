
#include"SIRS.h"
#include"person.h"
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
void show_help(){
	cout << "Program nalezy uruchomic z nastepujacymi parametrami:" << endl;
	cout << "-M \t szerokosc planszy"<<endl;
	cout << "-N \t wysokosc planszy"<<endl;
	cout << "-it \t liczba iteracji"<<endl;
	cout << "-p \t prawdopodobienstwo zarazenia"<<endl;
	cout << "-o \t nazwa pliku wyjsciowego"<<endl;
}


population::population(int N_, int M_, double p) :all_population_healthy(false), length_of_board(N_), width_of_board(M_), probability_1(p), probability_2(0.7*p) {
	for (int i = 0; i < length_of_board; i++)
	{
		future_board.push_back(vector<person*>());
		current_board.push_back(vector<person*>());
		for (int j = 0; j < width_of_board; j++)
		{
			future_board[i].push_back(new susceptible());		//zapelnianie tablic wartosciami poczatkkowymi
			current_board[i].push_back(new susceptible());
		}
	}
	size_of_population = length_of_board*width_of_board;		//poczatkowe ustawienie licznikow
	num_of_resistable = 0;
	num_of_susceptible = size_of_population - 1;
	num_of_infected = 1;
	int i = rand() % length_of_board;			//losowe rozmieszczenie jednostki chorej
	int j = rand() % width_of_board;
	delete current_board[i][j];
	current_board[i][j] = new infected();
}

population::~population() {
	for (int i = 0; i < length_of_board; i++)
	{
		for (int j = 0; j < width_of_board; j++)
		{
			delete current_board[i][j];
			delete future_board[i][j];
		}
	}
}
void population::generate()
{
	bool stayed_healthy;
	int count_infected = 0, count_healthy = 0, count_resistable = 0;
	int current_neighbour_i, current_neighbour_j;			//Oznaczenia wspolrzednych aktualnie wyliczanej komorki sasiedniej

	
		count_infected = count_healthy = count_resistable = 0;
		for (int i = 0; i < length_of_board; i++)
			for (int j = 0; j < width_of_board; j++)
			{
				if (current_board[i][j] == dynamic_cast<susceptible*>(current_board[i][j]))			//jezeli osobnik jest zdrowy
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
								current_neighbour_i = length_of_board - 1;
							else
								if (current_neighbour_i > length_of_board - 1)
									current_neighbour_i = 0;
							if (current_neighbour_j < 0)
								current_neighbour_j = width_of_board - 1;
							else
								if (current_neighbour_j > width_of_board - 1)
									current_neighbour_j = 0;
							if (current_board[current_neighbour_i][current_neighbour_j] == dynamic_cast<infected*>(current_board[current_neighbour_i][current_neighbour_j])) {			//jezeli sasiad jest chory
								if (abs(n) + abs(m) == 1)	//sasiedztwo von neumanna
									if (sick(probability_1))					//jezeli zachorowal
									{	
										delete future_board[i][j];
										future_board[i][j] = new infected();
										stayed_healthy = false;
										break;
									}
									else {}
								else				//rogi sasiedztwa moore'a
									if (sick(probability_2)) {							//jezeli zachorowal
										delete future_board[i][j];
										future_board[i][j] = new infected();
										stayed_healthy = false;
										break;
									}
							}
						}
					if (stayed_healthy)									//jezeli nie zachorowal
					{
						delete future_board[i][j];
						future_board[i][j] = new susceptible();
						count_healthy++;
					}
					else { count_infected++; }
				}
				else
				{
					if (current_board[i][j] == dynamic_cast<infected*>(current_board[i][j]))	//jezeli osobnik jest chory
					{

						if ((--(*current_board[i][j])).get_time() == 0)
						{
							delete future_board[i][j];
							future_board[i][j] = new resistable();
							count_resistable++;
						}
						else
						{
							delete future_board[i][j];
							future_board[i][j] = new infected(current_board[i][j]);
							count_infected++;
						}
					}
					else	                         		//jezeli osobnik jest odporny
					{
						if ((--(*current_board[i][j])).get_time() == 0)
						{
							delete future_board[i][j];
							future_board[i][j] = new susceptible();
							count_healthy++;
						}
						else
						{
							delete future_board[i][j];
							future_board[i][j] = new resistable(current_board[i][j]);
							count_resistable++;
						}
					}
				}
			}
		swap(current_board, future_board);
		if(count_healthy == size_of_population)
		{
			all_population_healthy = true;
		}
		else {}
		num_of_susceptible = count_healthy;
		num_of_resistable = count_resistable;
		num_of_infected = count_infected;
}

