#pragma once
#include<iostream>
#include<string>
using namespace std;


class CZwierze {
public:
	string nazwa;
	double waga;;
	CZwierze() :nazwa("zwierze"), waga(0) { cout << "konstruktor bezarg czwierze\n"; }
	CZwierze(string nazwa_, double waga_) :nazwa(nazwa_), waga(waga_) { cout << "konstruktor argumentowy1\n"; }
	virtual ~CZwierze() { cout << "destruktor1\n"; }
	virtual void zjedz() = 0;
};

class CSsak:public CZwierze{
public:
	int speed;

	CSsak() :CZwierze(),speed(0) { cout << "konstruktor bezarg cssak\n"; }
	CSsak(string nazwa_, double waga_,int speed_) :CZwierze(nazwa_,waga_), speed(speed_){ cout << "konstruktor argumentowy2\n"; }
	~CSsak() { cout << "destruktor2\n"; }
	void zjedz() { cout << "ssak" << nazwa << "je\n"; }
};

class CPtak:public CZwierze {
private:
	int speed;
public:
	CPtak() :CZwierze(), speed(0) { cout << "konstruktor bezarg cptak\n"; }
	CPtak(string nazwa_, double waga_, int speed_) :CZwierze(nazwa_, waga_), speed(speed_) { cout << "konstruktor argumentowy3\n"; }
	~CPtak() { cout << "destruktor3\n"; }
	void zjedz() { cout << "ssak" << nazwa << "je\n"; }
};

class CNietoperz : public CPtak, public CSsak {

public:
	int & speed() { return CSsak::speed; }
	CNietoperz() :CPtak(),CSsak(){ cout << "konstruktor bezarg cnietoperz\n"; }
	CNietoperz(string nazwa_, double waga_, int speed_) :CPtak(nazwa_, waga_,speed_),CSsak(nazwa_, waga_, speed_){ cout << "konstruktor argumentowy4\n"; }
	~CNietoperz() { cout << "destruktor4"; }
	
	void zjedz(){
		cout << "nietoperz" << CPtak::nazwa << "je\n";
	}
	
	
};
