#pragma once
#include "stdio.h"
#include "Vus.h"
#include "student.h"
#include "teacher.h"
#include "staff.h"

class Keeper
{
	int num;
	VUS** list;

	char fileName[200];

public:
	Keeper();
	~Keeper();

	int getNum();
	char* getFileName();
	void setFileName(char*);
	int changeFileName();
	void Add(int);
	void Edit(int);
	void Delete();
	void printAll();
	void printStudents();
	void printTeachers();
	void printStaff();
	void saveToFile();
	void loadFromFile();

};