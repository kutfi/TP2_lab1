
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
	printf("staff constructor\n");
}

Staff::~Staff()
{
	printf("staff destructor\n");
}

void Staff::setTitle(char* t) {
	strcpy(title, t);
}
void Staff::setResp(char* r) {
	strcpy(resp, r);
}

void Staff::setPhone(char* p) {
	strcpy(phone, p);
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

void Staff::Edit()
{
	printValues();

}