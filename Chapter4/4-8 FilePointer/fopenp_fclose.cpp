#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>

// foepn 함수와 fclose 함수의 기능을 좀 더 알아보기

bool file_exitst(const char* filename) // txt파일이 있는지 없는지 검사하는 함수로 따로 제작함
{
	FILE* fp = fopen(filename, "r");
	if (fp != nullptr)
		fclose(fp);

	return fp != nullptr;
}
int main()
{
	// fopen을 사용할때는 꼭 fclose()를 먼저 아래쪽에 만들고 그 사이에 하는것이 좋다.
	// 다른언어에서도 동일한 방식으로 되므로 익숙한게 좋음
	FILE* infile = fopen("sample.txt", "r"); // 읽기전용으로열었다 -> 파일이 없다면 nullptr을 반환하는데, 이 예외처리를 해줘야함
	// data
	if (infile != nullptr) fclose(infile);
	bool fileIsExists = infile != nullptr;


	bool exists = file_exitst("sample.txt");
	if (exists)
	{
		printf("파일이 존재합니다");
	}
	else
		printf("파일이 존재하지 않습니다");



	return 0;
}