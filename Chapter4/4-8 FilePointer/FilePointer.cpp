#define _CRT_SECURE_NO_WARNINGS
#include<cstdio>

// FILE* fopen(const char* filename, const char* mode);

// filename : ��� ���ϸ�
// mode : ������ ���� ���
/*
* w : ���� (�������� ������ ���� ����, �����ϸ� ����� �ٽ� ����)
* r : �б� (�������� ������  nullptr ��ȯ, �����ϸ� ó������ �б�)
* a : ���� �̾����(�������� ������ ���� ����, �����ϸ� ������ ���������� ����)
* w+ : ���� �Ǵ� �б�( �������� ������ ���� ����, �����ϸ� ����� �ٽ� ����)
* r+ : ���� �Ǵ� �б�(�������� ������ nullptr ��ȯ, �����ϸ� ó������ �а� ����)
* a+ : �̾���� �Ǵ� �а� ����(�������� ��������� ����, �����ϸ� ������ ����������)
*
* r+ ����� ���� �����. �����ϴ� ���.
*/

int main()
{
#pragma region HelloWorld �����ϱ�
	/*
	FILE* infile = fopen("text.txt", "w"); // ���λ���
	fprintf(infile,"Hello World"); // �����ϱ�
	fclose(infile);*/
#pragma endregion


#pragma region HellowWorld �б�
	/*
	FILE* infile = fopen("text.txt", "r"); // r �б�
	char input[100];
	fscanf(infile, "%99[^\n]s", input);
	fclose(infile); // ���Ḧ �� �������.
	printf("%s", input);*/
#pragma endregion


#pragma region int�� text��������
	/*
	FILE* infile = fopen("text.txt", "w");
	int value = 487651;
	// value�� ������ �� �� ���̴�. ������ value�� �����ϱ� ���ؼ� 7byte�� ����ߴµ�, int �� 4byte. 3byte�� ����ȴ�.
	// binary�����ͷ� �����ϴ°� ������ ���� ����-> fwrite() �� Ȱ���ϸ� ��.
	fwrite(&value, sizeof(int), 1, infile); // ����, ������, �ִ������, FileStream 
	// + �̷������� �Ǹ� 4byte�� ���� text.txt �� ����ǰ� ��. �����Ⱚ
	//fprintf(infile, "%d", value);
	fclose(infile);
	*/
	FILE* infile = fopen("text.txt", "r");
	int value;
	fread(&value, sizeof(int), 1, infile);
	fclose(infile);
	printf("%d", value); // txt ���Ͽ����� �̻��ϰ� ��������, ���� ����Ǿ��ִ°Ϳ��� ������ ����.
#pragma endregion



	return 0;
}