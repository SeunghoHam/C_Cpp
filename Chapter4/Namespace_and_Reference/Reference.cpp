#include<cstdio>
#include<string>



// Reference 타입
/*
* 파라미터를 받을 때, 타입 오른쪽에 &(앰퍼샌드) 기호를 이용하게 되면, 파라미터를 레퍼런스 타입으로 받을 수 있게 된다.
* 값 복사를 막아주어 실행속도를 빠르게 할 수 있다는 장점이 있다.
*/

void swap(int* a, int* b) // 포인터를 이용해서 복사된 값이 아닌, 파라미터로 가져온 값들의 값이 변하게 된다.
{
	int temp;
	temp = *a;
	*a = *b;
	*b = temp;
}
int main()
{
	// 19 : 45 부터
}