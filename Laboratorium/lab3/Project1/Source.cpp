#include"CMeble.h"

using namespace std;

int main()
{
	CMeble m1("kanapa", 20, 30, 40), m2(m1),m3(move(m1)),m4=m1;
	CMeble *m5 = new CMeble(m1);
	cout << m4 << endl  ;
	
	return 0;
}
