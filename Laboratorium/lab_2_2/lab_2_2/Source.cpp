#include<iostream>
#include"CBudynek.h"
using namespace std;
int main() {
	CBudynek ob0("dom", 205.6), ob1("ob", 205.6), ob2("ob", 205.6), ob3("ob3", 604.4), ob4("x", 0);
	if (ob1 == ob2) cout << "ob1==ob2\n";
	if (ob1 != ob0) cout << "ob1!=ob0\n";
	if (ob1 > ob2) cout << "ob1>ob2\n";
	ob0 = ob0;
	ob4 = ob2;
	ob0 = move(ob0);
	ob4 = move(ob0);
	ob4 += 50;
	CBudynek ob5 = ob4++;
	//ob5++ = ob4;

	return 0;
}