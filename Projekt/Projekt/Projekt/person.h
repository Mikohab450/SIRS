#pragma once
#include<iostream>
#include<vector>
#include<fstream>
using namespace std;

class person {
public:
	person() {}
	virtual int get_time()const = 0;
	virtual person &  operator--() = 0;

};

class infected : public person {
	int time_left;
public:
	infected() : person(), time_left(7) {}
	infected(person* & p);
	virtual int get_time()const {return time_left;}
	infected &  operator--();
};

class resistable :public person {
	int time_left;
public:
	resistable() :person(), time_left(4) {}
	resistable(person* &p);
	virtual int get_time()const {return time_left;}
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
