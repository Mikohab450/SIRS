#include"CMeble.h"

using namespace std;


CMeble::CMeble(const char* name, double h, double wid, double len):wys(h),szer(wid),dl(len) {
	cout <<endl<< "wywolano konstruktor wieloargumentowy";
	nazwa = new char[strlen(name) + 1];
	strcpy(nazwa, name);
};
CMeble::CMeble(const CMeble & m):wys(m.wys),szer(m.szer),dl(m.dl)
{
	cout <<endl<< "wywolano konstruktor kopiujacy";
	nazwa = new char[strlen(m.nazwa) + 1];
	strcpy(nazwa, m.nazwa);
};
CMeble::CMeble(CMeble && m):wys(m.wys),szer(m.szer),dl(m.dl)
{
	cout << endl << "wywolano konstruktor przenoszacy";
	nazwa = new char[strlen(m.nazwa) + 1];
	strcpy(nazwa, m.nazwa);
	m.nazwa = nullptr;
};
CMeble::~CMeble() {

	delete[]nazwa;
};
CMeble& CMeble::operator=(const CMeble &m)
{
	if (this == &m)
	{
		return*this;
	}
	cout <<endl<< "wywolano operator przypisania";
	nazwa = new char[strlen(m.nazwa)+1];
	strcpy(nazwa, m.nazwa);
	wys = m.wys;
	dl = m.dl;
	szer = m.szer;
	return *this;
};
ostream& operator<<(std::ostream &s, const CMeble&ob) {
	s << endl << ob.wys << endl << ob.dl << endl << ob.szer;
	return s;
}

CKrzesla::CKrzesla(const char* name, double h, double wid, double len,int num) :CMeble(name,h,wid,len),n(num) {
	cout << endl << "wywolano konstruktor wieloargumentowy";
};
CKrzesla::CKrzesla(const CKrzesla & k):CMeble(k),n(k.n)
{
	cout << endl << "wywolano konstruktor kopiujacy";
	
};
CKrzesla::CKrzesla(CKrzesla && k) :CMeble(move(k)),n(k.n){
	cout << endl << "wywolano konstruktor przenoszacy";

};
CKrzesla::~CKrzesla() {

};
CKrzesla& CKrzesla::operator=(const CKrzesla &k)
{
	if (this == &k)
	{
		return*this;
	}
	cout << endl << "wywolano operator przypisania";
	CMeble::operator=(k);
	n = k.n;
	return *this;
};
ostream& operator<<(std::ostream &s, const CKrzesla&ob) {
	s << *dynamic_cast<const CMeble*>(&ob) << ob.n;
	return s;
}
CTaborety::CTaborety(const char* name, double h, double wid, double len, int num,int lgs) : CKrzesla(name, h, wid, len,num), legs(lgs) {
	cout << endl << "wywolano konstruktor wieloargumentowy";
};
CTaborety::CTaborety(const CTaborety & k) : CKrzesla(k), legs(k.legs)
{
	cout << endl << "wywolano konstruktor kopiujacy";

};
CTaborety::CTaborety(CTaborety && k) : CKrzesla(move(k)), legs(k.legs) {
	cout << endl << "wywolano konstruktor przenoszacy";

};
CTaborety::~CTaborety() {

};
CTaborety& CTaborety::operator=(const CTaborety &k)
{
	if (this == &k)
	{
		return*this;
	}
	cout << endl << "wywolano operator przypisania";
	CKrzesla::operator=(k);
	legs= k.legs;
	return *this;
};
ostream& operator<<(std::ostream &s, const CTaborety&ob) {
	s << *dynamic_cast<const CKrzesla*>(&ob) << ob.legs;
	return s;
}