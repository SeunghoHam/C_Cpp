// ������ ���� ���α׷���
/*
* �����迭����Ŭ���� MyArray�� 
* Ư������ �����ϴ��� ã�Ƴ��� �����ϸ� true, 
		�������� ������ false�� �����ϴ� �Լ� constains(T value){} ����Լ��� �߰�.
* Ư�� ��ġ�� ���� �����ϴ� �Լ� replace(int index, T value) {} ����Լ��� �߰�
* Ư�� ��ġ�� ���� �����ϴ� �Լ� erase(int index){} �� �߰� 
*/
#define _CRT_SECURE_NO_WARNINGS
#include<cstdio>
#include<string>

template<typename T>
class MyArray // �����迭���� Ŭ���� MyArray
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
	void constains(T value) // �� Ž��
	{

	}
	void repalce(int index,T value) // �� ����
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
	printf("������ ���ϴ� ���� �Է��ϼ��� : ");
	scanf("%d", &m->changeIndex);

	printf("\n������ ���� �Է��ϼ��� : ");
	scanf("%d", &m->changeValue);


	m->repalce(m->changeIndex, m->changeValue);

	//printf(m->printValue());
#pragma endregion


	return 0;
}