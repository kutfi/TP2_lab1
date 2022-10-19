#define _CRT_SECURE_NO_WARNINGS

#include "myscanf.h"
#include "teacher.h"
#include "string.h"

Teacher::Teacher() {
	printf("teacher constructor\n");
	setType(TEACHER);
	
	setSSize(0);

	setGrSize(0);
	subjects = nullptr;
	groups = nullptr;
}

Teacher::~Teacher() {
	printf("teacher destructor\n");
}

void Teacher::setSSize(int n) {
	s_size = n;
}

void Teacher::setGrSize(int n) {
	gr_size = n;
}

void Teacher::addSubject() {

	char add[200];
	printf("enter new value for subject:\n");
	if (take_s(add, 200) == -1)
	{
		throw (char*)"input error, tile too long";
	}
	s_size++;
	int size = s_size;
	char** newArr = new char* [size];
	for (int i = 0; i < size - 1; i++)
	{
		newArr[i] = new char[strlen(subjects[i])];
		strcpy(newArr[i], subjects[i]);
	}
	newArr[size - 1] = new char[strlen(add)+1];
	strcpy(newArr[size - 1], add);
	subjects = newArr;
}

void Teacher::editSubject(int n) {
	char new_val[200];
	printf("enter new value for subject:\n");
	if (take_s(new_val, 200) == -1)
		throw (char*)"input error, tile too long";
	strcpy(subjects[n], new_val);
}

void Teacher::editGroup(int n) {
	int new_val = 0;
	printf("enter new value for group:\n");
	take(&new_val);
	groups[n] = &new_val;
}

void Teacher::delSubject(int n) {
	delete subjects[n];
	s_size--;
	for (int i = n; i < s_size; i++)
	{
		subjects[i] = subjects[i + 1];
	}
}

void Teacher::addGroup() {
	int g = 0;
	printf("enter new value for group:\n");
	take(&g);

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
	printf("teacher:\t");
	printName();
	printf("subjects:\n");
	for (int i = 0; i < s_size; i++)
	{
		printf("%s\n", subjects[i]);
	}

	printf("groups:\n");
	for (int i = 0; i < gr_size; i++)
	{
		printf("%d\n", *groups[i]);
	}

}

int Teacher::getGrSize() { return gr_size; }
int Teacher::getSSize() { return s_size; }

void Teacher::Edit()
{
	printValues();

		int c = 0;

		while (c == 0)
		{
			printValues();
			printf("\t-1_exit\n");

			printf("\t1__edit subjects\n");
			printf("\t2__add subject\n");
			printf("\t3__edit groups\n");
			printf("\t4__add group\n");
			take(&c);
			switch (c)
			{
			case -1:
				c = -1;
				break;

			case 1:
				if (s_size == 0)
					printf("no subjects found\n");
				else
				{
					int i = -1;
					printf("enter id of subject to edit\n");
					while (i < 0 || i > getSSize())
						take(&i);
					editSubject(i);
				}
				c = 0;	break;

			case 2:
				addSubject();
				c = 0;	break;

			case 3:
				if (s_size == 0)
					printf("no subjects found\n");
				else
				{
					int i = -1;
					printf("enter id of subject to delete\n");
					while (i < 0 || i > getSSize())
						take(&i);
					delSubject(i);
				}
				c = 0;	break;

			case 4:
				if (gr_size == 0)
					printf("no groups found\n");
				else
				{
					int i = -1;
					printf("enter id of group to edit\n");
					while (i < 0 || i > getGrSize())
						take(&i);
					editGroup(i);
				}
				c = 0;	break;

			case 5:
				addGroup();
				c = 0;	break;
				
			case 6:
				if (gr_size == 0)
					printf("no subjects found\n");
				else
				{
					int i = -1;
					printf("enter id of group to delete\n");
					while (i < 0 || i > getGrSize())
						take(&i);
					delGroup(i);
				}
				c = 0;	break;

			default:
				printf("unknown command\n");
				c = 0;	break;
			}

		}

}