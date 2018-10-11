

#include<iostream>
#include"CB.h"

using namespace std;


int main()
{
	CBudynek ob1(2137, "Szkola" , 14.88 );
	CBudynek ob2(ob1);
	ob1.wypisz();
	ob2.wypisz();
	CBudynek* ob3=&ob1;
	(*ob3).wypisz();
	CBudynek* ob4 = new CBudynek(ob1);
	(*ob4).wypisz();
	return 0;
}