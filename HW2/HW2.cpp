#pragma warning (disable: 4996)
#include <iostream>
#include "Survivor.h"
#include "Tribe.h"
using namespace std;
// שב מספר 5 בהם יוצרים 2 שבטים להם הוספנו
// רפרנס לבנדנה ולכל שורד קישור לשבט שלו  
// "lena" ושורדת בשם"miri" בהמשך נמחק שורדת בשם 
//לכן חשוב להוסיף שורדות בשמות הללו כדי לא להעיף התוכנית  <--
void cleanBuffer()
{
	int c;
	do
	{
		c = getchar();
	} while (c != EOF && c != '\n');
}

Tribe& ceatTribe() {
	Tribe* t;
	int clanSize;
	char name[20];
	char color[10];
	cout << "whats the new tribes name? ";
	cin >> name;
	cout << "what is the clans size? ";
	cin >> clanSize;
	cout << "what is the clans bandanas color? ";
	cin >> color;
	Bandana newBandana(color,30.3);
	t = new  Tribe(newBandana, name, clanSize);
	for (int i = 0; i < clanSize; i++) {
		cout << "--> adding surviver number " << i+1 << " to "<< name <<"'s tribe:\n";
		t->addSurviver();
	}
	return *t;
}

int main()
{
	Tribe t1 = ceatTribe();
	Tribe t2 = ceatTribe();
	cleanBuffer();
	t1.PrintAllSurvivers();
	t2.PrintAllSurvivers();

	char miri[5] = "miri";
	t1.DismissalSurviver(miri);

	char lena[5] = "lena";
	t2.DismissalSurviver(lena);

	cout << "!!! removing \"miri\" and \"lena\" !!!\n";
	t1.PrintAllSurvivers();
	t2.PrintAllSurvivers();
}