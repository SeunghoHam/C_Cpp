#ifndef __ANIMAL_H__
#define __ANIMAL_H__

#include "main_header.h"
class Animal
{
public:
	int legs;
	char name[50];

	Animal(int legs, const char* name)
	{
		this->legs = legs;
		strcpy_s(this->name, name);
	}
	void printInfo()
	{
		printf("�̸� : %s, �ٸ� : %d\n", name, legs);
	}
};

#endif