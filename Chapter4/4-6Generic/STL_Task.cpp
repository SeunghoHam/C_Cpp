// 과제형 연습 프로그래밍
/*
* 동적배열관리클래스 MyArray에 
* 특정값이 존재하는지 찾아내어 존재하면 true, 
		존재하지 않으면 false를 리턴하는 함수 constains(T value){} 멤버함수를 추가.
* 특정 위치의 값을 변경하는 함수 replace(int index, T value) {} 멤버함수를 추가
* 특정 위치의 값을 삭제하는 함수 erase(int index){} 를 추가 
*/
#define _CRT_SECURE_NO_WARNINGS
#include<cstdio>
#include<string>

template<typename T>
class MyArray // 동적배열관리 클래스 MyArray
{
private:
	int someValue = 3;
	T* arrayItem;

public:
	int changeIndex;
	int changeValue;
	T value;
public:	
	MyArray()
	{
		arrayItem = new T[someValue];
	}
	virtual ~MyArray()
	{
		delete[] arrayItem;
	}
	void constains(T value) // 값 탐색
	{

	}
	void repalce(int index,T value) // 값 변경
	{
		arrayItem[index] = value;
	}
	void erase(int index)
	{

	}
	void putValue(const T& value)
	{

	}
	T getValue(int index)
	{
		return arrayItem[index];
	}
	void printValue()
	{

	}
};

int main()
{
	MyArray<int>* m = new MyArray<int>();
	m->value = 10;


	
#pragma region replace
	printf("변경을 원하는 수를 입력하세요 : ");
	scanf("%d", &m->changeIndex);

	printf("\n변경할 수를 입력하세요 : ");
	scanf("%d", &m->changeValue);


	m->repalce(m->changeIndex, m->changeValue);

	//printf(m->printValue());
#pragma endregion


	return 0;
}