#define _CRT_SECURE_NO_WARNINGS

#include "myscanf.h"
#include "student.h"
#include "stdio.h"
#include "string.h"


Student::Student()
{
	setType(STUDENT);
	setGroup(0);
	setYear(0);
	setGrade(0);
	setSpec((char*)"unknown");
	printf("student constructor\n");
}

Student::~Student()
{
	printf("student destructor\n");
}

void Student::setGroup(int g) {
	group = g;
}
void Student::setYear(int y) {
	year = y;
}
void Student::setGrade(int g) {
	grade = g;
}
void Student::setSpec(char* s) {
	strcpy(spec, s);
};

int Student::getGroup(){ return group;}
int Student::getYear(){ return year;}
int Student::getGrade(){ return grade;}
char* Student::getSpec(){ return spec;}


void Student::printValues()
{
	printName();
	
	printf("group: %d, year: %d, grade %d\nspecialty: %s\n", getGroup(), getYear(), getGrade(), getSpec());

}

void Student::Edit()
{
	printValues();
}