#define _CRT_SECURE_NO_WARNINGS
#include<cstdio>
#include<cstdlib>
#include<ctime>
#include<cmath>

int GetInt(int* _intPointer);

char GetChar(char* _charPointer);

int main()
{
	int inputValue1;
	int inputValue2;
	char inputOper;
	int result;

	int* p_value1= &inputValue1;
	int* p_value2 = &inputValue2;
	char* p_Oper = &inputOper;

	GetInt(p_value1);
	GetInt(p_value2);
	GetChar(p_Oper);

	switch (inputOper)
	{
	case '+':
		result = *p_value1 + *p_value2; // 주소값의 내부값을 더해야 하니까
		printf("%d + %d 의 값은 : %d", inputValue1, inputValue2, result);
		break;
	case '-' :
		break;
	case '*': 
		break;
	case '/':
		break;
	default:
	
		printf("연산자가 잘못되었다");
		break;
	}




	return 0;
}

int GetInt(int* _intPointer)
{
	fseek(stdin, 0, SEEK_END);
	scanf("%d", _intPointer);
	return *_intPointer;
}

char GetChar(char* _charPointer)
{
	fseek(stdin, 0, SEEK_END);
	scanf("%c", _charPointer);
	return *_charPointer;
}