#include "stdio.h"
#include "Vus.h"

class Keeper
{
	int num;
	VUS** list;

public:

	void Add();
	void Edit();
	void Delete();
	void printAll();
	void saveToFile();
	void loadFromFile();

};