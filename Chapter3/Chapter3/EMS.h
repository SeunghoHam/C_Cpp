#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable: 4996)
#include<cstdio>
#include<cstring>
#include<cstdlib>

int number_Count = 1;
class Employee
{
public:
	int num = NULL;
	char* name = nullptr;
	int gender; // 0 : 남자, 1 : 여자
	char* rank = nullptr;

	Employee(char* _name, int _gender, char* _rank)
	{
		this->name = new char[strlen(_name) + 1]; // _name의 문자열 길이 가져옴(null 문자 제외이기 때문에 +1 시켜줬음)
		strcpy(this->name, _name);
		this->gender = _gender;
		this->rank = new char[strlen(_rank) + 1];
		strcpy(this->rank, _rank);
		this->num = number_Count;
		number_Count++;
	}
public:
	void printImpormation()
	{
		printf("번호 : %d\n", num);
		printf("이름 : %s\n", name);
		printf("성별 : %s\n", gender == 1 ? "남자" : "여자");
		printf("직위 : %s\n", rank);
	}

	~Employee() // 소멸자는 파라미터 없음
	{
		delete[] name;
		delete[] rank;
	}
};

int getInt(const char* prompt);

// 실행 후 메모리할당 해제 해줘야함
char* getString(const char* prompt);