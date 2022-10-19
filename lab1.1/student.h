#include "Vus.h"

class Student : public VUS
{
	int group;
	char spec[200];
	int year;
	int grade;

public:

	Student();
	~Student();
	void setGroup(int g);
	void setYear(int y);
	void setGrade(int g);
	void setSpec(char*);

	int getGroup();
	int getYear();
	int getGrade();
	char* getSpec();
	void printValues() override;
};