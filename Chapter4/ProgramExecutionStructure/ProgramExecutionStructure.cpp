// 함수 실행 구조에 대하여

// 프로그램의 실행 구조

// 프로그램은 실행될 때 Stack 과 Heap 메모리가 존재한다.
// Stack 영역에 존재하는 값들은 정적인 존재( 함수 콜 스택에 따라 정해진 생명을 갖는다 )
// Heap 영역에 존재하는 값들은 동적인 존재( 생명주기가 해제될 때까지 유지된다 )

// if 우리가 프로그램을 실행사면
/*
* 1. 바이트 배열로 만들어진 exe 파일이 RAM 메모리에 올라감.
* 2. OS에 의해서 Instructinos 에 실행코드가 만들어지게됨.
* 3. Stack에서 함수 콜스택을 관리한다. ( 정적 메모리 ) / ex) int a[10];
* 4. Heap 에서 동적 메모리를 관리한다. ( 수동, 유동적 메모리 ) / 어떻게 Heap 이 변할지 알 수 없다.
* 
*/

// 3_1. new 키워드를 이용해 만들지 않은 변수, 클래스 인스턴스들은 Stack 에 쌓아두고 함수가 끝나면 Stack을 비우게된다.
// 4_1. Heap 영역의 함수들은 new 키워드를 이용해 만들어서 함수가 끝나도 지워지지않음. delete 등을 이용하여 지워줘야함



// sum 함수 실행되는 순서

/*
* 1. Stack 에 int v1,v2 생성, 값을 저장할 r 변수 생성
* 2. Instruction에 따라 sum이라는 함수를 실행하게 됨
* 3. sum이라는 함수의 파라미터 a,b ,results(결과변수)가 stack에 생성
* 4. sum 함수를 실행시킨 시점으로 돌아와 r 이라는곳에 집어넣는다.
* 5. stack에서 sum과 관련된 부분을 없앤다.
* 6. Insturction에서 다음 호출은 printf이므로 값이 3인 r을 호출하기 위해 call Stack 이 만듣어진다. 이 이후는 위와 동일	 
*/

// 이렇게 함수는 call Stack 을 만들어야하기 때문에 함수에는 함수 호출 비용이 있다.
// 함수 호출을 한다는 것은 성능적으로, 메모리적으로 어느정도 손해를 감수해야 한다는 것이다.
#include<cstdio>
int sum(int a, int b)
{
	int result = a + b;
	return result;
}

int main()
{
	int v1 = 1;
	int v2 = 2;

	int r = sum(v1, v2);
	printf("결과 : %d", r);

	return 0;
}

/*
{
	"event_version": 32,
		"event_filename" : "popup_event.jpg",
		"event_url" : "https://smartstore.naver.com/xosoft/products/7108154599",
		"event2_version" : 11,
		"event2_filename" : "popup_event2.jpg",
		"event2_url" : "https://smartstore.naver.com/xosoft/category/9aaf64567aa449b39da8c32072f36ac1?cp=1",
		"update_version" : 7,
		"update_filename" : "popup_update.jpg",
		"update_url" : ""
}


{
	"event_version": 33,
		"event_filename" : "popup_event.jpg",
		"event_url" : "https://smartstore.naver.com/xosoft/products/7108154599",
		"event2_version" : 11,
		"event2_filename" : "popup_event2.jpg",
		"event2_url" : "https://smartstore.naver.com/xosoft/products/7695703255",
		"update_version" : 7,
		"update_filename" : "popup_update.jpg",
		"update_url" : ""
}*/