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
			int korean = GetInt("���� ���� �Է� : ");
			int math = GetInt("���� ���� �Է� : ");
			int english = GetInt("���� ���� �Է� : ");
			
			fscanf(studentFile," %99[^\n]s %d %d %d", name, korean, math, english);
			printf("������ ����Ǿ����ϴ� \n\n");
			fclose(studentFile);
		}
		else if (menu == 2)
		{
			
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
