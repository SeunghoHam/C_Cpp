#include<cstdio>
#include<cstring>
#include<string>
#define _CRT_SECURE_NO_WARNINGS


// const - ���
// ��� : ���α׷��� ���۵Ǹ鼭 ���������� ���� ������ �ʴ� ��.

// cosnt�� define��ũ���̸�, const Ű���带 �̿��� ���� ������
// ��������� '�������' �� ���� �ִ� �����̸� ���������� ���α׷� ���ο� �����ִ� ���̴�.

class Person
{
public :
	const int age;
	// Ŭ���� ���ο����� const ���
	/*
	* Ŭ���� ����� const ����� �����ϸ�, ���� �����μ� ��������� ���� �ִٴ� ���� �� �� �ִ�.
	* const�� ����� Ŭ���� ��� ������ ����� ���ÿ� �ʱ�ȭ �ϰų�, �����ڿ��� �ʱ�ȭ�� ������Ѵ�.
	* �����ڿ��� �ʱ�ȭ�Ҷ��� "�����̸�(�ʱⰪ) "  ���� ������ �ʱ�ȭ�� �Ѵ�.
	*/

	//Person() : age(100) {} // ���� ������ �ʴ� ���α׷��� �����ִ� 100(age)��� ���� �������� ����� �� ���ִ�.
					
	Person(int n) : age(n) {} // �������� ��� age 
	// �����ڿ��� n �̶�� ���� �޾Ƽ� age �� �Ҵ��Ѵ�. 
	
};

#define MYVALUE 100
int main()
{	
	//  ����   ���
	const int value = MYVALUE; // const : ���� ���� �ٸ� ������ �ٲ�� ���� ��ȣ���ش�.
	//printf("%d", value);

	// Ŭ���� ���� const ���� ��������
	//Person* p = new Person();
	//printf("%d", p->age);
	

	int input;
	fseek(stdin, 0, SEEK_END);
	scanf("%d", &input);

	Person* person = new Person(input);
	printf("%d", person->age);
	return 0;
	// 05 : 55
}