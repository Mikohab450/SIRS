#include<iostream>
#include"SIR.h"
#include<ctime>
#include <cstdlib>


int main(int argc, char* argv[]) {

		bool N_check =false, M_check = false, p_check=false, i_check = false, file_check = false;
	
	srand(time(NULL));
	int N, M, it;
	double p;
	string file, tmp;;
	for (int i = 1; i < argc; i++)
	{
		tmp = argv[i];
		if (tmp == "-N")
		{
			N = atoi(argv[++i]);
			N_check = true;
		}
		if (tmp == "-M")
		{
			M = atoi(argv[++i]);
			M_check = true;
		}
		if (tmp == "-i")
		{
			it = atoi(argv[++i]);
			i_check = true;
		}
		if (tmp == "-p")
		{
			p = atof(argv[++i]);
			p_check = true;
		}
		if (tmp == "-o")
		{
			file = argv[++i];
			file_check = true;
		}

	}
	if (N_check && M_check && i_check && p_check &&file_check) {
		population testowa(file, N, M, p);

		for (int iteration = 0; iteration < it; iteration++) {
			testowa.generate();
		}
	}
	else
		cout << "ERROR 420";


	return 0;
}