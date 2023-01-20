#include<cstdio>
#include<cstring>
#include<string.h>
#define _CRT_SECURE_NO_WARNINGS


// const - 상수
// 상수 : 프로그램이 시작되면서 끝날때까지 절대 변하지 않는 값.

// cosnt는 define매크로이며, const 키워드를 이용해 만든 변수는
// 상수이지만 '저장공간' 을 갖고 있는 변수이며 실직적으로 프로그램 내부에 박혀있는 값이다.

class Person
{
public :
	const int age; // 변수 형태의 공간을 가지고 있는 상수
	// define 상수 : 프로그램상 박혀있음
	// 상수 직접 할당 : 프로그램상 박혀있음
	// enum 상수 : 프로그램상 박혀있음
	// const 키워드 변수 : 변수의 공간을 가지고 있다.

	// 클래스 내부에서의 const 멤버
	/*
	* 클래스 멤버를 const 멤버로 선언하면, 실제 변수로서 저장공간을 갖고 있다는 것을 알 수 있다.
	* const로 선언된 클래스 멤버 변수는 선언과 동시에 초기화 하거나, 생성자에서 초기화를 해줘야한다.
	* 생성자에서 초기화할때는 "변수이름(초기값) "  같은 식으로 초기화를 한다.
	*/

	//Person() : age(100) {} // 절대 변하지 않는 프로그램상에 박혀있는 100(age)라는 수가 가변적인 상수가 될 수있다.
					
	Person(int n) : age(n) {} // 가변적인 상수 age 
	// 생성자에서 n 이라는 값을 받아서 age 에 할당한다. 
	
};

#define MYVALUE 100
int main()
{	
	//  변수   상수
	const int value = MYVALUE; // const : 변수 값이 다른 값으로 바뀌는 것을 보호해준다.
	//printf("%d", value);

	// 클래스 내부 const 변수 가져오기
	//Person* p = new Person();
	//printf("%d", p->age);
	

	
	/*
	int input;
	fseek(stdin, 0, SEEK_END);
	scanf_s("%d", &input);

	Person* person = new Person(input);
	printf("Person : age값 : %d", person->age);
	*/

	const char* str;
	char* myStr = new char[100];
	//strcpy(myStr, "HelloWorld");
	//str = myStr;

	//printf("\n%s", str);
	return 0;
	// 05 : 55
}