#pragma once 

class CBudynek
{
	int rok;
	double wys;
	char* nazwa;
public:
	CBudynek(): rok(1887), wys(324.2) , nazwa(new char[strlen("Eiffla")+1])
	{
		strcpy(nazwa, "Eiffla");
		std::cout << "konstruktor bezargumentowy"<<std::endl;
	}
	CBudynek(const char* name, double height) :rok(2018), wys(height), nazwa(new char[strlen(name) + 1]) 
	{
		strcpy(nazwa, name);
		std::cout << "konstruktor dwuargumentowy" << std::endl;
	}
	CBudynek(int year, const char* name, double height) : rok(year), wys(height), nazwa(new char[strlen(name) + 1])
	{
		strcpy(nazwa, name);
		std::cout << "konstruktor trojargumentowy" << std::endl;
	}
	CBudynek(const CBudynek & building);
	void wypisz();
};