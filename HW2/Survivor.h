#ifndef __SURVIVOR_H
#define __SURVIVOR_H
#include "Bandana.h"
class Tribe;

class Survivor
{
public:
	Survivor(const Tribe& tribe);
	char* getName();
	void setName(char* n) { strcpy_s(this->name, n); }
	void print();

private:
	char name[20];
	char age[3];
	const Tribe* myTribe;
	Bandana bandana;
	int ID;
	static int counter;
};
#endif