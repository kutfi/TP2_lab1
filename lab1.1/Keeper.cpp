#include"Keeper.h"

Keeper::Keeper() {

}

Keeper::~Keeper(){ 

}

void Keeper::Add(){ 

}

void Keeper::Edit(){ 

}

void Keeper::Delete(){ 

}



void Keeper::printAll(){ 
	printTeachers();
	printStudents();
	printStaff();
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