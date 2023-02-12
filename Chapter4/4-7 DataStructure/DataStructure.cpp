#include<cstdio>
#include<vector>
#include<map>
#include<string>
#include<algorithm>
// [Vector] : 배열
/* vector<T>는 배열을 사용하듯이 사용할 수 있으며,
* iterator(순회자)를 통해 각각의 원소를 순회할 수 있고,
* sort() 함수를 이용해 값을 정렬할 수 있다.
*/


// [Map] : 인덱스에 어떠한 값도 들어갈 수 있다.
/* Key,Value 로 들어간다. ex 대한민국, 서울 / 일본, 도쿄
* Key에 value 단 하나의 값이 아니라 구조체일수도 있다.
*/

int main()
{
#pragma region Vector


	std::vector<int> myvec = { 40,10,5 }; // = std::vector<int>(); 벡터 구조체는 굳이 생성자를 필요로 하지 않는다.

	// 벡터클래스에서 가장 많으 쓰는건 push_back
	// 가장 뒤쪽에 값을 넣음
	myvec.push_back(4);
	myvec.push_back(10);
	myvec.push_back(7);

	// sort 함수는 algorithm 헤더파일에 포함되어있다.
	std::sort(myvec.begin(), myvec.end());
	// iterator(순회자)
	/*
	* 기본 자료구조들이 갖고있는 원소 탐색 객체.
	* 원소들을 정렬하고나, for 루프를 돌 수도 있다.
	* 순회자의 값을 가져올 때에는 포인터 값을 가져오는 것처럼
	* *(애스터리스크) 연산자를 활용한다.
	* for(auto it = v.begin(); it !=v.end(); it++) {}
	*/


	// 이터레이터를 활용한 for 루프 돌리기
	// auto 키워드 : 컴파일러가 추론 가능한 데이터 타입을 자동으로 지정해줄 수 있다.
	// 긴 클래스명이나 데이터타입을 짧게 줄일 수 있어서 많이 사용함.
	for (auto it = myvec.begin(); it != myvec.end(); it++) // auto 를 사용한 루프
	//for (std::vector<int>::const_iterator it =  myvec.begin(); it != myvec.end(); it++)
	{
		printf("%d ", *it); // * 붙여야함
	}
	/*
	for (int i = 0; i < myvec.size(); i++)
	{
		printf("%d ", myvec[i]); // 배열처럼 사용 가능한 이유 : std:vector 라는 클래스가 [] 대괄호를 오버로딩 했기 때문에 가능한 것
		//printf("%d ", myvec.at(i)); // 원래는 이렇게 사용해야함
	}*/

#pragma endregion

#pragma region Map
	
	// std::map 은 map 헤더파일에 정의되어있다.
	/*
	* 배열과 비슷하지만, 더 확장성이 좋다.
	* 키와 그에 맞는 값 쌍을 저장한다.
	* 배열처럼 연속적이지 않아도 되며, std::string 등 꼭 int가 아니더라도 키 값을 가질 수 있다는 것이 큰 장점.
	* map은 원소 삽입과 동시에 자동으로 값이 정렬되는 특징이 있다.
	*/

	std::map<std::string, std::string> capitals;
	capitals["korea"] = "seoul";
	capitals["usa"] = "washington";
	capitals["china"] = "beizing";

	printf("\n%s ", capitals["korea"].c_str());
	// map에서 가장 많이 쓰는 함수 count : 키에 해당하는 값이 존재하는지 존재하지 않는지를 반환함

	// erase : 해당 키 값을 지워주는 역할
	//capitals.erase("korea");

	if (capitals.count("korea") == 1) // map 이라는 자료구조가 하나의 key에 여러개의 자료형이 대응되기 때문에 숫자를 반환함
	{
		printf("korea가 존재합니다");
	}
	else
		printf("korea가 존재하지 않습니다");

	// std::map 의 순회
	/*
	* std::map은 순회를 하기 위해 일반적인 for루프를 활용할 수 없고, iterator(순회자)를 활용하여야만 가능하다.
	* for( auto it=  m.bewgin(); it!= beign.end(); it++){ 
	* it->first; // map의 각각 키
	* it->second; // map의 각각 값
	*/

	for (auto it = capitals.begin(); it != capitals.end(); it++)
	{
		//printf("\nfirst : %s\n", it->first.c_str());
		//printf("second : %s", it->second.c_str());
		printf("\ncapitals[%s] = %s", it->first.c_str(), it->second.c_str());
	}
	// map 에서 제공한 인덱스는 넣은 순서로 들어가는게 아니라 내부적으로 tree 라는 자료구조를 통해 만들어지게 된다.
	// 자동으로 정렬이 되며 들어가게 됨.
	// key의 값 쌍이 자동으로 정렬이 되어 출력됨.
	

#pragma endregion

	return 0;
}
