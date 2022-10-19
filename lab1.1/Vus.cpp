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
	strcmp(name, n);
}

int VUS::getType() {
	return type;
}

char* VUS::getName() {
	return name;
}

