#include<cstdio>
#include<cstring>
#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable:4996)

enum Gender
{
	MALE, FEMALE,
};

class Student
{
public:
	int student_num;
	char name[20];
	Gender gender;
	Student(const char* _name, int _num, Gender _gender)
	{
		this->student_num = _num;
		strcpy(name, _name);
		this->gender = _gender;

	}
	~Student()
	{

	}
	void printInfo()
	{
		printf("%s 학생의 번호는 %d. 성별은 %s 이다. \n",
			this->name, this->student_num, gender == Gender::MALE ? "남성" : "여성"
		);

	}
};


enum class Month
{
	// DEC 의미 중복을 막기 위해 enum class

	JAN = 1, FEB, MAR, APR, MAY, JUN, JUL, AUG, SEP, OCT, NOV, DEC
};
class Math
{
public:
	enum Value {
		INC, DEC
	};
};
int main()
{
	//Month m = Month::MAR;
	// 강제 형변환 시켜줘야함
	//int value = (int)m;
}