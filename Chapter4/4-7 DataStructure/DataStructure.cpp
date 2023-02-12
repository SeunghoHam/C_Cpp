#include<cstdio>
#include<vector>
#include<map>
#include<string>
#include<algorithm>
// [Vector] : �迭
/* vector<T>�� �迭�� ����ϵ��� ����� �� ������,
* iterator(��ȸ��)�� ���� ������ ���Ҹ� ��ȸ�� �� �ְ�,
* sort() �Լ��� �̿��� ���� ������ �� �ִ�.
*/


// [Map] : �ε����� ��� ���� �� �� �ִ�.
/* Key,Value �� ����. ex ���ѹα�, ���� / �Ϻ�, ����
* Key�� value �� �ϳ��� ���� �ƴ϶� ����ü�ϼ��� �ִ�.
*/

int main()
{
#pragma region Vector


	std::vector<int> myvec = { 40,10,5 }; // = std::vector<int>(); ���� ����ü�� ���� �����ڸ� �ʿ�� ���� �ʴ´�.

	// ����Ŭ�������� ���� ���� ���°� push_back
	// ���� ���ʿ� ���� ����
	myvec.push_back(4);
	myvec.push_back(10);
	myvec.push_back(7);

	// sort �Լ��� algorithm ������Ͽ� ���ԵǾ��ִ�.
	std::sort(myvec.begin(), myvec.end());
	// iterator(��ȸ��)
	/*
	* �⺻ �ڷᱸ������ �����ִ� ���� Ž�� ��ü.
	* ���ҵ��� �����ϰ�, for ������ �� ���� �ִ�.
	* ��ȸ���� ���� ������ ������ ������ ���� �������� ��ó��
	* *(�ֽ��͸���ũ) �����ڸ� Ȱ���Ѵ�.
	* for(auto it = v.begin(); it !=v.end(); it++) {}
	*/


	// ���ͷ����͸� Ȱ���� for ���� ������
	// auto Ű���� : �����Ϸ��� �߷� ������ ������ Ÿ���� �ڵ����� �������� �� �ִ�.
	// �� Ŭ�������̳� ������Ÿ���� ª�� ���� �� �־ ���� �����.
	for (auto it = myvec.begin(); it != myvec.end(); it++) // auto �� ����� ����
	//for (std::vector<int>::const_iterator it =  myvec.begin(); it != myvec.end(); it++)
	{
		printf("%d ", *it); // * �ٿ�����
	}
	/*
	for (int i = 0; i < myvec.size(); i++)
	{
		printf("%d ", myvec[i]); // �迭ó�� ��� ������ ���� : std:vector ��� Ŭ������ [] ���ȣ�� �����ε� �߱� ������ ������ ��
		//printf("%d ", myvec.at(i)); // ������ �̷��� ����ؾ���
	}*/

#pragma endregion

#pragma region Map
	
	// std::map �� map ������Ͽ� ���ǵǾ��ִ�.
	/*
	* �迭�� ���������, �� Ȯ�强�� ����.
	* Ű�� �׿� �´� �� ���� �����Ѵ�.
	* �迭ó�� ���������� �ʾƵ� �Ǹ�, std::string �� �� int�� �ƴϴ��� Ű ���� ���� �� �ִٴ� ���� ū ����.
	* map�� ���� ���԰� ���ÿ� �ڵ����� ���� ���ĵǴ� Ư¡�� �ִ�.
	*/

	std::map<std::string, std::string> capitals;
	capitals["korea"] = "seoul";
	capitals["usa"] = "washington";
	capitals["china"] = "beizing";

	printf("\n%s ", capitals["korea"].c_str());
	// map���� ���� ���� ���� �Լ� count : Ű�� �ش��ϴ� ���� �����ϴ��� �������� �ʴ����� ��ȯ��

	// erase : �ش� Ű ���� �����ִ� ����
	//capitals.erase("korea");

	if (capitals.count("korea") == 1) // map �̶�� �ڷᱸ���� �ϳ��� key�� �������� �ڷ����� �����Ǳ� ������ ���ڸ� ��ȯ��
	{
		printf("korea�� �����մϴ�");
	}
	else
		printf("korea�� �������� �ʽ��ϴ�");

	// std::map �� ��ȸ
	/*
	* std::map�� ��ȸ�� �ϱ� ���� �Ϲ����� for������ Ȱ���� �� ����, iterator(��ȸ��)�� Ȱ���Ͽ��߸� �����ϴ�.
	* for( auto it=  m.bewgin(); it!= beign.end(); it++){ 
	* it->first; // map�� ���� Ű
	* it->second; // map�� ���� ��
	*/

	for (auto it = capitals.begin(); it != capitals.end(); it++)
	{
		//printf("\nfirst : %s\n", it->first.c_str());
		//printf("second : %s", it->second.c_str());
		printf("\ncapitals[%s] = %s", it->first.c_str(), it->second.c_str());
	}
	// map ���� ������ �ε����� ���� ������ ���°� �ƴ϶� ���������� tree ��� �ڷᱸ���� ���� ��������� �ȴ�.
	// �ڵ����� ������ �Ǹ� ���� ��.
	// key�� �� ���� �ڵ����� ������ �Ǿ� ��µ�.
	

#pragma endregion

	return 0;
}
