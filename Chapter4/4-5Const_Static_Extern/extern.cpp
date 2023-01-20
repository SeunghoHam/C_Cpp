

// extern 키워드 : '외부에 존재한다' 라는 뜻
// C/C++ 에서 obj 파일로 링크가 되면서 만들어지는 진정한 전역변수를 만들어 줄 수 있는 키워드
// extern의 활용과 뜻은 많지만, '전역변수를 만들어준다' 라는 것으로 이해하면 편하다

// 프로그램 전체에서의 static

/*
* 
*/

#include"extern.h"
int main()
{
	// myValue 의 초기값 = 100;
	// extern_sub 에 정의된 add(myValue++) 를 한다.
	// 결과가 101이 나와야하는데 100 이 됨.
	// 하지만 안됨
	/*
		클래스 외부의 static 변수 및 함수의 특징 : 각각의 cpp 파일마다 다르게 작용한다.
		그래서 extern 키워드를 사용한다.
	*/
	add();

	printf("%d", myValue);
	return 0;
}