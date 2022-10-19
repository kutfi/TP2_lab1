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

int menu()
{

	Keeper record;

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
			record.printAll();
			break;

		case 11:
			record.Add();
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