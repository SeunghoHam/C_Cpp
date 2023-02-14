#define _CRT_SECURE_NO_WARNINGS
#include<cstdio>

// fprintf 함수와 fscanf 함수의 기능을 좀 더 알아보기

bool file_exitst(const char* filename) // txt파일이 있는지 없는지 검사하는 함수로 따로 제작함
{
	FILE* fp = fopen(filename, "r");
	if (fp != nullptr)
		fclose(fp);

	return fp != nullptr;
}

int main()
{
	FILE* outfile = fopen("out.txt", "w"); // 쓰기모드로 생성함
	fprintf(outfile,"%d / HelloWorld / %d", 100, 200);

	FILE* infile = fopen("in.txt", "r");
	//fprintf(infile, "헬로월드");

	int data1;
	int data2;

	//char line[128];
	//fscanf(infile, "%d %d", &data1, &data2); // 공백을 이용해서 나눠받는다.
	//printf("data1 : %d,data2: %d", data1, data2);
	//fscanf(infile, "%127[^\n]s" ,&line);

	// fscanf 주의할점 : 한 줄에서 읽으려고 할 때 문제가 발생할 수 있다.

	//printf("%s", line);
	//fclose(infile);
	// fscanf 의 큰 장점 : format 문자열을 이용해서 여러개의 값을 한꺼번에 받아올 수 있음

	//fclose(outfile);



	// 한줄 한줄씩 fscanf를 받아오기
	char ipsumLine[256];

//	fscanf(infile, "%256[^\n]s", &ipsumLine);
//	printf("%s\n", ipsumLine);
//	fgetc(infile); // 파일스트림의 현재 포인터에서 문자 하나를 읽어서 리턴함.fcanf가 개행문자(\n)가 나오기 전까지 읽는다

	/* 줄 내림을 fgetc를 이용해서 하는 이유
	* %s 옵션을 이용하면 \n를 알아서 구분할 수는 있지만, 올바르게 동작하지 않을 확률이 높다.
	* 대부분 프로그래머가 %s 가 아닌 안전한 방법인 %숫자[^\n]s 옵션을 사용한다. 이렇기 때문에 벌어지는현상
	*/
//	fscanf(infile, "%256[^\n]s", &ipsumLine);
//	printf("%s\n", ipsumLine);

	while (true)
	{
		char line[256];
		fscanf(infile, "%255[^\n]s", line);
		fgetc(infile);

		printf("%s\n", line);

		// feof : 파일의 끝에 당도하면 1 을 리턴
		if (feof(infile) == 1) // 파일 끝에서 탈출
			break;
	}
	fclose(infile);
	return 0;

}