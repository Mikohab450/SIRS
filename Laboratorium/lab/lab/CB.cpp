#include<iostream>
#include"CB.h"

CBudynek::CBudynek(const CBudynek & building):rok(building.rok), wys(building.wys), nazwa(new char[strlen(building.nazwa) + 1])
{
	strcpy(nazwa, building.nazwa);
	std::cout << "konstruktor kopiujacy";

}
void CBudynek::wypisz()
{
	std::cout << rok << std::endl << wys << std::endl << nazwa << std::endl;
}