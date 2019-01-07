#include<iostream>
#include"SIR.h"
#include<vector>
#define _CRTDBG_MAP_ALLOC
#include <cstdlib>
#include <crtdbg.h>
#define new new(_NORMAL_BLOCK, __FILE__, __LINE__)
int main(int argc, char* argv[]) {

	int N, M, it;
	double p1,p2;
	string file, tmp;;
	for (int i = 1; i < argc; i++)
	{
		tmp = argv[i];
		if (tmp == "-N")
		{
			N = atoi(argv[++i]);
		}
		if (tmp == "-M")
		{
			M = atoi(argv[++i]);
		}
		if (tmp == "-i")
		{
			it = atoi(argv[++i]);
		}
		if (tmp == "-p")
		{
			p1 = atof(argv[++i]);
			p2 = p1 * 0.7;
		}
		if (tmp == "-o")
		{
			file = argv[++i];
		}

	}
	/*for (int i = 0; i < 10; i++)
	{
		if (sick(p))
			cout << "1" << endl;
		else
			cout << "0" << endl;
	}*/


	vector<vector<person*> > tab1  (N,vector<person*> (M)); //dwuwymiarowy wektor wskaznikow na obiekty
	vector<vector<person*> > tab2(N, vector<person*>(M));

	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			tab1[i][j] = new susceptible();
	tab1[N/2][N/2] = new infected();
	//--(*tab1[1][1]);
	bool stayed_healthy;
	int count_infected,count_healthy, count_resistable;
	int current_neighbour_i, current_neighbour_j;			//Oznaczenia wspolrzednych aktualnie wyliczanej komorki sasiedniej
	for(int iteration=0;iteration<it;iteration++)
	{
	count_infected = count_healthy= count_resistable=0;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
		{
			if (tab1[i][j] == dynamic_cast<susceptible*>(tab1[i][j]))
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
						if (tab1[current_neighbour_i][current_neighbour_j] == dynamic_cast<infected*>(tab1[current_neighbour_i][current_neighbour_j])) {
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
									stayed_healthy=false;
									break;
								}
						}
					}
				if (stayed_healthy)
				{
					tab2[i][j] = new susceptible();
					count_healthy++;
				}
				else{ count_infected++; }
			}
			else
			{
				if (tab1[i][j] == dynamic_cast<infected*>(tab1[i][j]))
				{
					tab1[i][j]->dec();
					if (tab1[i][j]->get_time() == 0)
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
					tab1[i][j]->dec();
					if (tab1[i][j]->get_time() == 0)
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
	swap(tab1, tab2);
	cout <<"iteracja"<< iteration<<endl<< "zdrowych: "<<count_healthy << endl<<"chorych: "<<count_infected<<endl<<"odpornych: "<<count_resistable<<endl;
	cout << endl;
	}
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
		{
//			delete tab1[i][j];
			delete tab2[i][j];
		}
	_CrtDumpMemoryLeaks();
	return 0;
}