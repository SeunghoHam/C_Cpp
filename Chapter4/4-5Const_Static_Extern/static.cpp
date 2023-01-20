#define _CRT_SECURE_NO_WARNINGS

#include<cstdio>
#include"static.h"


int MyClass::static_member_int = 1; // 정적 멤버변수의 몸체 만들기

int main()
{
	MyClass::static_member_int = 100;
	printf("%d", MyClass::static_member_int); 
	// unresolved external symbol = static 변수의 몸체가 없음
	/*
	MyClass* c = new MyClass();
	c->foo();
	MyClass::goo();*/
	return 0;
}


void MyClass::foo()
{

}

void MyClass::goo() // 함수의 몸체에는 static 선언이 필요없다.
{

}