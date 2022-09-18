#include<stdio.h>


int sum(int a, int b);


int main()
{
	int _number = -512;

	printf("%d ÀÔ´Ï´Ù\n",_number);
	
	int input;
	int input2;


	scanf_s("%d", &input);
	scanf_s("%d", &input2);

	printf("%d",sum(input, input2));

	return 0;

}


int sum(int a,int b)
{
	return a + b;
}