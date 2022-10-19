#include "stdio.h"
#include "Keeper.h"
#include "myscanf.h"

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
		printf("print menu");
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
		printf("add menu");
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
			record.Add(new Teacher);
			break;

		case 2:
			record.Add(new Student);
			break;

		case 3:
			record.Add(new Staff);
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

int add_menu()
{
	int c = 0;
	edit_menu_commands();
	while (true)
	{
		printf("add menu");
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
			record.Edit();
			break;

		case 13:
			record.Delete();
			break;

		case 2:
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