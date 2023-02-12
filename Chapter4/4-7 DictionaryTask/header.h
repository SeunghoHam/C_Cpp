#ifndef __HEADER_H__
#define __HEADER_H__

#define _CRT_SECURE_NO_WARNINGS
#include<cstdio>
#include<map>
#include<string>



// 메뉴 입력하기
int GetInt(const char* prompt);

// 문자 입력하기
std::string GetString(const char* prompt);

class Dictionary 
{
private:
	std::map<std::string, std::string> words;
public:
	// 단어 삽입
	// std::string을 파라미터로 받게되면 값 복사가 일어남.
	//  map 에 Assign 할 때 또 한번 값복사가 발생됨.
	// 변수를 그대로 가져오기때문에 값복사가 일어나지않음
	//void InsertWorld(std::string word, std::string meaning)
	void InsertWorld(const std::string& word, const std::string& meaning);
	// 단어가 있는지 없는지 확인
	bool Exist(const std::string& word);
	// 뜻을 가져옴.
	std::string GetMean(std::string word);
};


#endif // !__HEAER_H__

