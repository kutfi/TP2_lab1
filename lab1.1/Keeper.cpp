#include"Keeper.h"

Keeper::Keeper() {
	num = 0;
	list = nullptr;
}

Keeper::~Keeper(){ 

}

void Keeper::Add(VUS* add){ 

	num += 1;

	 VUS** tmp = new VUS * [num];

	for (int i = 0; i < num-1; i++)
	{
		tmp[i] = new VUS;
		tmp[i] = list[i];
	}

	list = tmp;
	list[num - 1] = add;

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