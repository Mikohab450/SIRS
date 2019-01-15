#include"CZwierze.h"


int main() {
	{
		CSsak ssak1;
		CPtak ptak1;
		CNietoperz nietop1;
		CSsak ssak2("wieloryb", 2137, 420);
		CPtak ptak2("wrobelek", 14, 88);
		CNietoperz nietop2("gacek", 69, 666);
		ssak1.zjedz();
		ptak1.zjedz();
		nietop1.CPtak:: zjedz();
		ssak2.zjedz();
		ptak2.zjedz();
		nietop2.CPtak:: zjedz();
	}
	cout << sizeof(CNietoperz) << endl << sizeof(CPtak) << endl << sizeof(CZwierze);
	return 0;
}

/*
1a) uzyc operatora zasiegu 
b) stworzyc osobna metode w cnietoperz
2.a) w kolejnosci klas, z ktorych dziedziczy Cnietoperz, destruktory w odwrotnej(zwierze-ptak-zwierze-ssak-nietoperz
nietoperz:128				//none
ptak64
zwierze56
////
nietoperz:152	both
ptak64
zwierze56
///
nietoperz:144		//virtual cssak/cptak
ptak64
zwierze56
//
*/