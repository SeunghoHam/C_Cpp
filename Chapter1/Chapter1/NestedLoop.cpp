#include<stdio.h>

int main()
{
	// break; continue;
	int _inputValue;
	fseek(stdin, 0, SEEK_END);
	scanf_s("%d",&_inputValue);

	for (int i = 0; i < _inputValue; i++)
	{
		for (int k = 0; k < _inputValue- i; k++)
		{
			printf(" ");
		}
		for (int l = _inputValue - i - 1; l < _inputValue; l++)
		{
			printf("*");
		}
		printf("\n");
	}
	return 0;
}