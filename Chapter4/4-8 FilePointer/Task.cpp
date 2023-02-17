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
	scanf("%99[^\n]s", &str); // �迭�� ������ �ּұ� �ѵ�
	return  str;
}
void PrintInfo(const char* name)
{
	FILE* infile = fopen("score.txt", "r"); // �б��������� ����
	fclose(infile);
}
#pragma region SaveData
//template <typename T>
void SaveData(FILE* file, std::string name)
{
	//const char* value[255] = { 0, };
	// ���Ͽ� �����ϱ�
	
	fprintf(file, "%99[^\n]s", name.c_str());
	fgetc(file); // �� �������� ����
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

		// feof : ���Ͽ� ���� ������(�ٳ���X) 
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
		printf("1. �л� ���� �Է��ϱ� : \n");
		printf("2. �л��� ������ ���� : \n");
		printf("3. ���α׷� �����ϱ� : \n");

		int menu = GetInt("��ȣ�� �Է��ϼ��� : ");

		if (menu == 1)
		{
			FILE* studentFile = fopen("score.txt", "w");

			std::string name = GetString("�̸� �Է� : ");
			SaveData(studentFile, name);
			/*e
			//fscanf(studentFile, " %99[^\n]s", name);
			fprintf(studentFile, "%99[^\n]s", name);
			fgetc(studentFile);
			*/

			int korean = GetInt("���� ���� �Է� : ");
			SaveData(studentFile, korean);

			/*
			fscanf(studentFile, " %d", korean);

			fgetc(studentFile);
			*/
			int math = GetInt("���� ���� �Է� : ");
			SaveData(studentFile, math);

			/*
			fscanf(studentFile, " %d", math);
			fgetc(studentFile);
			*/
			int english = GetInt("���� ���� �Է� : ");
			SaveData(studentFile, english);

			/*
			fscanf(studentFile, " %d", english);
			fgetc(studentFile);
			*/

			printf("������ ����Ǿ����ϴ� \n\n");
		}
		else if (menu == 2)
		{
			FILE* studentFile = fopen("score.txt", "r");
			ShowData(studentFile);
			fclose(studentFile);
		}
		else if (menu == 3)
		{
			printf("���η� ����\n");
			break;
		}
		else
			printf("�߸��� �Է�\n");

	}
}
