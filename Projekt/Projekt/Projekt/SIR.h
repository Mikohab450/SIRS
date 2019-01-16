#pragma once
#include<iostream>
#include<vector>
#include<fstream>
#define _CRTDBG_MAP_ALLOC
#define new new(_NORMAL_BLOCK, __FILE__, __LINE__)
using namespace std;

class person {
	public:
		person() {}
		person(int c) {}
		virtual int get_time()const = 0;
		virtual person &  operator--() = 0;
	
};

class infected: public person{
	int t;
	public:
		 infected() : person(), t(7) {}
		 infected(person* & p);
		 virtual int get_time()const {
			return t;
		 }
		 infected &  operator--();

};

class resistable :public person {

	int t;
	public:
		resistable() :person(), t(4) {}
		resistable( person* &p );
		virtual int get_time()const {
			return t;
		}
		resistable &  operator--();
};

class susceptible :public person {

	public:
		susceptible() : person() {};
		susceptible(const person* &) {};
		virtual int get_time()const {
			return 0;
		}
		susceptible &  operator--() { return *this; };
};

class population
{
	ofstream file_;
	int N;
	int M;
	double p1;
	double p2;
	vector<vector<person*> > tab1;
	vector<vector<person*> > tab2;
	public:
		population(string file_name, int N_, int M_, double p);
		void generate();
		~population();
};
bool sick(double propability);
