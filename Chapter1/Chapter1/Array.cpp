#include<stdio.h>

int main()
{
	//int _length= 5;
	int _Array1[5][5]; // 1 2 3 4
	int _Array2[5][5]; // 2 4 6 8
	int _Array3[5][5]; // 1 + 2 한 값

	for (int i = 0; i < 5; i++)
	{
		for (int k = 0; k < 5; k++)
		{
			_Array1[i][k] = (i*5) + k+1;

			_Array2[i][k] = ((i * 5) + k + 1) * 2;
			
			_Array3[i][k] = _Array1[i][k] + _Array2[i][k];
		}
	}



	printf("Array1의 값\n");
	for (int i = 0; i < 5; i++)
	{
		for (int k  = 0; k < 5; k++)
		{
			printf(" %d ", _Array1[i][k]);
		}
		printf("\n");
	}
	printf("\n\nArray2의 값\n");
	for (int i = 0; i < 5; i++)
	{
		for (int k = 0; k < 5; k++)
		{
			printf(" %d ", _Array2[i][k]);
		}
		printf("\n");
	}
	printf("\n\nArray3의 값\n");
	for (int i = 0; i < 5; i++)
	{
		for (int k = 0; k < 5; k++)
		{
			printf(" %d ", _Array3[i][k]);
		}
		printf("\n");
	}


	return 0;
}