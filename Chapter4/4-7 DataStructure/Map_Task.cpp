#define _CRT_SECURE_NO_WARNINGS
#include<cstdio>
#include<vector>
#include<map>
#include<string>
#include<algorithm>

#pragma region ����Ǭ��

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
	scanf_s("%99[^\n]s", str); // �̰� ������? �ڸ��� ���ߴ°ǰ�?
	return str; // std string �� return ��µ� char �� ��ȯ�ص� �ڵ����� ĳ���� ����.
}

int main_asdf()
{
	std::map<std::string, std::string> member;

	for (;;)
	{
		printf("1. ȸ������\n");
		printf("2. ȸ������\n");
		printf("3. ȸ������\n");
		int menu = GetInt("��ȣ�� �Է��ϼ��� : ");

		if (menu == 1)
		{
			std::string id = GetString("ID�� �Է��� �ּ��� : ");
			std::string pwd = GetString("��й�ȣ�� �Է��� �ּ��� : ");


			if (member.count(id)) // �ߺ��˻� - �ߺ���
			{
				printf("�ߺ��� ���̵� �Դϴ�.\n");
			}
			else
			{
				printf("ȸ�������� �Ϸ�Ǿ����ϴ�. \n");
				member[id] = pwd; // member �ʿ� key-id / value-pwd �� �Ҵ��ߴ�.
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
			printf("���α׷��� �����մϴ�\n");
			break;
		}
		else
		{
			printf("�߸��� �Է� �Դϴ�.\n");
		}
		return 0;
	}
}
#pragma endregion

// �ܾ��� ���� �Է��� �� �ִ� ������ �ۼ�
// �ܼ� �Է����� �ܾ�� ���� �Է¹޾� ������ ���, �˻��� ���� �ܾ��� ���� ã�� �� �־����

// �ܾ �˻��� �� ��Ȯ�� ��ġ�ϴ� �ܾ��� �游 ����ؾ���
// ������ �ϴ� �ܾ ���ٸ� �ܾ ���ٴ� ���� ����Ѵ�.

std::string GetString2(const char* beginDialogue) // �̸� ��½�ų ��縦 �Ĺ��ͷ� �־����
{
	printf(beginDialogue);
	char str[100] = { 0, }; // �ʱ� �� �ʱ�ȭ �������
	fseek(stdin, 0, SEEK_END);
	scanf_s("%99[^\n]", str); // ���Խ�(����������)���� �����
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
		printf("1. �ܾ� �Է�\n");
		printf("2. �ܾ� �˻��ϱ�\n");
		printf("3. ���α׷� ����\n");
		scanf_s("%d", &input);

		if (input == 1)
		{
			std::string word = GetString2("�ܾ �Է��ϼ��� ");
			std::string mean = GetString2("���� �Է��ϼ��� ");

			if (Dictionry.count(word)) // ũ�� ��ȯ(�ߺ��� ����)
			{
				printf("�ߺ��� �ܾ��Դϴ�.\n");
			}
			else
			{
				printf("�Է��� �Ϸ�Ǿ����ϴ� \n");
				Dictionry[word] = mean;
			}
		}
		else if (input == 2)
		{
			/*
			for (std::map<std::string, std::string>::const_iterator it = Dictionry.begin(); it != Dictionry.end();)
			{
				printf("%s �ܾ��� ���� %s �̴�.\n", it->first.c_str(), it->second.c_str());
			}*/
			
			for (auto it = Dictionry.begin(); it != Dictionry.end(); it++)
			{
				printf("%s �ܾ��� ���� %s �̴�.\n", it->first.c_str(), it->second.c_str());

			}
		}
		else if (input == 3)
		{
			printf("���α׷��� �����մϴ�\n");
			break; // break �� ���̷��� for���� �ȿ� �־����
		}
		else
		{
			printf("�߸��� ���� �Է��߽��ϴ�\n");
		}
	}
	
	//return 0;
}