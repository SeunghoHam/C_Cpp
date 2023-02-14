#define _CRT_SECURE_NO_WARNINGS
#include<cstdio>

// fprintf �Լ��� fscanf �Լ��� ����� �� �� �˾ƺ���

bool file_exitst(const char* filename) // txt������ �ִ��� ������ �˻��ϴ� �Լ��� ���� ������
{
	FILE* fp = fopen(filename, "r");
	if (fp != nullptr)
		fclose(fp);

	return fp != nullptr;
}

int main()
{
	FILE* outfile = fopen("out.txt", "w"); // ������� ������
	fprintf(outfile,"%d / HelloWorld / %d", 100, 200);

	FILE* infile = fopen("in.txt", "r");
	//fprintf(infile, "��ο���");

	int data1;
	int data2;

	//char line[128];
	//fscanf(infile, "%d %d", &data1, &data2); // ������ �̿��ؼ� �����޴´�.
	//printf("data1 : %d,data2: %d", data1, data2);
	//fscanf(infile, "%127[^\n]s" ,&line);

	// fscanf �������� : �� �ٿ��� �������� �� �� ������ �߻��� �� �ִ�.

	//printf("%s", line);
	//fclose(infile);
	// fscanf �� ū ���� : format ���ڿ��� �̿��ؼ� �������� ���� �Ѳ����� �޾ƿ� �� ����

	//fclose(outfile);



	// ���� ���پ� fscanf�� �޾ƿ���
	char ipsumLine[256];

//	fscanf(infile, "%256[^\n]s", &ipsumLine);
//	printf("%s\n", ipsumLine);
//	fgetc(infile); // ���Ͻ�Ʈ���� ���� �����Ϳ��� ���� �ϳ��� �о ������.fcanf�� ���๮��(\n)�� ������ ������ �д´�

	/* �� ������ fgetc�� �̿��ؼ� �ϴ� ����
	* %s �ɼ��� �̿��ϸ� \n�� �˾Ƽ� ������ ���� ������, �ùٸ��� �������� ���� Ȯ���� ����.
	* ��κ� ���α׷��Ӱ� %s �� �ƴ� ������ ����� %����[^\n]s �ɼ��� ����Ѵ�. �̷��� ������ ������������
	*/
//	fscanf(infile, "%256[^\n]s", &ipsumLine);
//	printf("%s\n", ipsumLine);

	while (true)
	{
		char line[256];
		fscanf(infile, "%255[^\n]s", line);
		fgetc(infile);

		printf("%s\n", line);

		// feof : ������ ���� �絵�ϸ� 1 �� ����
		if (feof(infile) == 1) // ���� ������ Ż��
			break;
	}
	fclose(infile);
	return 0;

}