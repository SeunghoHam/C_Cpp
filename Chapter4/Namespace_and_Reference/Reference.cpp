#define _CRT_SECURE_NO_WARNINGS
#include<cstdio>
#include<string>
#include<ctime>


// Reference Ÿ��
/*
* �Ķ���͸� ���� ��, Ÿ�� �����ʿ� &(���ۻ���) ��ȣ�� �̿��ϰ� �Ǹ�, �Ķ���͸� ���۷��� Ÿ������ ���� �� �ְ� �ȴ�.
* �� ���縦 �����־� ����ӵ��� ������ �� �� �ִٴ� ������ �ִ�.
*/

/**
* swap �Լ��� ���� ����
* int& : �Ķ������ ���۷���Ÿ��
* &�� �پ������� ���۷��� Ÿ��, ������ �״�� �����´�.
*/
void swap(int& a, int& b) // �����͸� �̿��ؼ� ����� ���� �ƴ�, �Ķ���ͷ� ������ ������ ���� ���ϰ� �ȴ�.
{
	int temp;
	temp = a;
	a = b;
	b = temp;
}

//std::string �� �����Ͱ� �ƴ϶�, ����Ÿ������ ��ȯ�ǰ� ���ȴ�.
// ���� �״�� �������� ���ؼ� (�ڷ���) �� �ƴ϶� (�ڷ���&) ������ �ؼ� �� ���簡 �ּ������� �Ͼ�Եȴ�.
// �� ���簡 �Ͼ�� �ʵ��� ���۷����� �ѱ��.

// ����ȭ �Ϸ��� ������ �������� �޾Ƽ� �ּҰ��� �˾ƿ��ų�, ���۷����� �޾ƿ;��Ѵ�.
void stingSwap(std::string& a, std::string& b)
{
	std::string temp;
	temp = a;
	a = b;
	b = temp;
}


class Vector 
{
public:
	float x;
	float y;
	Vector(float x, float y)
	{
		this->x = x;
		this->y = y;
	}
};

/*
* ������ �����ε��� ���۷��� Ÿ������ �Ķ���͸� �޴´�.
* ������ �����ε��� �ϱ� ���ؼ��� �׻� ���� Ÿ���� Ŭ�������� �޾ƾ��Ѵ�.
* 
* �Ϲ� Vector �� �Ķ���ͷ� �ްԵǸ� x,y �� 8byte�� �����簡 �Ͼ�� �ȴ�.
* 
* ���۷��� Ÿ������ �ްԵǸ� �� ������, �ν��Ͻ��� �״�� ���޵ǹǷ� �ð� ����, ���� �ϰԵȴ�.
*/
Vector operator+(Vector& v1, Vector& v2)
{
	return Vector(v1.x + v2.x, v1.y+v2.y);
}
int main()
{
	std::string svalue1 = "Hello";
	std::string svalue2 = "World";
	int value1 = 100;
	int value2 = 200;
	printf("���� �� %d, %d\n", value1, value2);
	swap(value1, value2);

	printf("���� �� %d, %d", value1, value2);

	float start = clock();
	for (int i = 0; i < 100000; i++)
	{
		stingSwap(svalue1, svalue2);
		
	}
	float end = clock();

	float time = (end -  start)/ CLOCKS_PER_SEC;
	printf("����ð� : %f\n", time);

	// �� ���簡 �Ͼ ����  0.445�� �Ҹ�
	// ���۷��� Ÿ������ �ϸ� 0.178�� �Ҹ�

	/*
	stingSwap(svalue1, svalue2);
	printf("svalue1 = %s, svalue2 = %s\n", svalue1.c_str(), svalue2.c_str());
	*/
}