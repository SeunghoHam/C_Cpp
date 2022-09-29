#include<iostream>
#include<cstdio>
#include<cstring>
#define _CRT_SECURE_NO_WARNINGS
struct Person
{
	// 속성
	int age;
	float salary;
	int gender;
	char name[100];

	// 행동
	void work();
	void off();

	// 속성과 행동을 나누는 것 : 추상화(Abstraction)
};
struct ProtossUnit
{
	int shieldAmount = 0;
	int shieldRegen = 0;
	int shieldArmmor = 0;
	int hp = 0;
};

// 수학적인 명제 및, 다형성의 원리에 의해 (자식클래스)→(부모클래스) 이런 화살표 방향을 이용한다. 
struct Zealot : ProtossUnit
{
	Zealot()
	{
		hp = 80;
		shieldAmount = 60;
	}
};


struct Dragon : ProtossUnit
{
	Dragon()
	{
		hp = 100;
		shieldAmount = 80;
	}
};

class Student
{
public:
	int student_num;
	char* name;
	int gender;


	// 생성자를 만들면 선언만으로는 클래스를 활용할 수 없게된다.
	Student(int student_num, const char* n, int g) 
	{
		this->student_num = student_num; // this = 클래스의 변수를 의미한다.
		// 자기자신의 인스턴스(포인터타입)을 가져올 수 있다.
		name = new char[strlen(n) + 1]; // strlen : 문자열의 길이를 나타낸다.(null문자 제외)
		// null문자를 포함한 길이를 가져오기 위해서 + 1
		strcpy(name, n);
		gender = g;

	}

	~Student() // 소멸자 : 파라미터를 받지 않는다
	{
		printf("%s 의 소멸자 호출", name);
		delete[] name;
		
	}
};

int main()
{
	//Zealot* zealot;
	//ProtossUnit* protossUnit;

	//zealot = (Zealot*)protossUnit; //질럿으로 형변환 시켜줘야함
	//protossUnit = zealot; //


	Student s = Student(1234, "홍길동", 0); // 함수가 끝나게 되면 정보가 사라진다. ( 소멸자 자동호출 )
	//s.student_num = 1234;
	//strcpy(s.name, "홍길동");
	//s.gender = 0;

	Student* ps = new Student(3456,"여자홍길동", 1);
	// new 키워드를 이용하여 클래스를 할당하면, 함수의 실제 값이 Heap 영역에 저장된다. 함수의 실행주기(라이프사이클)과 관계없이 유지된다.
	//ps->student_num = 3456;
	//strcpy(ps->name, "여자홍길동");
	//ps->gender = 1;

	delete ps; // new 키워드를 사용하여 클래스 인스턴스를 만들었다면, delete 키워드를 사용해서 인스턴스의 실제 값을 Heap 메모리에서 삭제해줘야 한다.
	return 0;
}

