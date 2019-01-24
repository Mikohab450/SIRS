#include"person.h"
#include"SIRS.h"
infected & infected::operator--() {
	time_left--;
	return *this;
}
resistable & resistable::operator--() {
	time_left--;
	return *this;
}

infected::infected(person* &p)
{
	time_left = p->get_time();
}
resistable::resistable(person* &p)
{
	time_left = p->get_time();
}