#define _CRT_SECURE_NO_WARNINGS

#include "myscanf.h"
#include "teacher.h"
#include "string.h"

Teacher::Teacher() {
	printf("\n\tTeacher()\n");
	setType(TEACHER);
	
	setSSize(0);

	setGrSize(0);
	subjects = nullptr;
	groups = nullptr;
}

Teacher::~Teacher() {
	printf("\n\t~Teacher()\n");
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

void Teacher::printF(FILE* f)
{
	fprintf(f, "%d\n", getType());
	fprintf(f, "%s\n", getName());
	fprintf(f, "%d\n", getSSize());
	for (int i = 0; i < s_size; i++)
		fprintf(f, "%s\n", subjects[i]);
	

	fprintf(f, "%d\n", getGrSize());

	for (int i = 0; i < gr_size; i++)
		fprintf(f, "%d\n", *groups[i]);
	

}

void Teacher::scanF(FILE* f)
{
	setType(TEACHER);
	char s[200] = { 0 };
	fgets(s, 200, f); setName(s);
	int i = 0;
	fscanf(f, "%d\n", &i); setSSize(i);
	for (int id = 0; id < s_size; id++)
	{
		trimToFormat(s);
		fgets(s, 200, f); 
		strcpy(subjects[id], s);
	}

	fscanf(f, "%d\n", &i); setGrSize(i);

	for (int id = 0; id < gr_size; id++)
	{
		fscanf(f, "%d\n", &i); 
		*groups[id] = i;
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

		printf("\t0__edit name\n");
		printf("\t1__edit subjects\n");
		printf("\t2__add subject\n");
		printf("\t3__delete subject\n");
		printf("\t4__edit groups\n");
		printf("\t5__add group\n");
		printf("\t6__delete group\n");
		take(&c);
		switch (c)
		{
		case -1:
			c = -1;
			break;
		case 0:
			try {
				editName();
			}
			catch (char* m)
			{
				throw m;
			}
			printf("\n\tedited\n");
			c = 0; break;
		case 1:
			if (s_size == 0)
				printf("no subjects found\n");
			else
			{
				int i = -1;
				printf("enter id of subject to edit\n");
				while (i < 0 || i > getSSize())
					take(&i);
				try {
					editSubject(i);
				}
				catch (char* m)
				{
					throw m;
				}
				printf("\n\tedited\n");
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
				printf("\n\deleted\n");
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
				printf("\n\tedited\n");
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
				printf("\n\deleted\n");
			}
			c = 0;	break;

		default:
			printf("unknown command\n");
			c = 0;	break;
		}

	}

}