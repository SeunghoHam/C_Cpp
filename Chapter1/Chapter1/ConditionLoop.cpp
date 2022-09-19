#include<stdio.h>

int GetInput();
int main()
{
	int _valueInput1;
	int _valueInput2;
	int _valueOperation;
	printf("Input 1의 값을 입력하세요 : ");
	_valueInput1 = GetInput();
	printf("\nInput 2의 값을 입력하세요 : ");
	_valueInput2 = GetInput();

	printf("\nOperation 의 값을 입력하세요 : ");
	_valueOperation = GetInput();

	if (_valueOperation == 0) // 더하기
	{
		printf("\n\nOperation =  0, 더하기 입니다.\n");
		int returnvalue = _valueInput1 + _valueInput2;
		printf("결과는 %d", returnvalue);
		printf("입니다");
	}
	else if (_valueOperation == 1) // 빼기
	{
		printf("\n\nOperation =  1, 빼기 입니다.\n");
		int returnvalue = _valueInput1 - _valueInput2;

		printf("결과는 %d",returnvalue);
		printf("입니다");
	}
	else if (_valueOperation == 2) // 거듭제곱
	{
		printf("\n\nOperation =  2, 거듭제곱 입니다.\n");
		
		int _destinationValue = 1;
		for (int i = 0; i < _valueInput2; i++)
		{
			_destinationValue *= _valueInput1;
		}
		printf("결과는 % d", _destinationValue);
		printf("입니다");
	}
	else // 오류구문
	{
		printf("오류가 발생하였습니다");
	}


	return 0;
}

//fseek(stdin, 0, SEEK_END);// scanf를 사용하기 전 호출해줘야 하는 구문 ( 입력값이 잘 못 들어오는것을 방지해준다. )

int GetInput()
{
	int _inputValue;
	fseek(stdin, 0, SEEK_END);
	scanf_s("%d", &_inputValue);
	return _inputValue;
}