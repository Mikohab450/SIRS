#include"CKruszec.h"


int main() {
	CKruszec zloto(12, 13), platyna(15, 12);
	cout<<"\n"<<zloto.return_price();
	cout<< "\n" << zloto.return_dens();
	CProstopadloscian kruszec1(zloto,3,4,5,"nazwa1");
	CProstopadloscian kruszec2(platyna, 8, 4, 9, "nazwa2");
	kruszec1.info();
	CWalec walec(platyna, 10, 5, "platyna");
	walec.info();
	return 0;
}