#include "header.h"

int main()
{

	Dictionary* dict = new Dictionary;
	for(;;)
	{
		printf("1. 단어 등록\n");
		printf("2. 단어 찾기\n");
		printf("3. 프로그램 종료\n");
		int input = GetInt("메뉴 번호를 입력하세요 : ");
		if (input == 1)
		{
			// 단어 등록
			std::string word = GetString("단어를 입력하세요 : ");
			std::string mean = GetString("뜻을 입력하세요 : ");
			dict->InsertWorld(word, mean);

			printf("정상적으로 등록 완료\n");
		}
		else if (input == 2)
		{
			// 단어 찾기
			std::string word = GetString("찾을 단어  :");
			if (dict->Exist(word))
			{
				printf("단어 뜻 : %s\n", dict->GetMean(word).c_str());
			}
			else
				printf("없는 단어 입니다 \n");
		}
		else if (input == 3)
		{
			// 프로그램 종료
			printf("프로그램을 종료합니다\n");
			break;
		}
		else
		{
			// 다시 반환
			printf("잘못 입력했다.\n");
		}
	}

	return 0;
}

std::string GetString(const char* prompt)
{
	char input[100] = { 0, };
	printf(prompt);
	fseek(stdin, 0, SEEK_END);
	scanf("%99[^\n]s", input);
	return input;
}

int GetInt(const char* prompt)
{
	int input;
	printf(prompt);
	fseek(stdin, 0, SEEK_END);
	scanf("%d", &input);
	return input;
}
void  Dictionary::InsertWorld(const std::string& word, const std::string& meaning)
{
	words[word] = meaning; //  word 키에 meaning value 를 할당함
}

// 단어가 있는지 없는지 확인
bool Dictionary::Exist(const std::string& word)
{
	// Count를 세서 1이면 return true;
	return words.count(word) == 1; // count 배열의 word 가 있으면(1) true 반환
	// 아래 식을 위처럼 한 줄로 작성 가능
	/*
	if (words.count(word) == 1)
		return true;
	return false;
	*/
}
// 뜻을 가져옴.
std::string Dictionary::GetMean(std::string word)
{
	return words[word];
}