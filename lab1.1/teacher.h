#include "Vus.h"

class Teacher : public VUS
{
	int** groups;
	int gr_size;
	char** subjects;
	int sbj_size;

public:


	Teacher();
	~Teacher();

	void setGrSize(int n);
	void setSbjSize(int n);
	void addSubject(char* add);
	void delSubject(int n);
	void addGroup(int g);
	void delGroup(int n);

	void printValues() override;

};