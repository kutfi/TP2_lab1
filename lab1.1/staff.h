#include "Vus.h"

class Staff : public VUS
{
	char title[200];
	char phone[15];
	char resp[200];

public:

	Staff();
	~Staff();
	void setTitle(char*);
	void setResp(char*);
	void setPhone(char*);

	char* getTitle();
	char* getResp();
	char* getPhone();

	void printValues() override;

};