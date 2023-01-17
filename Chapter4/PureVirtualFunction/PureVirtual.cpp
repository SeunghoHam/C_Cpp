// ���� �����Լ�

// ��ü�� ���� �����Լ�.
// ���� �� �����ϰ� �� ������ �ڽ� Ŭ�������� �����ؾ��Ѵ�. abstract?
/*
* ����ϴ� ���� : ������ ���߿� �ڽ�Ŭ������ �̷�� ���� ��
*/


#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cstring>

#pragma endregion

enum class Time // ����� �ٸ� ������ �ٲٱ� ���� (enum)Time
{
	MORNING, AFTERNOON, NIGHT
};
class Animal
{
public:
	char name[100]; // �� name �������� ���ؼ� �ۺ����� ������
	Animal(const char* name)
	{
		strcpy(this->name, name);
	}

	virtual int getLegs() = 0; // ���� �����Լ� ���� ( �ڽİ�ü���� ���������� ������ �ڽİ�ü new �Ҵ��� �ȵ� )
	void printInfo()
	{
		printf("�̸� : %s / �ٸ� : %d\n", name,getLegs()); // getLegs �Լ� ���
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
	Dog() : Animal("��") {}
	virtual int getLegs()
	{
		return 4;
	}
};
int main()
{

	Person* p = new Person("��ȣ");
	p->setTime(Time::NIGHT);
	p->printInfo();
	Dog* d = new Dog();
	d->printInfo();
	return 0;
}



