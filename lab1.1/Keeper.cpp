#define _CRT_SECURE_NO_WARNINGS
#include"Keeper.h"
#include "myscanf.h"
#include "string.h"

Keeper::Keeper() {
	printf("\n\tKeeper()\n");
	num = 0;
	list = nullptr;
	setFileName((char*)"database.txt");
}

Keeper::~Keeper(){ 
	printf("\n\t~Keeper()\n");
	for (int i = 0; i < num; i++)
		delete list[i];
}


void Keeper::Add(int t){ 

	VUS* add = nullptr;
	switch (t)
	{
	case 1:
		add = new Teacher;
		break;
	case 2:
		add = new Student;
		break;
	case 3:
		add = new Staff;
		break;
	}

	num += 1;

	 VUS** tmp = new VUS * [num];

	for (int i = 0; i < num-1; i++)
	{
		tmp[i] = list[i];
	}

	list = tmp;
	list[num - 1] = add;
	printf("\n\added\n");
}

int Keeper::getNum() {
	return num;
}

void Keeper::Edit(int i){ 
	if (i < 0 || i >= num)
		printf("error: id out of range\n");
	else
	{
		try {
			list[i]->Edit();
		}
		catch (...)
		{
			printf("error\n");
		}
	}
}

void Keeper::Delete(){ 
	int id = -1;
	printf("%d records found\nenter number of record to delete (0 -- %d)\n", num, num-1);
	while (id < 0 || id >= num)
	{
		take(&id);
	}

	delete list[id];
	
	for (int i = id; i< num-1; i++)
	{
		list[i] = list[i+1];
	}
	num--;
	printf("\n\trecord was deleted\n\n");
}




void Keeper::printAll(){ 
	for (int i = 0; i < num; i++)
	{
		printf("\trecord -- %d\n", i);
		list[i]->printValues();
		printf("\n");
	}
}

void Keeper::printTeachers() {
	printf("Teachers:\n");
	for (int i = 0; i < num; i++)
	{
		if (list[i]->getType() == TEACHER)
			list[i]->printValues();
		printf("\n");
	}
}

void Keeper::printStudents() {
	printf("Students:\n");
	for (int i = 0; i < num; i++)
	{
		if (list[i]->getType() == STUDENT)
			list[i]->printValues();
		printf("\n");
	}
}

void Keeper::printStaff() {
	printf("Staff:\n");
	for (int i = 0; i < num; i++)
	{
		if (list[i]->getType() == STAFF)
			list[i]->printValues();
		printf("\n");
	}
}

void Keeper::setFileName(char* n)
{
	strcpy(fileName, n);
}


char* Keeper::getFileName()
{
	return fileName;
}


int Keeper::changeFileName()
{
	int c = 0;
	while (c == 0)
	{
		printf("\t-1_exit\n");

		printf("\t0__edit name\n");
		printf("\t2__see name\n");
		take(&c);
		switch(c)
		{
			default:
				printf("unknown command\n");
				break;
		case -1:
				return 0;
		case 1:
		{
			printf("enter new file name\n");
			char s[200];
			try {
				take_s(s, 200);
			}
			catch (char* m)
			{
				throw m;
			}
			setFileName(s);
			printf("\n\tedited\n");
		}
		case 2:
			printf("filename is %s\n", getFileName());
			break;

		}
	}
}


void Keeper::saveToFile() {

	FILE* fp = fopen(getFileName(), "a");
	if (fp == NULL)
	{
		printf("file not found\n");
		return;
	}
	fprintf(fp, "N = %d\n", getNum());
	for (int i = 0; i < getNum(); i++)
	{
		list[i]->printF(fp);
	}

	fclose(fp);
};

void Keeper::loadFromFile(){ 
	FILE* fp = fopen(getFileName(), "r");
	if (fp == NULL)
	{
		printf("file not found\n");
		return;
	}

	int size = 0;
	

	if (fscanf(fp, "N = %d\n", &size) != 1)
		throw (char*)"exeption: data coppupted, possible data loss\n";
	if (size <= 0)
		throw (char*)"exeption: data coppupted, possible data loss\n";
	VUS** tmpList = new VUS * [size];
	int type = -1;
	VUS* add;
	for (int i = 0; i < size; i++)
	{
		if (fscanf(fp, "%d\n", &type) != 1)
			throw (char*)"exeption: data coppupted, possible data loss\n";

		switch (type)
		{
		case TEACHER:
			try { add = new Teacher; } catch (char* m) { throw m; } break;

		case STUDENT:
			try { add = new Student; } catch (char* m) { throw m; } break;

		case STAFF:
			try { add = new Staff; } catch (char* m) { throw m; } break;

		default:
			throw (char*)"exeption: data coppupted, possible data loss\n";
		}
		add->scanF(fp);
		tmpList[i] = add;
	}


	VUS** newList = new VUS * [size + getNum()];

	for (int i = 0; i < getNum(); i++)
		newList[i] = list[i];

	for (int i = 0; i < size; i++)
		newList[i + getNum()] = tmpList[i];
	

	list = newList;
	num = getNum() + size;
	fclose(fp);
}