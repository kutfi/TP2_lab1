#define _CRT_SECURE_NO_WARNINGS
#include "myscanf.h"
#include "stdio.h"

#include <crtdbg.h>
#include "stdlib.h"
#include "string.h"

int take(int* _x)
{
	while (true)
	{
		printf("input\t");
		if (scanf("%d", _x) != 1) printf("invalid type inputed, required type -- int\n");
		else
		{
			if (getchar());	return 1;
		}
		if (getchar());
	}
}


void myInvalidParamHandler(const wchar_t*, const wchar_t*, const wchar_t*, unsigned int, uintptr_t) {}

int take_s(char* s, int l)
{
	_CrtSetReportMode(_CRT_ASSERT, 0);
	_invalid_parameter_handler oldHandler = _set_invalid_parameter_handler(myInvalidParamHandler);
	if (gets_s(s, l) == nullptr)
	{
		_set_invalid_parameter_handler(oldHandler);
		return -1;
	}
	_set_invalid_parameter_handler(oldHandler);
	return 0;
}