#pragma once
#include<iostream>
class CMeble {
	char* nazwa;
	double wys;
	double szer; 
	double dl;
public:
	CMeble(const char* name, double h, double wid, double len);
	CMeble(const CMeble & m);
	CMeble(CMeble && m);
	~CMeble();
	CMeble& operator=(const CMeble &m);
	friend std::ostream& operator<<(std::ostream &s, const CMeble&ob);
};

class CKrzesla :public CMeble {
private:
	int n;
public:
	CKrzesla(const char* nm, double wys, double szer, double dl,int num);
	CKrzesla(const CKrzesla & k);
	CKrzesla(CKrzesla && k);
	virtual ~CKrzesla();
	CKrzesla & operator=(const CKrzesla &k);
	friend std::ostream& operator<<(std::ostream &s, const CKrzesla&ob);
};
class CTaborety :public CKrzesla {
private:
	int legs;
public:
	CTaborety(const char* nm, double wys, double szer, double dl, int num,int lgs);
	CTaborety(const CTaborety & k);
	CTaborety(CTaborety && k);
	virtual ~CTaborety();
	CTaborety & operator=(const CTaborety &k);
	friend std::ostream& operator<<(std::ostream &s, const CTaborety &ob);
};