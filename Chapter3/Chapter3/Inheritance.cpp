#include<cstdio>
#include<cstring>
#pragma warning (disable:4996)

/*
class Animal
{
public:
	int legs = NULL;
	char name[50] = {NULL ,};
	Animal(int _legs, const char* _name) // 기본생성자
	{
		this->legs = _legs;
		strcpy(this->name, _name);
	}
	void print_AnimalInfo()
	{
		printf("다리의 개수 : %d\n", legs);
		printf("동물의 이름 : %s\n", name);
	}
};
class Person : public Animal
{
public:
	char regist_num[30];

	Person(const char* _regist_num) : Animal(2, "사람")
	{
		strcpy(this->regist_num, _regist_num);
	}
};

class Dog : public Animal
{
public:
	Dog() : Animal(4, "개")
	{
		printf("Dog 생성자 실행");
	}
};

int main()
{
	Animal* a;

	Person* p = new Person("1234-5678"); // Person() : 생성자를 호출한다 / Person : 생성자를 호출하지 않는다.
	p->print_AnimalInfo();

	Dog* d = new Dog;
	d->print_AnimalInfo();


	p = (Person*)a;
	delete p;
}
*/


class Weapon
{
private :
	int damage = NULL;
	int range = NULL;
	int price = NULL;
public:
	Weapon(int _damage,int _range, int _price )
	{
		this->damage = _damage;
		this->range = _range;
		this->price = _price;
	}

	void printInfo()
	{
		printf("공격력 : %d\n", this->damage);
		printf("사정거리 : %d\n", this->range);
		printf("가격 : %d\n", this->price);
	}
};

class ShortType : public Weapon
{
public:
	ShortType() : Weapon(10, 5, 500)
	{
		printf("숏 소드 활성화\n");
	}
};
class LongType : public Weapon
{
public:
	LongType() : Weapon(20, 10, 2000)
	{
		printf("롱 소드 활성화\n");

	}
};
class Hammer : public Weapon
{
public:
	Hammer() : Weapon(30, 7, 3000)
	{
		printf("해머 활성화\n");

	}
};
int main()
{
	ShortType* st = new ShortType;
	st->printInfo();

	LongType* lt = new LongType;	
	lt->printInfo();

	Hammer* hm = new Hammer;
	hm->printInfo();
}