#include "stdio.h"
#include "Keeper.h"
#include "myscanf.h"
#include "student.h"
#include "teacher.h"
#include "staff.h"
void menu_commands()
{
	printf("menu");
	printf("\t-1_exit\n");
	printf("\t0__print to console\n");

	printf("\n\t2__save\n");
	printf("\t3__load\n");
	
	printf("\n\t11__add record\n");
	printf("\t12__edit record\n");
	printf("\t13__delete record\n");

	printf("\t__\n");


}

void print_menu_commands()
{

	printf("\t-1_exit\n");
	printf("\t0__print all\n");

	printf("\t1__print teachers\n");
	printf("\t2__print students\n");
	printf("\t3__print staff members\n");
}

	Keeper record;


int print_menu()
{
	int c = 0;
	print_menu_commands();
	while (true)
	{
		printf("print menu\n");
		take(&c);
		switch (c)
		{
		case -1:
			return 0;
			break;
		case 10:
			print_menu_commands();
			break;

		case 0:
			record.printAll();
			break;

		case 1:
			record.printTeachers();
			break;

		case 2:
			record.printStudents();
			break;

		case 3:
			record.printStaff();
			break;

		default:
			printf("unknown command, to see command list enter 10\n");
			break;
		}

	}
	return 0;
}

void add_menu_commands()
{
	printf("\t-1_exit\n");

	printf("\t1__add teacher\n");
	printf("\t2__add student\n");
	printf("\t3__add staff member\n");
}

int add_menu()
{
	int c = 0;
	add_menu_commands();
	while (true)
	{
		printf("add menu\n");
		take(&c);
		switch (c)
		{
		case -1:
			return 0;
			break;

		case 10:
			add_menu_commands();
			break;

		case 1:
		case 2:
		case 3:
			record.Add(c);
			break;

		default:
			printf("unknown command, to see command list enter 10\n");
			break;
		}

	}
	return 0;
}


void edit_menu_commands()
{
	printf("\t-1_exit\n");
	printf("\t1__enter id\n");
}

int edit_menu()
{
	int c = 0;
	edit_menu_commands();


	while (true)
	{
		printf("edit menu\n");
		take(&c);
		switch (c)
		{
		case -1:
			return 0;
			break;

		case 10:
			edit_menu_commands();
			break;

		case 1:
		{
			if (record.getNum() == 0)
			{
				printf("no records added\n");
				break;
			}
			int id = -1;
			while (id < 0 || id > record.getNum())
				take(&id);
			record.Edit(id);

		}
			break;


		default:
			printf("unknown command, to see command list enter 10\n");
			break;
		}

	}
	return 0;
}




int menu()
{
	printf("NUMERATION OF ITEMS BEGINS FROM 0\n");
	int c = 0;
	while (true)
	{
		menu_commands();
		take(&c);
		switch (c)
		{
		case 10:
			menu_commands();
			break;

		case -1:
			return 0;
			break;

		case 0:
			print_menu();
			break;

		case 11:
			add_menu();
			break;

		case 12:
			if (record.getNum() == 0)
				printf("no records found\n");
			else
				edit_menu();
			break;

		case 13:
			if (record.getNum() == 0)
				printf("no records found\n");
			else
			record.Delete();
			break;

		case 2:
			if (record.getNum() == 0)
				printf("no records found\n");
			else
			record.saveToFile();
			break; 

		case 3:
			record.loadFromFile();
		break;


		default:
			printf("unknown command, to see command list enter 10\n");
			break;
		}

	}
	return 0;
}


int main()
{
	menu();
	return 0;
}