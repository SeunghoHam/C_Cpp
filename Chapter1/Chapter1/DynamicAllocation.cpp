// 메모리 동적 할당과 배열
#include "Header.h"

struct Marine
{
	int hp;
	int mp;
	char name[20];
};

Marine* foo() // Marine 이라는 구조체 포인터타입
{
	Marine m;
	m.hp = 100;
	m.mp = 50;
	strcpy(m.name, "Jim Raynor"); // 마린이라는 구조체에 이름 할당
	return &m; // 실제 주소값을 리턴
}

Marine* Allocfoo() // 메모리 동적할당 한 구조체 포인터타입
{

	Marine* m = (Marine*) malloc(sizeof(Marine));
	m->hp = 100; // -> 스코프 연산자 : 동적 할당된 구조체의 포인터 변수의 '멤버 변수' 에 접근하기 위하여 사용한다.
	m->mp = 50;
	strcpy(m->name, "Jim Raynor");
	return m; // 반환은 주소값을 리턴하지 않는다?
}
int main()
{
	/*
	int myArray[100]; 
	// 배열 인덱스를 집어넣어 값을 가져오는  [] 대괄호는
	// 해당 주소값에서 몇 번째 뒤쪽의 값을 가져오느냐 라는 의미를 가지고 있다.
	int* p_myArray = myArray;
	const char* myString = "HelloWorld"; // 메모리 동적할당
	// 배열이나 데이터를 컴퓨터의 메모리 중(힙) 영역에 자리시키는것.
	// 함수의 실행주기와 무관하게 프로그램 종료까지 살아남는 메모리 공간이다
	p_myArray[0] = 100;
	p_myArray[1] = 200;
	p_myArray[2] = 300;
	printf("%d\n", myArray[0]);
	printf("%d\n", myArray[1]);
	printf("%d\n", myArray[2]);
	*/


	Marine* m = foo(); // Marine 의 구조체 타입을 가져왔기에, 
	Marine* allocm = Allocfoo();
	//printf("%s", (*m).name); // foo() 의 할당값인 m의 값에 넣는다
	printf("%s", (*allocm).name);
	free(allocm);

	// free() : cstdlib 에 포함되어있다
	// 동적할당된 변수, 배열등을 해제해주는 함수

	// 이름 출력 안되는 이유 : 함수 실행이 끝나면, 함수 내부의 변수들의 값은 파괴된다.

	// ↑위와같은 사유로 인해 메모리를 동적 할당 해야한다 : malloc()
	// Type v = (Type*)malloc(sizeof(Type));
	return 0;
}