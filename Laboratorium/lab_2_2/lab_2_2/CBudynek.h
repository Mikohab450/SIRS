#pragma once
class CBudynek
{
	char* nazwa;
	double wys;

	public:
		CBudynek(const char*_nazwa, const double _wys);
		CBudynek(const CBudynek & o);
		bool operator==(const CBudynek & o) const;
		bool operator!=(const CBudynek & o) const;
		bool operator>(const CBudynek & o) const;
		CBudynek &operator=(const CBudynek & o);
		CBudynek &operator=(CBudynek && o);
		CBudynek &operator+=(double v);
		CBudynek& operator++();
		CBudynek operator++(int);
		operator double();
		char operator[](int v) const ;

};