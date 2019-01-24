#include<iostream>
#include"SIRS.h"
#include"person.h"
#include<ctime>
#include <cstdlib>


int main(int argc, char* argv[]) {

	//srand(time(NULL));
	int N = 30;
	int M = 30;
	int it=50;
	double p=0.5;
	string file = "default_file_out.txt";
	string tmp=argv[argc-1];
	if (tmp == "-h")
		show_help();
	for (int i = 1; i < argc-1; i++)
	{
		tmp = argv[i];
		if (tmp == "-N")
		{
			if(0<atoi(argv[++i]))
				N = atoi(argv[i]);
		}
		if (tmp == "-M")
		{
			if(0<atoi(argv[++i]))
				M = atoi(argv[i]);
		}
		if (tmp == "-i")
		{
			it = atoi(argv[++i]);
		}
		if (tmp == "-p")
		{
			p = atof(argv[++i]);

		}
		if (tmp == "-o")
		{
			file = argv[++i];

		}
		if (tmp == "-h")
			show_help();
	}
	ofstream file_out(file);
	
		population testowa(N, M, p);
		for (int iteration = 0; iteration < it && !testowa.all_population_healthy; iteration++) {
			testowa.generate();
			file_out << "iteracja " << iteration << endl << "chorych: " << testowa.num_of_infected << endl << "zdrowych: " << testowa.num_of_susceptible << endl << "odpornych: " << testowa.num_of_resistable << endl << endl;
		//	file_out << testowa.num_of_infected << "\t " << testowa.num_of_susceptible << "\t " << testowa.num_of_resistable << endl;
		}




	return 0;
}