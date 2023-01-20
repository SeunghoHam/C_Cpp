 // STL
/*
* Standard Template Library 
* 각종 자료형에 구애받지 않는 통합 라이브러리를 만들 수 있다.
* C++의 STL은 다른 언어의 Generic과 다른 굉장히 빠른 퍼포먼스를 보여준다.
*/


#include<cstdio>
#include<string>
template <typename T> // STL 클래스에서 타입을 나중에 지정하겠다고 명시하는 방법. T 가 나중에 지정할 타입이름이 된다.
class MyClass
{
public:
	
	// 클래스 내부에는 타입이 지정되지 않은 어떤 것이 있다. ( 타입의 지정을 뒤로 미룬다 )
	// 변수를 사용하기 직전에 정의하는것. template 

	T value; // 클래스 인스턴스를 만들 때 타입이 정해진다.
};

template <typename T>
void swap(T* a, T* b)
{
	T tmp;
	tmp = *a;
	*a = *b;
	*b = tmp;
}


// STL - 가변 배열 클래스 작성
/*
* STL을 활용하여 가변 배열 클래스를 만든다.
* 하나의 통합적인 자료관리 모델을 만들고, 이를 활용한다.
*/


template<typename T>
class MyArray
{
private:
	T* arrayItem; // 나중에 type이 지정되고, 그 타입의 배열 포인터로 활용된다.(고정배열)
	int count = 0;
	int capacity = 8;

public:
	MyArray() // 동적할당(생성자) 후에는 소멸자를 만들어줘야함
	{
		arrayItem = new T[capacity]; // 초기값 설정 해줘야함
	}
	virtual ~MyArray() // 소멸자는 virtual 키워드를 붙이는 것이 좋다. 상속받아서 추가적인 동작을 하는 경우가 많다.
	{
		delete[] arrayItem;
	}

//public:
	// void putValue(T value)
	/*
	* 파라미터를 레퍼런스 타입으로 받게 된다면 const로 받아와야한다
	* ex) std::string 타입을 받는다고 하면, const char 를 받는건데, 레퍼런스타입의 파라미터를 받는다는 것은 그 값이 수정된다는 의미
	* const를 붙임으로 인해 괜찮아짐
* 
	*/
	void putValue(const T& value)
	{
							
		if (capacity <= count)// 초기배열카운트보다 더 많이 생성함 -> 다시 배열을 만들어줘야함
		{
			printf("배열 두배로~\n");
			T* newArray = new T[capacity * 2];
			capacity - capacity * 2;
			for (int i = 0; i < count; i++)
			{
				newArray[i] = arrayItem[i]; // 기존 배열 복사하여 새로운 배열에 할당
			}
			delete[] arrayItem; // delete 로 지워주기
			arrayItem = newArray; // 이렇게 하면 arrayItem 은 heap 영역에 남아있다. 
								//newArray 할당 전의 arrayItem이 가리키는 주소의 값을 지워야함
		}
			arrayItem[count] = value;
			count++;
	}
	int getCount()
	{
		return count;
	}
	T getValue(int index) // index위치에 있는 array배열 변수의 값을 받아온다.
	{
		return arrayItem[index];
	}
};


// STL 선언과 정의 분리
/*
* STL은 선언과 정리를 분리할 수 없다.
* C++ 컴파일러가 그때그때 필요한 타입에 맞는 STL 클래스를 가져와서 그것을 이용해 STL 클래스 몸체(함수) 를 만들기 때문.
* 그래서 STL 클래스는 분리하지 선언-정의 분리하지않고 헤더파일에만 존재한다.
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
	swap<int>(&value1, &value2); // <T> 에 해당하는 부분으로 swap 정의부의 T 가 변환되는것
	printf("value1: %d\n", value1);
	printf("value2: %d\n", value2);


	// STL-Array 관련

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