 // STL
/*
* Standard Template Library 
* ���� �ڷ����� ���ֹ��� �ʴ� ���� ���̺귯���� ���� �� �ִ�.
* C++�� STL�� �ٸ� ����� Generic�� �ٸ� ������ ���� �����ս��� �����ش�.
*/


#include<cstdio>
#include<string>
template <typename T> // STL Ŭ�������� Ÿ���� ���߿� �����ϰڴٰ� ����ϴ� ���. T �� ���߿� ������ Ÿ���̸��� �ȴ�.
class MyClass
{
public:
	
	// Ŭ���� ���ο��� Ÿ���� �������� ���� � ���� �ִ�. ( Ÿ���� ������ �ڷ� �̷�� )
	// ������ ����ϱ� ������ �����ϴ°�. template 

	T value; // Ŭ���� �ν��Ͻ��� ���� �� Ÿ���� ��������.
};

template <typename T>
void swap(T* a, T* b)
{
	T tmp;
	tmp = *a;
	*a = *b;
	*b = tmp;
}


// STL - ���� �迭 Ŭ���� �ۼ�
/*
* STL�� Ȱ���Ͽ� ���� �迭 Ŭ������ �����.
* �ϳ��� �������� �ڷ���� ���� �����, �̸� Ȱ���Ѵ�.
*/


template<typename T>
class MyArray
{
private:
	T* arrayItem; // ���߿� type�� �����ǰ�, �� Ÿ���� �迭 �����ͷ� Ȱ��ȴ�.(�����迭)
	int count = 0;
	int capacity = 8;

public:
	MyArray() // �����Ҵ�(������) �Ŀ��� �Ҹ��ڸ� ����������
	{
		arrayItem = new T[capacity]; // �ʱⰪ ���� �������
	}
	virtual ~MyArray() // �Ҹ��ڴ� virtual Ű���带 ���̴� ���� ����. ��ӹ޾Ƽ� �߰����� ������ �ϴ� ��찡 ����.
	{
		delete[] arrayItem;
	}

//public:
	// void putValue(T value)
	/*
	* �Ķ���͸� ���۷��� Ÿ������ �ް� �ȴٸ� const�� �޾ƿ;��Ѵ�
	* ex) std::string Ÿ���� �޴´ٰ� �ϸ�, const char �� �޴°ǵ�, ���۷���Ÿ���� �Ķ���͸� �޴´ٴ� ���� �� ���� �����ȴٴ� �ǹ�
	* const�� �������� ���� ��������
* 
	*/
	void putValue(const T& value)
	{
							
		if (capacity <= count)// �ʱ�迭ī��Ʈ���� �� ���� ������ -> �ٽ� �迭�� ����������
		{
			printf("�迭 �ι��~\n");
			T* newArray = new T[capacity * 2];
			capacity - capacity * 2;
			for (int i = 0; i < count; i++)
			{
				newArray[i] = arrayItem[i]; // ���� �迭 �����Ͽ� ���ο� �迭�� �Ҵ�
			}
			delete[] arrayItem; // delete �� �����ֱ�
			arrayItem = newArray; // �̷��� �ϸ� arrayItem �� heap ������ �����ִ�. 
								//newArray �Ҵ� ���� arrayItem�� ����Ű�� �ּ��� ���� ��������
		}
			arrayItem[count] = value;
			count++;
	}
	int getCount()
	{
		return count;
	}
	T getValue(int index) // index��ġ�� �ִ� array�迭 ������ ���� �޾ƿ´�.
	{
		return arrayItem[index];
	}
};


// STL ����� ���� �и�
/*
* STL�� ����� ������ �и��� �� ����.
* C++ �����Ϸ��� �׶��׶� �ʿ��� Ÿ�Կ� �´� STL Ŭ������ �����ͼ� �װ��� �̿��� STL Ŭ���� ��ü(�Լ�) �� ����� ����.
* �׷��� STL Ŭ������ �и����� ����-���� �и������ʰ� ������Ͽ��� �����Ѵ�.
*/
int main()
{
	MyClass<int>* m = new MyClass<int>();
	m->value = 100;

	MyClass<std::string>* ms = new MyClass<std::string>();
	ms->value = "HelloWorld";


	int value1 = 100;
	int value2 = 200;

	printf("value1: %d\n", value1);
	printf("value2: %d\n", value2);
	swap<int>(&value1, &value2); // <T> �� �ش��ϴ� �κ����� swap ���Ǻ��� T �� ��ȯ�Ǵ°�
	printf("value1: %d\n", value1);
	printf("value2: %d\n", value2);


	// STL-Array ����

	MyArray<int> array = MyArray<int>();
	array.putValue(10);
	array.putValue(20);
	array.putValue(30);
	array.putValue(40);
	array.putValue(50);
	array.putValue(60);
	array.putValue(70);
	array.putValue(80);
	array.putValue(90);


	for (int i = 0; i < array.getCount(); i++)
	{
		printf("%d ", array.getValue(i));
	}
	return 0;
}