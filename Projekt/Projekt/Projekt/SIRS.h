#pragma once
#include<iostream>
#include<vector>
#include<fstream>
#include"person.h"
using namespace std;



class population
{
	int size_of_population;
	int length_of_board;
	int width_of_board;
	double probability_1;
	double probability_2;
	vector<vector<person*> > current_board;
	vector<vector<person*> > future_board;
	public:
		bool all_population_healthy;
		int num_of_infected;
		int num_of_susceptible;
		int num_of_resistable;
		population(int N_, int M_, double p);
		void generate();
		~population();
};
bool sick(double propability);
void show_help();