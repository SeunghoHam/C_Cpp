#define _CRT_SECURE_NO_WARNINGS
#include<cstdio>
#include<vector>
#include<map>
#include<string>
#include<algorithm>

#pragma region 같이푼거

int GetInt(const char* prompt)
{
	printf(prompt);
	int input;
	fseek(stdin, 0, SEEK_END);
	scanf_s("%d", &input);
	return input;
}

std::string GetString(const char* prompt)
{
	printf(prompt);
	char str[100] = { 0, };
	fseek(stdin, 0, SEEK_END);
	scanf_s("%99[^\n]s", str); // 이게 뭐였지? 자릿수 맞추는건가?
	return str; // std string 을 return 라는데 char 을 반환해도 자동으로 캐스팅 해줌.
}

int main_asdf()
{
	std::map<std::string, std::string> member;

	for (;;)
	{
		printf("1. 회원가입\n");
		printf("2. 회원가입\n");
		printf("3. 회원가입\n");
		int menu = GetInt("번호를 입력하세요 : ");

		if (menu == 1)
		{
			std::string id = GetString("ID를 입력해 주세요 : ");
			std::string pwd = GetString("비밀번호를 입력해 주세요 : ");


			if (member.count(id)) // 중복검사 - 중복임
			{
				printf("중복된 아이디 입니다.\n");
			}
			else
			{
				printf("회원가입이 완료되었습니다. \n");
				member[id] = pwd; // member 맵에 key-id / value-pwd 로 할당했다.
			}

		}
		else if (menu == 2)
		{
			for (auto it = member.begin(); it != member.end(); it++)
			{
				printf("%s\n", it->first.c_str());
			}
		}
		else if (menu == 3)
		{
			printf("프로그램을 종료합니다\n");
			break;
		}
		else
		{
			printf("잘못된 입력 입니다.\n");
		}
		return 0;
	}
}
#pragma endregion

// 단어의 뜻을 입력할 수 있는 사전을 작성
// 콘솔 입력으로 단어와 뜻을 입력받아 사전에 등록, 검색을 통해 단어의 뜻을 찾을 수 있어야함

// 단어를 검색할 때 정확히 일치하는 단어의 뜻만 출력해야함
// 찬고자 하는 단어가 없다면 단어가 없다는 것을 출력한다.

std::string GetString2(const char* beginDialogue) // 미리 출력시킬 대사를 파미터로 넣어버림
{
	printf(beginDialogue);
	char str[100] = { 0, }; // 초기 값 초기화 해줘야함
	fseek(stdin, 0, SEEK_END);
	scanf_s("%99[^\n]", str); // 정규식(형식지정자)으로 만들기
	return str;
}
int GetInt2(const char* beginDialogue)
{
	printf(beginDialogue);
	int input;
	scanf_s("%d",&input);
	return input;
}

int main()
{
	std::map<std::string, std::string> Dictionry;


	for(;;)
	{
		int input;
		printf("1. 단어 입력\n");
		printf("2. 단어 검색하기\n");
		printf("3. 프로그램 종료\n");
		scanf_s("%d", &input);

		if (input == 1)
		{
			std::string word = GetString2("단어를 입력하세요 ");
			std::string mean = GetString2("뜻을 입력하세요 ");

			if (Dictionry.count(word)) // 크기 반환(중복이 있음)
			{
				printf("중복된 단어입니다.\n");
			}
			else
			{
				printf("입력이 완료되었습니다 \n");
				Dictionry[word] = mean;
			}
		}
		else if (input == 2)
		{
			/*
			for (std::map<std::string, std::string>::const_iterator it = Dictionry.begin(); it != Dictionry.end();)
			{
				printf("%s 단어의 뜻은 %s 이다.\n", it->first.c_str(), it->second.c_str());
			}*/
			
			for (auto it = Dictionry.begin(); it != Dictionry.end(); it++)
			{
				printf("%s 단어의 뜻은 %s 이다.\n", it->first.c_str(), it->second.c_str());

			}
		}
		else if (input == 3)
		{
			printf("프로그램을 종료합니다\n");
			break; // break 를 먹이려면 for루프 안에 있어야함
		}
		else
		{
			printf("잘못된 값을 입력했습니다\n");
		}
	}
	
	//return 0;
}