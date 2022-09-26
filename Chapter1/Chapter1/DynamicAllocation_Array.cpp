#include"Header.h"

int main()
{
	/*
	int* myArray;
	int input;
	fseek(stdin, 0, SEEK_END);
	printf("숫자를 입력하면 배열 생성  : ");
	scanf("%d", &input);

	myArray = (int*)malloc(sizeof(int) * input); // 동적배열 할당
	// 리턴은 포인터 타입으로 나오기 때문에 (int*)로 형변환 해준다.

	for (int i = 0; i < input; i++)
	{
		myArray[i] = i * 10;
	}
	for (int i = 0; i < input; i++)
	{ 
		printf("myArray[%d] = %d\n", i, myArray[i]);
	}*/

	// 사용자한테 숫자를 입력받아 배열의 동적할당을 활용해 입력받은 숫자 만큼의 크기를 갖는 배열을 만들고
	// 해당 배열에 2,4,6,8 로 증가하는 수열을 저장한 뒤, 배열을 출력하라

	int* myArray; // 입력받은 숫자 만큼의 크기를 갖는 배열 : 포인터 ≒ 배열 . int* myArray ≒ int myArray[(int)]
	int input; // 입력받을 수. 

	printf("입력받을 수 : ");
	fseek(stdin, 0, SEEK_END);
	scanf_s("%d", &input);

	myArray = (int*)malloc(sizeof(int) * input); // (int*) 가 없다면 void* 형식의 값이 된다.
	
	for (int i = 0; i < input; i++)
	{
		// 배열에 수열 저장
		myArray[i] = (i+1) * 2;
	}
	for (int i = 0; i < input; i++)
	{
		printf("myArray[%d] = %d\n", i, myArray[i]);
	}

	free(myArray);
	return 0;
}