#define _CRT_SECURE_NO_WARNINGS
#include "Vus.h"
#include "string.h"

VUS::VUS() {
	setType(NONE);
	setName((char*)"unknown");

}

VUS::~VUS() {

}


void VUS::printName()
{
	printf("name: %s\n", name);
}
void VUS::setType(int t) {
	type = t;
}

void VUS::setName(char* n) {
	strcpy(name, n);
}

int VUS::getType() {
	return type;
}

char* VUS::getName() {
	return name;
}

