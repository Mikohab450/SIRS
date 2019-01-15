#include<iostream>
#include"SIR.h"
#include<ctime>
#define _CRTDBG_MAP_ALLOC
#include <cstdlib>
#include <crtdbg.h>
#define new new(_NORMAL_BLOCK, __FILE__, __LINE__)

int main(int argc, char* argv[]) {
	
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
			p = atof(argv[++i]);

		}
		if (tmp == "-o")
		{
			file = argv[++i];
		}

	}
	population testowa(file, N, M, p);

	for (int iteration = 0; iteration < it; iteration++) {
		testowa.generate();
	}

	_CrtDumpMemoryLeaks();

	return 0;
}