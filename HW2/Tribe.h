#ifndef __TRIBE_H
#define __TRIBE_H

#include "Survivor.h"
class Survivor;
class Tribe
{
private:
	Survivor** Survivors;
	char tribeName[20];
	int MaxSurvivers;
	int ReminedSurvivers;
	Bandana tribsBandana;

public:
	Tribe(const Bandana& bandana, char* name, int max);
	Tribe(const Tribe& trubeToCopy);
	~Tribe();
	void addSurviver();
	void DismissalSurviver(char* name);
	void PrintAllSurvivers() const;
	const Bandana& getBandana() const { return tribsBandana; }
};
#endif