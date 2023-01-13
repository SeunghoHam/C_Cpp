#include "Animal.h"
#include"main_header.h"

int main()
{
	Animal* animal = new Animal(2, "닭");
	animal->printInfo();

	foo();
	return 0;
}


void foo() // main_header에서 선언된 foo 함수의 몸체를 main.cpp 에서 만든다.
{
	printf("Hello World");
}