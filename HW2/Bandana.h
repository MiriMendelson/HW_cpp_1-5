#ifndef __BANDANA_H
#define __BANDANA_H
class Bandana
{
public:
	Bandana(const char* c, double length);
	~Bandana();
	char color[20];
	double length;
	void print() const;
};
#endif

