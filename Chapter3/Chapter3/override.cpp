#include<stdio.h>
#include<cstring>
#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable:4996)
// 오버라이드 정의 : 
// 부모클래스의 함수의 정의를 자식클래스에서 새로 덮어쓰는 것
// 함수명, 파라미터까지 모두 같은 함수를 만들어내는 것
class Animal
{
public:
	int legs;
	char* name;

	Animal(int legs, const char* name)
	{
		this->legs = legs;
		name = new char[strlen(name) + 1];
		 strcpy(this->name, name);
	}
	// virtual : 오버라이딩할 때, 부모클래스의 함수에서
	// 키워드를 추가하면 정상적으로 오버라이드된 함수를 찾아가서 실행한다.
	// virtual 키워드를 추가할
	virtual void printInfo() 
	{
		printf("다리 : %d, 이름 : %s\n", legs, name);
	}
	// 소멸자에서의 virtual 키워드를 넣지 않으면,
	// 상속받은 클래스의 경우 현재 타입에 맞는 소멸자를 호출하게 된다.
	// -> 메모리 누수로 이어짐
	virtual ~Animal()
	{
		printf("Animal 소멸자 호출\n");
		delete[] name;
	}
};

class Human : public Animal
{

	char regist_num[40];
public:
	Human(const char* _resist_num) : Animal(2, "사람")
	{
		strcpy(this->regist_num, _resist_num);
	}
	void printInfo() 
	{
		printf("이름 : %s, 주민등록번호 : %s\n", name, this->regist_num);
	}

	~Human()
	{
		printf("Human 소멸자 호출\n");
	}
};

// 3차원 행렬 Matrix 선언.
// Matrix의 정적 클래스 인스턴스의 행렬합을 구하는 연산자 오버로딩 함수 구현


class Matrix
{
public:
	float x;
	float y;
	float z;
	Matrix(float _x, float _y, float _z)
	{
		this->x = _x;
		this->y = _y;
		this->z = _z;
	}

	void printInfo()
	{
		printf("x : %.2f, y : %.2f, z : %.2f\n", x, y, z);
	}
};

Matrix operator+(Matrix & _mat1, Matrix& _mat2)
{
	return Matrix(_mat1.x + _mat2.x, _mat1.y + _mat2.y, _mat1.z + _mat2.z);
}
int main()
{
	Human* human = new Human("1234-5678");
	Animal* animal = new Animal(2, "닭");

	animal = (Animal*)human; // human을 
	animal->printInfo();
	delete animal;
	// Matrix
	/*
	Matrix mat1 = Matrix(4, 4, 4);
	Matrix mat2 = Matrix(10, 12, 14);

	Matrix sumMat = mat1 + mat2;
	sumMat.printInfo();*/
	return 0;
}