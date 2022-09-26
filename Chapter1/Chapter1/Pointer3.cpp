#include "Header.h"

struct Marine
{
	int hp = 40;
	int atk = 6;
};

void foo(int* a, int count) // 파라미터의 포인터
{
	for (int i = 0; i < count; i++)
	{
		printf("%d\n", a[i]);
	}
}

void goo(const char* str) // 파라미터의 포인터
{
	// 하드코딩된 string변수 "value" 는 const. 상수변수로 받아와야한다.
	printf("%s", str);
}

int main()
{
#pragma region  변수 초기화
	//int* pointer = 0;
	int* pointer = nullptr; // c, c++ 에서의 표준 = nullptr

	pointer = (int*)malloc(sizeof(int));
	//printf("%d,", pointer);

	free(pointer);
	pointer = nullptr;
#pragma endregion


#pragma region  배열 초기화
	// Type v[10] ={0.};
	// Type v[10] = {nullptr,};
	int myArray[10] = {0,};

	for (int i = 0; i < 10; i++)
	{
		//printf("myArray[%d] = %d\n", i, myArray[i]);
	}

#pragma endregion

#pragma region 구조체 초기화


	//Marine* marine = nullptr;
	//Marine* marine_arr[40] = {nullptr,  }; // 포인터의 배열을 null 포인터로 초기화

	Marine* marine[40] = { nullptr, };
	for (int i = 0; i < 40; i++)
	{
		marine[i] = (Marine*)malloc(sizeof(Marine));
		marine[i]->hp = 40;
		marine[i]->atk = 7;
	
}
	for (int i = 0; i < 40; i++)
	{
		//printf(" marine[%d].atk = %d\n", i,marine[i]->atk);

	}

#pragma endregion

#pragma region 포인터의 포인터
	// 이중포인터에서
	// 기본형 데이터 타입이라면 : 2차원 배열일 가능성 높음
	// 구조체 타입이라면 : 포인터의 배열일 가능성 높음

	// int** v // int의 2차원 동적배열일 가능성 높음
	// Type** v // Type* 의 1차원 동적배열일 가능성 높음

	Marine* pMarine[20]; // 아래의 이중포인터와 같은 의미
	Marine** ppMarine; // 주소값의 주소값
	ppMarine = (Marine**)malloc(sizeof(Marine*) * 20); // 포인터는 항상 4byte
	// malloc 주소의 실제값을 힙 영역(사라지지않는) 에 실제로 만들어준다.
	for (int i = 0; i < 20; i++)
	{
		ppMarine[i] = (Marine*)malloc(sizeof(Marine));
		ppMarine[i]->atk = 8;
	}

	for (int i = 0; i < 20; i++)
	{
		//printf("marine[%d]->atk = %d\n", i, ppMarine[i]->atk);
	}

	free(pMarine);
	free(ppMarine);
#pragma endregion

#pragma region  파라미터의 포인터
	// 변수의 주소값을 받기 위함일 수 있지만, 배열변수를 받기 위함일 수도 있다
	// int foo(int* v, int size); 배열일 가능성 높음
	// int goo(int* v) // 한개의 값만을 필요할 가능성 높음

	//int myparamArray[5] = { 4,6,10,20,100 };
	//foo(myparamArray, 5);

	//goo("HelloWorld");
#pragma endregion

	printf("냐ㅗㅇㅇ;");
	return 0;
}
