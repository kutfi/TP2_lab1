
#define _CRT_SECURE_NO_WARNINGS

#include "myscanf.h"

#include "staff.h"
#include "stdio.h"
#include "string.h"


Staff::Staff()
{
	
	setType(STAFF);
	setTitle((char*)"unknown");
	setResp((char*)"unknown");
	setPhone((char*)"unknown");
	printf("\n\tStaff()\n");
}

Staff::~Staff()
{
	printf("\n\t~Staff()\n");
}

void Staff::setTitle(char* t) {
	trimToFormat(t); strcpy(title, t);
}
void Staff::setResp(char* r) {
	trimToFormat(r); strcpy(resp, r);
}

void Staff::setPhone(char* p) {
	trimToFormat(p); strcpy(phone, p);
}


char* Staff::getTitle() { return title; }
char* Staff::getResp(){ return resp; }
char* Staff::getPhone(){ return phone; }

void Staff::printValues()
{
	printf("staff member:\t");
	printName();
	printf("job title: %s, responsibility: %s\nphone number: %s\n", getTitle(), getResp(), getPhone());
}

void Staff::printF(FILE* f)
{
	fprintf(f, "%d\n", getType());
	fprintf(f, "%s\n", getName());
	fprintf(f, "%s\n", getTitle());
	fprintf(f, "%s\n", getResp());
	fprintf(f, "%s\n", getPhone());
}
void Staff::scanF(FILE* f)
{
	char s[200] = { 0 };
	setType(STAFF);
	fgets(s, 200, f); setName(s);
	fgets(s, 200, f); setTitle(s);
	fgets(s, 200, f); setResp(s);
	fgets(s, 200, f); setPhone(s);
}




void Staff::Edit()
{
	printValues();

	int c = 0;
	while (c == 0)
	{
		printValues();
		printf("\t-1_exit\n");

		printf("\t0__edit name\n");
		printf("\t1__edit job title\n");
		printf("\t2__edit phone number\n");

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
			printf("enter new job title\n");
			char s[200];
			try {
				take_s(s, 200);
			}
			catch (char* m)
			{
				throw m;
			}
			setTitle(s);
			printf("\n\tedited\n");
		}
		c = 0;	break;

		case 2:
		{
			printf("enter new phone number\n");
			char s[200];
			try {
				take_s(s, 200);
			}
			catch (char* m)
			{
				throw m;
			}
			setPhone(s);
			printf("\n\tedited\n");
		}
		c = 0;	break;


		default:
			printf("unknown command\n");
			c = 0;	break;
		}

	}

}