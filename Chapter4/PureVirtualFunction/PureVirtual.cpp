// 순수 가상함수

// 몸체가 없는 가상함수.
// 선언 만 존재하고 그 동작을 자식 클래스에서 구현해야한다. abstract?
/*
* 사용하는 이유 : 구현을 나중에 자식클래스로 미루고 싶은 것
*/


#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cstring>

#pragma endregion

enum class Time // 사람의 다리 개수를 바꾸기 위한 (enum)Time
{
	MORNING, AFTERNOON, NIGHT
};
class Animal
{
public:
	char name[100]; // 이 name 가져오기 위해서 퍼블릭으로 생성함
	Animal(const char* name)
	{
		strcpy(this->name, name);
	}

	virtual int getLegs() = 0; // 순수 가상함수 생성 ( 자식객체에서 생성해주지 않으면 자식개체 new 할당이 안됨 )
	void printInfo()
	{
		printf("이름 : %s / 다리 : %d\n", name,getLegs()); // getLegs 함수 사용
	}
};

class Person : public Animal
{
private:
	Time time = Time::MORNING;
public:
	Person(const char* name) : Animal(name) {}

	virtual int getLegs()  
	{
		switch (time)
		{
		case Time::MORNING:
			return 4;
		case Time::AFTERNOON:
			return 2;
		case Time::NIGHT:
			return 3;		
		default:
			return 2;
		}
		return 2;
	}

	void setTime(Time time)
	{
		this->time = time;
	}
};

class Dog : public Animal
{
public:
	Dog() : Animal("개") {}
	virtual int getLegs()
	{
		return 4;
	}
};
int main()
{

	Person* p = new Person("승호");
	p->setTime(Time::NIGHT);
	p->printInfo();
	Dog* d = new Dog();
	d->printInfo();
	return 0;
}



