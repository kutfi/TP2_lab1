#define _CRT_SECURE_NO_WARNINGS

#include "myscanf.h"
#include "teacher.h"
#include "string.h"

Teacher::Teacher() {
	printf("teacher constructor\n");
	setType(TEACHER);
	setSbjSize(0);
	setGrSize(0);
	subjects = nullptr;
	groups = nullptr;
}

Teacher::~Teacher() {
	printf("teacher destructor\n");
}

void Teacher::setSbjSize(int n) {
	sbj_size = n;
}

void Teacher::setGrSize(int n) {
	gr_size = n;
}

void Teacher::addSubject(char* add) {
	sbj_size++;
	char** newArr = new char* [sbj_size];
	for (int i = 0; i < sbj_size - 1; i++)
	{
		newArr[i] = new char[strlen(subjects[i])];
		strcpy(newArr[i], subjects[i]);
	}
	newArr[sbj_size - 1] = new char[strlen(subjects[sbj_size - 1])];
	strcpy(newArr[sbj_size - 1], subjects[sbj_size - 1]);
	subjects = newArr;

}

void Teacher::delSubject(int n) {
	delete subjects[n];
	sbj_size--;
	for (int i = n; i < sbj_size; i++)
	{
		subjects[i] = subjects[i + 1];
	}

}

void Teacher::addGroup(int g) {
	gr_size++;
	int** newArr= new int* [gr_size];
	for (int i = 0; i < gr_size - 1; i++)
	{
		newArr[i] = new int;
		newArr[i] = groups[i];
	}
	newArr[gr_size - 1] = new int(g);

	groups = newArr;
}


void Teacher::delGroup(int n) {
	delete groups[n];
	gr_size--;
	for (int i = n; i < gr_size; i++)
	{
		groups[i] = groups[i + 1];
	}

}

void Teacher::printValues()
{
	printName();
	printf("subjects:\n");
	for (int i = 0; i < sbj_size; i++)
	{
		printf("%s\n", subjects[i]);
	}

	printf("groups:\n");
	for (int i = 0; i < gr_size; i++)
	{
		printf("%d\n", groups[i]);
	}

}