#define _CRT_SECURE_NO_WARNINGS
#include<cstdio>
#include<cstring>

// static : ����
// static�� class ���ο� ������ ��� :  class ���ο��� �����ϰ� �������� ������ ��
// class �ܺο� ������ ��� : obj���� ���ο��� �����ϰ� �������� ���� ��� ���� �ȴ�.

#define MYVALUE 100
class MyClass
{
public:
	// ��������� class �� �����Ǹ鼭 �ϳ��ϳ� ������ �Ǹ� �޸� ������ ���� ������
	// static ������ class �� ������� �ϴ� �����ؾ��Ѵ�. ( ��ü�� ���������� )

	int a;
	static int b;
	static int static_member_int;

	void foo(); // dynamic ���� �Լ�
	/*
		a = 10;
		this->a = 200;
		printf("foo\n");
	*/
	static void goo(); // static ���� �Լ�
		/*
		// a = 100; //�Ұ����ϴ�
		// Ŭ������ ��ü�� �Ǵ� �ν��Ͻ��� ����.
		// ��ü�� ���̵� ������ �Ǵ� goo �Լ��̱⶧���� a�� ������ Ư���� ���� ����.

		b = 100; // static ���� ����� �������� ���ٰ����ϴ�.
		printf("goo\n");*/
	

	// ���� �Լ��� this Ű���尡 ������ �� ������, ���� �Լ��� this Ű���尡 ������ �� ����.
};