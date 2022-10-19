#pragma once
#include "stdio.h"
#define NONE 0
#define TEACHER 1
#define STUDENT 2

#define STAFF 3

class VUS
{
	int type;
	char name[200];
	
protected: 
	void printName();
	
public:
	VUS();
	~VUS();
	void setType(int t);
	int getType();
	void setName(char*);
	char* getName();
	virtual void printValues() {};
	virtual void Edit() {};
	

};