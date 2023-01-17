#define _CRT_SECURE_NO_WARNINGS
#include<cstdio>


#include <iostream> // std:count ����� ���� ��ó����
#include<string> // std:string ����� ���� ��ó�������ϱ�
#include<vector>

//namespace : �����ڳ��� ���� �̸��� ������� �ʵ��� �̸����� �������ִ� ������ �ϴ� ����
using namespace std; // "std:  " ���� ����
namespace hong
{
	void foo(){}
	class Marine
	{
	public:
		Marine();
		void printInfo(int i, const char* str);
	};
}

namespace kim
{
	void foo(){}
}


// std:string : C++���� ���ڿ��� Ȱ���ϱ� ���� Ŭ������ ���ڿ�Ÿ��. ���� ����Լ��� ���ǵǾ� �ִ�.
// + ���ڿ��� �����͸� �ڵ����� �������ֱ� ������ �ϳ��ϳ� �����͸� ������ �ʿ����, ������ ������ Ŭ���� �ν��Ͻ��� Ȱ���� �� �ִ�.
int main()
{
	/*
	* #include<cstring> ����ϱ�
	char myString[100];
	strcpy(myString, "HelloWorld");
	strcat(myString, " Hello C++"); // strcat : ���ڿ� ���ϱ� summit
	printf("%s", myString);
	*/

	// #include<string> ����ϱ�
	std::string myStr = "HelloWorld";
	// std::string �� ������ Ŭ���� �ν��Ͻ��� ����ǰ� ���ȴ�. (��Ȯ���� ������ �ƴ� stack allocator�̴�. dynamic�� �ݴ�)
	// ����1 : ���� Ŭ������ ����� �ν��Ͻ��� ����� �Ǹ� �޸𸮰����� ������Ѵ�. - �޸� ������ ������� �ʱ� ����
	// ����2 : = �� �̿��ؼ� ���ڿ��� �޴� ���� ������ �����ε� ������ �����ϴ�. 
	//			std:string* myStrPointer;��  ���� ������������ �ּҰ����� ������ �����ε��� �Ұ����ϴ�.




	myStr = myStr + " Hello C++\n"; // std:string �� + ��ȣ�� �̿��Ͽ� ���ڿ� ���ϱ⸦ �����Ѵ�.

	//	printf("%s", myStr); // myStr�� Ŭ���� �����̱⶧���� %s �� ����Ϸ��ϸ� int ���� ���´�.
	printf("%s", myStr.c_str());
	std::cout << myStr; //cout �� int,float,string ���� �˾Ƽ� �Ǵ��� ��, ����Ѵ�. (������ �ٸ� ���α׷��� ������ ��İ� ������ �������̴�)



	// �� ���� ���ڿ� ��
	std::string str1 = "apple";
	std::string str2 = "banana";

	// ���������� strcmp �� Ȱ��������, std:::compare�� Ȱ���Ѵ�.
	// std::compare : ���� ���ڿ� Ŭ������ ���ڿ��� �Ķ���ͷ� �Է¹��� ���ڿ��� ���Ͽ�, 
	// ���ٸ� 0, ���� ���ڿ� Ŭ������ �켱������ ������ -1, �Ķ���ͷ� ���� ���ڿ��� �켱������ ���ٸ� 1 �� ��ȯ�Ѵ�.


	// if(strcmp(str1.c_str(), str2.c_str()) == 0 ) // strcmp() ����ϱ�
	if (str1.compare(str2) == 0) // ������ �Ǵ�
	{
		printf("�� ���ڿ��� �����ϴ�");
	}
	else
	{
		printf("�� ���ڿ��� �ٸ��ϴ�");
	}


	// namespace ����
	hong::foo();
	kim::foo();
	

	std::string myStr = "Hello World"; // std =  standard Namespace(�⺻�����Լ�)
	std::vector<int> myVec;

	return 0;

};

void hong::foo()
{
	printf("ȫ�浿�� ���� �Լ� foo\n");
}

void kim::foo()
{
	printf("�踻���� ���� �Լ� foo\n");
}
hong::Marine::Marine()
{
	// �����ڵ� namespace ����
}
void hong::Marine::printInfo(int i, const char* str)
{
	// ���ӽ����̽��� Ŭ���� ���� �Լ��� ������ �� �ִ�.
}

