#include "header.h"

int main()
{

	Dictionary* dict = new Dictionary;
	for(;;)
	{
		printf("1. �ܾ� ���\n");
		printf("2. �ܾ� ã��\n");
		printf("3. ���α׷� ����\n");
		int input = GetInt("�޴� ��ȣ�� �Է��ϼ��� : ");
		if (input == 1)
		{
			// �ܾ� ���
			std::string word = GetString("�ܾ �Է��ϼ��� : ");
			std::string mean = GetString("���� �Է��ϼ��� : ");
			dict->InsertWorld(word, mean);

			printf("���������� ��� �Ϸ�\n");
		}
		else if (input == 2)
		{
			// �ܾ� ã��
			std::string word = GetString("ã�� �ܾ�  :");
			if (dict->Exist(word))
			{
				printf("�ܾ� �� : %s\n", dict->GetMean(word).c_str());
			}
			else
				printf("���� �ܾ� �Դϴ� \n");
		}
		else if (input == 3)
		{
			// ���α׷� ����
			printf("���α׷��� �����մϴ�\n");
			break;
		}
		else
		{
			// �ٽ� ��ȯ
			printf("�߸� �Է��ߴ�.\n");
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
	words[word] = meaning; //  word Ű�� meaning value �� �Ҵ���
}

// �ܾ �ִ��� ������ Ȯ��
bool Dictionary::Exist(const std::string& word)
{
	// Count�� ���� 1�̸� return true;
	return words.count(word) == 1; // count �迭�� word �� ������(1) true ��ȯ
	// �Ʒ� ���� ��ó�� �� �ٷ� �ۼ� ����
	/*
	if (words.count(word) == 1)
		return true;
	return false;
	*/
}
// ���� ������.
std::string Dictionary::GetMean(std::string word)
{
	return words[word];
}