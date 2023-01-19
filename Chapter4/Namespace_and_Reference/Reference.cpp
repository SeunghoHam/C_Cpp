#define _CRT_SECURE_NO_WARNINGS
#include<cstdio>
#include<string>
#include<ctime>


// Reference 타입
/*
* 파라미터를 받을 때, 타입 오른쪽에 &(앰퍼샌드) 기호를 이용하게 되면, 파라미터를 레퍼런스 타입으로 받을 수 있게 된다.
* 값 복사를 막아주어 실행속도를 빠르게 할 수 있다는 장점이 있다.
*/

/**
* swap 함수에 대한 설명
* int& : 파라미터의 레퍼런스타입
* &가 붙어있으면 레퍼런스 타입, 변수를 그대로 가져온다.
*/
void swap(int& a, int& b) // 포인터를 이용해서 복사된 값이 아닌, 파라미터로 가져온 값들의 값이 변하게 된다.
{
	int temp;
	temp = a;
	a = b;
	b = temp;
}

//std::string 은 포인터가 아니라, 정적타입으로 소환되고 사용된다.
// 값을 그대로 가져오기 위해서 (자료형) 이 아니라 (자료형&) 식으로 해서 값 복사가 최소한으로 일어나게된다.
// 값 복사가 일어나지 않도록 레퍼런스를 넘긴다.

// 최적화 하려면 포인터 형식으로 받아서 주소값을 알아오거나, 레퍼런스를 받아와야한다.
void stingSwap(std::string& a, std::string& b)
{
	std::string temp;
	temp = a;
	a = b;
	b = temp;
}


class Vector 
{
public:
	float x;
	float y;
	Vector(float x, float y)
	{
		this->x = x;
		this->y = y;
	}
};

/*
* 연산자 오버로딩도 레퍼런스 타입으로 파라미터를 받는다.
* 연산자 오버로딩을 하기 위해서는 항상 정적 타입의 클래스만을 받아야한다.
* 
* 일반 Vector 형 파라미터로 받게되면 x,y 총 8byte의 값복사가 일어나게 된다.
* 
* 레퍼런스 타입으로 받게되면 그 변수가, 인스턴스가 그대로 전달되므로 시간 단축, 절약 하게된다.
*/
Vector operator+(Vector& v1, Vector& v2)
{
	return Vector(v1.x + v2.x, v1.y+v2.y);
}
int main()
{
	std::string svalue1 = "Hello";
	std::string svalue2 = "World";
	int value1 = 100;
	int value2 = 200;
	printf("스왑 전 %d, %d\n", value1, value2);
	swap(value1, value2);

	printf("스왑 후 %d, %d", value1, value2);

	float start = clock();
	for (int i = 0; i < 100000; i++)
	{
		stingSwap(svalue1, svalue2);
		
	}
	float end = clock();

	float time = (end -  start)/ CLOCKS_PER_SEC;
	printf("경과시간 : %f\n", time);

	// 값 복사가 일어날 때는  0.445초 소모
	// 레퍼런스 타입으로 하면 0.178초 소모

	/*
	stingSwap(svalue1, svalue2);
	printf("svalue1 = %s, svalue2 = %s\n", svalue1.c_str(), svalue2.c_str());
	*/
}