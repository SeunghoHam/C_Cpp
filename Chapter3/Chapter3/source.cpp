#include<iostream>
#include<cstdlib>

/*
int main()
{
	int v2[5] = { 1,2,3,4,5 };
	int* pv2 = v2;
	printf("%d", *(pv2 + 1)); // pv2 + 1 = +(타입의 바이트 만큼 더하기) 에 의해서 v2[0] + 1  = v2[1] 이 된다.
	// 결과 : 2
	// 포인터 주소 자체에 덧셈 뺄셈을 하게 되면 주소값의 현재타입만큼 이동하게 된다.
	return 0;
}*/

// 구조체 + 함수 = 클래스

struct Marine
{
	int hp;
	int mp;
};
int main()
{
	// [ C에서 malloc을 이용해서 메모리에 할당하던 방식 ]
	Marine* m = (Marine*)malloc(sizeof(Marine));
	free(m);


	// [ C++에서 new 키워드를 이용해서 메모리에 할당 ]
	Marine* m = new Marine;
	delete m;




	int* myArrray = (int*)malloc(sizeof(int)* 10); // 10 개의 배열을 만들고 싶다
	free(myArrray);

	int* myArray_cpp = new int[100];
	delete[] myArray_cpp;
	return 0;
}