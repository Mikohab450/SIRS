#include<iostream>
#include"CBudynek.h"
CBudynek::CBudynek(const char* _nazwa, const double _wys) : wys(_wys) {
	nazwa = new char[strlen(_nazwa) + 1];
	strcpy(nazwa, _nazwa);
	wys = _wys;
}

CBudynek::CBudynek(const CBudynek & o) : wys(o.wys) {
	nazwa = new char[strlen(o.nazwa) + 1];
	strcpy(nazwa, o.nazwa);
	wys = o.wys;
}

bool CBudynek::operator==(const CBudynek& o) const{
	return wys == o.wys&& !strcmp(nazwa,o.nazwa);
}
bool CBudynek::operator!=(const CBudynek& o) const {
	return wys != o.wys || strcmp(nazwa, o.nazwa);
}
bool CBudynek::operator>(const CBudynek& o) const {
	return wys > o.wys;
}
CBudynek & CBudynek::operator=(const CBudynek &o) {
	if (this == &o)
		return *this;
	delete[] nazwa;
	nazwa = new char[strlen(o.nazwa) + 1];
	strcpy(nazwa, o.nazwa);
	wys = o.wys;
	return *this;
}

CBudynek & CBudynek::operator=(CBudynek &&o) {
	char* tmp = nazwa;
	nazwa = o.nazwa;
	o.nazwa = tmp;
	wys = o.wys;
	return *this;
}

CBudynek & CBudynek::operator+=(double v)
{
	wys += v;
	return *this;
}
CBudynek &CBudynek::operator++()
{
	wys++;
	return *this;
}
CBudynek CBudynek::operator++(int)
{
	CBudynek temp = (*this);
	wys ++;
	return temp;
}

CBudynek::operator double() {
	return wys;
}
char CBudynek::operator[](int v)const {
	if (v < strlen(nazwa))
		return nazwa[v];
	else
		return '-';
}