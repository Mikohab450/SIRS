#pragma once
#include<iostream>
using namespace std;

class person {
	public:
		person() {}
		person(int c) {}
		virtual int get_time()const = 0;
		virtual person &  operator--() = 0;
		virtual void dec() = 0;
	//	person & operator=(person &p);
};

class infected: public person{
	int t;
	public:
		 infected() : person(), t(2) {}
		 virtual int get_time()const {
			return t;
		 }
		 infected &  operator--();
		 virtual void dec();
};

class resistable :public person {

	int t;
	public:
		resistable() :person(), t(1) {}
		virtual int get_time()const {
			return t;
		}
		resistable &  operator--();
		virtual void dec();
};

class susceptible :public person {

	public:
		susceptible() : person() {}
		virtual int get_time()const {
			return 0;
		}
		susceptible &  operator--() { return *this; };
		virtual void dec() {};
};
bool sick(double propability);