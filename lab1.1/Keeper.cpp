#include"Keeper.h"
#include "myscanf.h"

Keeper::Keeper() {
	printf("\n\tKeeper()\n");
	num = 0;
	list = nullptr;
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

void Keeper::saveToFile(){ 

}

void Keeper::loadFromFile(){ 

}