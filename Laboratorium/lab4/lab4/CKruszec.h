#pragma once
#include<iostream>
using namespace std;
class CKruszec {
private:
	double price;
	double dens;
public:
	CKruszec() :price(0), dens(0) { cout << "\nkonstruktor bezargumntowy"; }
	CKruszec(double price_, double dens_) :price(price_), dens(dens_) { cout << "\nkonstruktor dwuargumentowy"; }
	virtual ~CKruszec() { cout << "\ndestruktor CKruszec"; };
	void change_price(double price_) {
		price = price_;
	}
	void change_dens(double dens_) {
		dens = dens_;
	}
	double return_price()const {
		return price;
	}
	double return_dens() const{
		return dens;
	}
};

class CSztabka :public CKruszec
{
public:
	
	virtual double o() = 0;
	double return_weight() {
		return (return_dens()*o());
	}
	double Return_price_of_bar()
	{
		return (return_price()*return_weight());
	}
	void info() {
		cout << "\nvol" << o() << "\nweight" << return_weight() << "\nprice" << Return_price_of_bar()<<endl;
	}


};

class CProstopadloscian : public CSztabka {
private:
	double edge1, edge2, edge3;
	string name;
public:
	CProstopadloscian(const CKruszec &kruszec, double edge1_, double edge2_, double edge3_, string n) :edge1(edge1_), edge2(edge2_), edge3(edge3_), name(n)
	{
		cout << "\nkonstruktor 5-argumentowy";
		change_dens(kruszec.return_dens());
		change_price(kruszec.return_price());
	}
	~CProstopadloscian() { cout << "\ndestruktor CProstopadloscian"; };
	double o() {
		return(edge1*edge2*edge3);
	}

};

class CWalec :public CSztabka {
private:
		double wys;
		double promien;
		string name;
public:
	CWalec(const CKruszec &kruszec, double wys_, double promien_, string n) :wys(wys_), promien(promien_),name(n)
	{
		cout << "\nkonstruktor 4-argumentowy";
		change_dens(kruszec.return_dens());
		change_price(kruszec.return_price());
	}
	~CWalec() { cout << "\ndestruktor CWalec"; };
	double o() {
		return(3.14*promien*promien*wys);
	}

};