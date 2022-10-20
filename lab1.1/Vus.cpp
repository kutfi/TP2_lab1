#define _CRT_SECURE_NO_WARNINGS
#include "Vus.h"
#include "string.h"
#include "myscanf.h"

VUS::VUS() {
	printf("\n\tvus()\n");
	setType(NONE);
	setName((char*)"unknown");

}

VUS::~VUS() {
	printf("\n\t~vus()\n");
}


void VUS::printName()
{
	printf("name: %s\n", name);
}
void VUS::setType(int t) {
	type = t;
}

void VUS::setName(char* n) {
	trimToFormat(n); strcpy(name, n);
}

int VUS::getType() {
	return type;
}

char* VUS::getName() {
	return name;
}


void VUS::editName() {

	char new_val[200];
	printf("enter new value for name:\n");
	if (take_s(new_val, 200) == -1)
		throw (char*)"input error, tile too long";
	setName(new_val);
}

