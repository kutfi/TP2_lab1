#include "stdio.h"

#define STUDENT 1
#define TEACHER 2
#define STAFF 3

class VUS
{
	int type;
	char name[200];

public:

	void setType(int t);
	int getType();
	void setName(char*);
	char* getName();

	virtual void printValues() {};

};