#include <iostream>
#include <cstring>
#include "Tribe.h"
#include "Survivor.h"
#include <array>
#include <iterator>
using namespace std;

Tribe::Tribe(const Bandana& bandana, char* name, int max) :tribsBandana(bandana)
{
	MaxSurvivers = max;
	ReminedSurvivers = 0;
	Survivors = new Survivor * [max];
	strcpy_s(tribeName, name);
}

Tribe::Tribe(const Tribe& trubeToCopy) :tribsBandana(trubeToCopy.getBandana())
{
	MaxSurvivers = trubeToCopy.MaxSurvivers;
	ReminedSurvivers = trubeToCopy.ReminedSurvivers;
	strcpy_s(tribeName, trubeToCopy.tribeName);
	int size = trubeToCopy.MaxSurvivers;
	Survivors = new Survivor * [size];
	Survivors = trubeToCopy.Survivors;
}

void Tribe::addSurviver()
{
	if (ReminedSurvivers == MaxSurvivers)
		return;
	Survivors[ReminedSurvivers] = new Survivor(*this);
	ReminedSurvivers++;
}

void Tribe::DismissalSurviver(char* name) {
	for (size_t i = 0; i < ReminedSurvivers; i++)
	{
		if (strcmp(Survivors[i]->getName(), name) == 0)
		{
			size_t j = i;
			delete Survivors[i];
			ReminedSurvivers--;
			for (; j < ReminedSurvivers; j++) {
				Survivors[j] = Survivors[j + 1];
			}
		}
	}
}
void Tribe::PrintAllSurvivers() const
{
	cout << "printing \"" << tribeName << "s'\"  survivers: \n------------ \n";
	for (int i = 0; i < ReminedSurvivers; i++) {
		Tribe::Survivors[i]->print();
	}
	cout << "------------ \n\n";
}

Tribe::~Tribe()
{
	for (int i = 0; i < ReminedSurvivers; i++)
		delete Survivors[i];
	delete[] Survivors;
}
