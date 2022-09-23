#include<cstdio>

int main()
{
	int v[5] = { 0,1,2,3,4 };
	int index = 2;
	//v[index++] = 10;
	v[++index] = 10;
	for (int i = 0; i < 5; i++)
	{
		printf("%d, ", v[i]); // 0, 1, 10 , 3, 4
		// 0, 1, 2, 10, 4
	}
	return 0;
}