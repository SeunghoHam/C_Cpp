#include "Animal.h"
#include"main_header.h"

int main()
{
	Animal* animal = new Animal(2, "��");
	animal->printInfo();

	foo();
	return 0;
}


void foo() // main_header���� ����� foo �Լ��� ��ü�� main.cpp ���� �����.
{
	printf("Hello World");
}