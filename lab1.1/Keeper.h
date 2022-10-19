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

public:
	Keeper();
	~Keeper();

	int getNum();
	void Add(VUS* add);
	void Edit(int);
	void Delete();
	void printAll();
	void printStudents();
	void printTeachers();
	void printStaff();
	void saveToFile();
	void loadFromFile();

};