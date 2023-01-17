#define _CRT_SECURE_NO_WARNINGS
#include<cstdio>


#include <iostream> // std:count 사용을 위한 전처리기
#include<string> // std:string 사용을 위한 전처리포함하기
#include<vector>

//namespace : 개발자끼리 같은 이름을 사용하지 않도록 이름들을 구분해주는 역할을 하는 개념
using namespace std; // "std:  " 생략 가능
namespace hong
{
	void foo(){}
	class Marine
	{
	public:
		Marine();
		void printInfo(int i, const char* str);
	};
}

namespace kim
{
	void foo(){}
}


// std:string : C++에서 문자열을 활용하기 위한 클래스형 문자열타입. 여러 멤버함수가 정의되어 있다.
// + 문자열의 포인터를 자동으로 관리해주기 때문에 하나하나 포인터를 관리할 필요없이, 정적인 형태의 클래스 인스턴스로 활용할 수 있다.
int main()
{
	/*
	* #include<cstring> 사용하기
	char myString[100];
	strcpy(myString, "HelloWorld");
	strcat(myString, " Hello C++"); // strcat : 문자열 더하기 summit
	printf("%s", myString);
	*/

	// #include<string> 사용하기
	std::string myStr = "HelloWorld";
	// std::string 은 정적인 클래스 인스턴스로 선언되고 사용된다. (정확히는 정적이 아닌 stack allocator이다. dynamic의 반대)
	// 이유1 : 동적 클래스를 만들어 인스턴스를 만들게 되면 메모리관리를 해줘야한다. - 메모리 관리를 사용하지 않기 위해
	// 이유2 : = 를 이용해서 문자열을 받는 것이 연산자 오버로딩 때문에 가능하다. 
	//			std:string* myStrPointer;와  같은 포인터형태의 주소값에는 연산자 오버로딩이 불가능하다.




	myStr = myStr + " Hello C++\n"; // std:string 은 + 기호를 이용하여 문자열 합하기를 지원한다.

	//	printf("%s", myStr); // myStr은 클래스 형태이기때문에 %s 로 출력하려하면 int 값이 나온다.
	printf("%s", myStr.c_str());
	std::cout << myStr; //cout 은 int,float,string 등을 알아서 판단한 뒤, 출력한다. (하지만 다른 프로그래밍 언어와의 방식과 굉장히 이질적이다)



	// 두 개의 문자열 비교
	std::string str1 = "apple";
	std::string str2 = "banana";

	// 이전까지는 strcmp 를 활용했지만, std:::compare를 활용한다.
	// std::compare : 현재 문자열 클래스의 문자열과 파라미터로 입력받은 문자열을 비교하여, 
	// 같다면 0, 현재 문자열 클래스가 우선순위가 높으면 -1, 파라미터로 받은 문자열의 우선순위가 높다면 1 을 반환한다.


	// if(strcmp(str1.c_str(), str2.c_str()) == 0 ) // strcmp() 사용하기
	if (str1.compare(str2) == 0) // 같은지 판단
	{
		printf("두 문자열은 같습니다");
	}
	else
	{
		printf("두 문자열은 다릅니다");
	}


	// namespace 관련
	hong::foo();
	kim::foo();
	

	std::string myStr = "Hello World"; // std =  standard Namespace(기본제공함수)
	std::vector<int> myVec;

	return 0;

};

void hong::foo()
{
	printf("홍길동이 만든 함수 foo\n");
}

void kim::foo()
{
	printf("김말똥이 만든 함수 foo\n");
}
hong::Marine::Marine()
{
	// 생성자도 namespace 가능
}
void hong::Marine::printInfo(int i, const char* str)
{
	// 네임스페이스의 클래스 내부 함수도 가져올 수 있다.
}

