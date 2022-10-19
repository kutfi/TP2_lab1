#pragma once
#include "Vus.h"

class Teacher : public VUS
{
	int** groups;
	int gr_size;
	int s_size;
	char** subjects;

public:


	Teacher();
	~Teacher();

	void setGrSize(int n);
	void setSSize(int n);
	int getGrSize();
	int getSSize();

	void addSubject();
	void editSubject(int n);
	void delSubject(int n);
	void addGroup();
	void editGroup(int n);
	void delGroup(int n);

	void printValues() override;
	void Edit() override;

};