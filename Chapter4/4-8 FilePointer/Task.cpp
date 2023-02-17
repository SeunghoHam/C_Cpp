#define _CRT_SECURE_NO_WARNINGS
#include<cstdio>
#include<string>

bool file_exist(const char* filename)
{
	FILE* file = fopen(filename, "w");
	if (file != nullptr)
		fclose(file);

	return file != nullptr;
}
int GetInt(const char* prompt)
{
	printf(prompt);
	int input;
	fseek(stdin, 0, SEEK_END);
	scanf("%d", &input);
	return input;
}
std::string GetString(const char* prompt)
{
	printf(prompt);
	char str[128] = {0,};
	fseek(stdin, 0, SEEK_END);
	scanf("%99[^\n]s", &str); // 배열은 포인터 주소긴 한데
	return  str;
}
void PrintInfo(const char* name)
{
	FILE* infile = fopen("score.txt", "r"); // 읽기전용으로 열기
	fclose(infile);
}
#pragma region SaveData
//template <typename T>
void SaveData(FILE* file, std::string name)
{
	//const char* value[255] = { 0, };
	// 파일에 저장하기
	
	fprintf(file, "%99[^\n]s", name.c_str());
	fgetc(file); // 줄 내림으로 저장
}
void SaveData(FILE* file, int value)
{
	fprintf(file, "%d", value);
	fgetc(file);
}
#pragma endregion

#pragma region Show
void ShowData(FILE* file)
{
	while (true)
	{
		char line[256] = { 0, };
		fscanf(file, "%255[^\n]s", line);
		fgetc(file);
		printf("%s\n", line);

		// feof : 파일에 끝에 닿으면(줄내림X) 
		if (feof(file) == 1)
			break;
	}
	fclose(file);
}
#pragma endregion
int main()
{
	for (;;)
	{
		printf("1. 학생 정보 입력하기 : \n");
		printf("2. 학생의 시험결과 보기 : \n");
		printf("3. 프로그램 종료하기 : \n");

		int menu = GetInt("번호를 입력하세요 : ");

		if (menu == 1)
		{
			FILE* studentFile = fopen("score.txt", "w");

			std::string name = GetString("이름 입력 : ");
			SaveData(studentFile, name);
			/*e
			//fscanf(studentFile, " %99[^\n]s", name);
			fprintf(studentFile, "%99[^\n]s", name);
			fgetc(studentFile);
			*/

			int korean = GetInt("국어 점수 입력 : ");
			SaveData(studentFile, korean);

			/*
			fscanf(studentFile, " %d", korean);

			fgetc(studentFile);
			*/
			int math = GetInt("수학 점수 입력 : ");
			SaveData(studentFile, math);

			/*
			fscanf(studentFile, " %d", math);
			fgetc(studentFile);
			*/
			int english = GetInt("영어 점수 입력 : ");
			SaveData(studentFile, english);

			/*
			fscanf(studentFile, " %d", english);
			fgetc(studentFile);
			*/

			printf("정보가 저장되었습니다 \n\n");
		}
		else if (menu == 2)
		{
			FILE* studentFile = fopen("score.txt", "r");
			ShowData(studentFile);
			fclose(studentFile);
		}
		else if (menu == 3)
		{
			printf("프로램 종료\n");
			break;
		}
		else
			printf("잘못된 입력\n");

	}
}
