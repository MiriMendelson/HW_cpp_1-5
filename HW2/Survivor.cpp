#include <iostream>
#include <cstring>
#include <array>
#include <iterator>

using namespace std;
#include "tribe.h"
#include "Survivor.h"

int Survivor::counter = 0;

void cleanBufferSurviver()
{
	int c;
	do
	{
		c = getchar();
	} while (c != EOF && c != '\n');
}

char* Survivor::getName() {
	return name;
}

Survivor::Survivor(const Tribe& tribe) : myTribe(&tribe), bandana(tribe.getBandana()) {
	cout << "*) please enter\x1b[1m name\x1b[0m of survivur: ";
	cleanBufferSurviver();
	char name1[20];
	cin >> name1;
	setName(name1);
	cout << "*) please enter\x1b[1m age\x1b[0m of surviver : ";
	cleanBufferSurviver();
	cin >> age;
	//Riesing the static variable and set it as ID
	ID = ++counter;
}
void  Survivor::print() {
	cout << "name: " << name << " age: " << age << "\n";
}