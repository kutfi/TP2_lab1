#define _CRT_SECURE_NO_WARNINGS
#include "myscanf.h"
#include "stdio.h"

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


