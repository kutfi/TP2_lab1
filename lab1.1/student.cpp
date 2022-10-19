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
	printf("\n\tStudent()\n");
}

Student::~Student()
{
	printf("\n\t~Student()\n");
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
	printf("student:\t");
	printName();
	
	printf("group: %d, year: %d, grade %d\nspecialty: %s\n", getGroup(), getYear(), getGrade(), getSpec());

}

void Student::Edit()
{
	printValues();

	int c = 0;
	while (c == 0)
	{
		printValues();
		printf("\t-1_exit\n");

		printf("\t0__edit name\n");
		printf("\t1__edit group\n");
		printf("\t2__edit year\n");
		printf("\t3__edit grade\n");
		printf("\t4__edit specialty\n");
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
		{
			int new_group = 0;
			printf("enter new group value\n");
			take(&new_group);
			setGroup(new_group);
			printf("\n\tedited\n");
		}
			c = 0;	break;

		case 2:
		{
			int new_year = 0;
			printf("enter new year value\n");
			take(&new_year);
			setYear(new_year);
			printf("\n\tedited\n");
		}
			c = 0;	break;

		case 3:
		{
			int new_grade = 0;
			printf("enter new grade value\n");
			take(&new_grade);
			setGrade(new_grade);
			printf("\n\tedited\n");
		}	
			c = 0;	break;

		case 4:
		{
			
			printf("enter new specialty value\n");
			char s[200];
			try {
				take_s(s, 200);
			}
			catch (char* m)
			{
				throw m;
			}
			setSpec(s);
			printf("\n\tedited\n");
		}
			c = 0;	break;


		default:
			printf("unknown command\n");
			c = 0;	break;
		}

	}

}