#include "stdio.h"
#include "Vus.h"

class Keeper
{
	int num;
	VUS** list;

public:
	Keeper();
	~Keeper();
	void Add();
	void Edit();
	void Delete();
	void printAll();
	void printStudents();
	void printTeachers();
	void printStaff();
	void saveToFile();
	void loadFromFile();

};