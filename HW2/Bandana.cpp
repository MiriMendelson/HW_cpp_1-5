#include <string.h>
#include <iostream>
using namespace std;
#include "Bandana.h"

Bandana::Bandana(const char* c, double length): length(length)
{
	strcpy_s(this->color, c);
}
Bandana::~Bandana() {};
void Bandana::print() const
{
	cout << "color of andana: " << color << ", " <<"and it's length:" << length;
}
