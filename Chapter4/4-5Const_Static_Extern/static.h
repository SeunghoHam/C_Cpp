#define _CRT_SECURE_NO_WARNINGS
#include<cstdio>
#include<cstring>

// static : 정적
// static이 class 내부에 존재할 경우 :  class 내부에서 유일하고 독립적인 멤버라는 뜻
// class 외부에 존재할 경우 : obj파일 내부에서 유일하고 독립적인 존재 라는 뜻이 된다.

#define MYVALUE 100
class MyClass
{
public:
	// 멤버변수는 class 가 생성되면서 하나하나 선언이 되며 메모리 공간을 갖게 되지만
	// static 변수는 class 와 관계없이 일단 존재해야한다. ( 몸체를 만들어줘야함 )

	int a;
	static int b;
	static int static_member_int;

	void foo(); // dynamic 동적 함수
	/*
		a = 10;
		this->a = 200;
		printf("foo\n");
	*/
	static void goo(); // static 정적 함수
		/*
		// a = 100; //불가능하다
		// 클래스의 주체가 되는 인스턴스가 없다.
		// 주체가 없이도 실행이 되는 goo 함수이기때문에 a가 뭐인지 특정할 수가 없다.

		b = 100; // static 으로 선언된 변수에는 접근가능하다.
		printf("goo\n");*/
	

	// 동적 함수는 this 키워드가 존재할 수 있지만, 정적 함수는 this 키워드가 존재할 수 없다.
};