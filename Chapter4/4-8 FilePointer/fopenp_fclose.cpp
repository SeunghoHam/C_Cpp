#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>

// foepn �Լ��� fclose �Լ��� ����� �� �� �˾ƺ���

bool file_exitst(const char* filename) // txt������ �ִ��� ������ �˻��ϴ� �Լ��� ���� ������
{
	FILE* fp = fopen(filename, "r");
	if (fp != nullptr)
		fclose(fp);

	return fp != nullptr;
}
int main()
{
	// fopen�� ����Ҷ��� �� fclose()�� ���� �Ʒ��ʿ� ����� �� ���̿� �ϴ°��� ����.
	// �ٸ������� ������ ������� �ǹǷ� �ͼ��Ѱ� ����
	FILE* infile = fopen("sample.txt", "r"); // �б��������ο����� -> ������ ���ٸ� nullptr�� ��ȯ�ϴµ�, �� ����ó���� �������
	// data
	if (infile != nullptr) fclose(infile);
	bool fileIsExists = infile != nullptr;


	bool exists = file_exitst("sample.txt");
	if (exists)
	{
		printf("������ �����մϴ�");
	}
	else
		printf("������ �������� �ʽ��ϴ�");



	return 0;
}