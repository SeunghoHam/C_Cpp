#include<cstdio>


void swap(int a, int b);
void p_swap(int* a, int* b);
void ref_swap(int& a, int& b);
int main()
{
	int v1 = 100;
	int v2 = 200;

	int temp; // 임시변수

	//swap(v1, v2); 
	// 이렇게 하면 스왑이 될 것 같지만 안된다.
	// 매개변수(파라미터)로 함수에 들어가지면서 새로운 변수 취급을 받는다. 전역변수 v1와 swap의 매개변수 a 는 다른 변수이다.

	printf("a : %d\n, b : %d\n", v1, v2);
	//p_swap(&v1, &v2);
	ref_swap(v1, v2);
	printf("a : %d\n, b : %d", v1, v2);

}
void swap(int a, int b)
{
	int temp;
	temp = a;
	a = b;
	b = temp;
}
void ref_swap(int& a, int& b) // int 의 레퍼런스 타입  (변수 그 자체를 가져온다)
{	
	int temp;
	temp = a;
	a = b;
	b = temp;
}
void p_swap(int* a, int* b)
{
	int temp;
	temp = *a;
	*a = *b;
	*b = temp;
}