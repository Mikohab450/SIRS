
#include"SIR.h"
#include<cstdlib>

bool sick(double propability)
{
	double p;
	p = (double)rand() / RAND_MAX;
	if (p < propability)
		return true;
	else
		return false;
}
infected & infected::operator--() {
	t--;
	return *this;
}
resistable & resistable::operator--() {
	t--;
	return *this;
}
void resistable::dec() {
	t--;
}
void infected::dec() {
	t--;
}