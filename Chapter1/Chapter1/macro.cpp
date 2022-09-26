#include"Header.h"
#define SWAP(X,Y,T) T = X; X =Y; Y=T; // 규칙에 맞게 소스코드를 교체(몸체가 없다)

// 매크로를 두 줄로 사용하기 위해서는 \ 으로 줄바꿈 ( \ 뒤에는 공복이 없어야함)
#define LineChange(A,B)\
 A+B;\
A-B;

#define P(X,Y) X##Y 

#define PI 3.141592
#define EXCUTE_NUM 1 // 전처리 매크로를 활용하여
#if EXCUTE_NUM == 0
int main()
{
	printf("HelloWorld 0");
	return 0;
}
#else 
int main()
{
	int v1 = 100;
	int v2 = 200;
	int temp;

	// #define매크로(전처리) 함수를 호출하면
	// 실행이 컴퓨터 연산에 의해 일어나는 것이 아닌, 아예 소스코드가 바뀌어버리게 된다.
	SWAP(v1, v2, temp);
	temp = v1; v1 = v2; v2 = temp;
	printf("v1 = %d\n", v1);
	printf("v2 = %d\n", v2);

	P(print, f("HelloWorld\n"));

	float pie = PI;
	
	return 0;
}
#endif