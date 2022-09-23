#define _CRT_SECURE_NO_WARNINGS

#include<cstdio>
#include<cmath>
#include<cstdlib>
#include<ctime>
#include<cstring>


int main()
{
	/*
	char myString[100];

	fseek(stdin, 0, SEEK_END);
	scanf("%99[^/n]s", myString); // 99[^/n] : 99개의 문자열을 받고 줄 바꿈 문자열은 받지 않는다.

	//strcpy(myString, "Hello World");
	printf(myString);
	*/

	// strcpy 예제코드 ( 값 복사)
	/*
	char inputString[100];

	printf("문자열 : " );
	fseek(stdin, 0, SEEK_END);
	scanf("%99[^/n]s", inputString);


	char duplicatedString[100];
	strcpy(duplicatedString, inputString); // (받을 파라미터, 줄 파라미터 )
	printf("입력된 문자열은 %s .", duplicatedString);
	*/

	// strcmp 예제코드 
	/*
	char str1[100];
	char str2[100];
	strcpy(str1, "HelloA");
	strcpy(str2, "HelloB");

	str1[0] ='a';
	str1[1] = 'b';
	str1[2] = 'c';
	str1[3] = '\0'; // : null값. 마지막에 0(null)을 넣어줘야 그 이후로 쓰레기값이 안나오고 제대로된 값만으로 끝낼 수 있다.
	//if(str1 == str2) // str1,2 는 주소값이기 때문에 값이 같더라도 str1,2 의 값은 절대로 같을 수 없다
	//if(strcmp(str1,str2) == 0) // 문자열의 값이 같은지 비교하기 위해서는 strcmp를 사용하여 사전적 비교를 해야함

	int result = strcmp(str1, str2); // strcpm = 사전적 비교 ( -1 , 1 ) 같다면 0

	printf("%d", result);
	*/

	// 과제형 연습 프로그래밍
	// 문자열을 입력받아 해당 문자열을 거꾸로 출력하는 프로그램 (cstring에 존재하는 함수 쓰지 말고)
	char str1[100]; // 입력받을 문자열
	char str2[100]; // 역방향 문자열

	int _arrSize = 0;
	fseek(stdin, 0, SEEK_END);
	scanf("%99[^\n]s", str1); // 입력 받을때만 99[^\n]s
	printf("입력한 문자열은 : %s ", str1);

	for (int i = 0; ; i++)
	{
		//_arrSize += 1;
		//printf("arrSize : %d\n ", _arrSize);

		if (str1[i] == '\0')
		{
			_arrSize = i;
			printf("_arrSize : %d", _arrSize);
			printf("브레이크\n");
			break;
		}
	}

	for (int i = 0; i < _arrSize; i++)
	{
		str2[(_arrSize - i)-1] = str1[i]; // _arrSize = 4 이기 때문에 -1 시켜줌 [0~3]
	}


	str2[_arrSize] = '\0';
	printf("\n역방향 문자열은 : %s", str2);
	return 0;
}  