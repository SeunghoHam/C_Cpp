#define _CRT_SECURE_NO_WARNINGS

#include<cstdio>
#include"static.h"


int MyClass::static_member_int = 1; // ���� ��������� ��ü �����

int main()
{
	MyClass::static_member_int = 100;
	printf("%d", MyClass::static_member_int); 
	// unresolved external symbol = static ������ ��ü�� ����
	/*
	MyClass* c = new MyClass();
	c->foo();
	MyClass::goo();*/
	return 0;
}


void MyClass::foo()
{

}

void MyClass::goo() // �Լ��� ��ü���� static ������ �ʿ����.
{

}