#define _CRT_SECURE_NO_WARNINGS
#include<cstdio>

// FILE* fopen(const char* filename, const char* mode);

// filename : 대상 파일명
// mode : 파일을 여는 방법
/*
* w : 쓰기 (존재하지 않으면 새로 생성, 존재하면 지우고 다시 생성)
* r : 읽기 (존재하지 않으면  nullptr 반환, 존재하면 처음부터 읽기)
* a : 파일 이어나가기(존재하지 않으면 새로 생성, 존재하면 파일의 마지막부터 쓰기)
* w+ : 쓰기 또는 읽기( 존재하지 않으면 새로 생성, 존재하면 지우고 다시 생성)
* r+ : 쓰기 또는 읽기(존재하지 않으면 nullptr 반환, 존재하면 처음부터 읽고 쓰기)
* a+ : 이어나가기 또는 읽고 쓰기(존재하지 않으면새로 생성, 존재하면 파일의 마지막부터)
*
* r+ 방식을 많이 사용함. 저장하는 방식.
*/

int main()
{
#pragma region HelloWorld 생성하기
	/*
	FILE* infile = fopen("text.txt", "w"); // 새로생성
	fprintf(infile,"Hello World"); // 생성하기
	fclose(infile);*/
#pragma endregion


#pragma region HellowWorld 읽기
	/*
	FILE* infile = fopen("text.txt", "r"); // r 읽기
	char input[100];
	fscanf(infile, "%99[^\n]s", input);
	fclose(infile); // 종료를 꼭 해줘야함.
	printf("%s", input);*/
#pragma endregion


#pragma region int형 text파일저장
	/*
	FILE* infile = fopen("text.txt", "w");
	int value = 487651;
	// value가 저장은 잘 될 것이다. 하지만 value를 저장하기 위해서 7byte를 사용했는데, int 는 4byte. 3byte가 낭비된다.
	// binary데이터로 저장하는게 공간의 낭비가 없다-> fwrite() 를 활용하면 됨.
	fwrite(&value, sizeof(int), 1, infile); // 버퍼, 사이즈, 최대사이즈, FileStream 
	// + 이런식으로 되면 4byte의 값만 text.txt 에 저장되게 됨. 쓰레기값
	//fprintf(infile, "%d", value);
	fclose(infile);
	*/
	FILE* infile = fopen("text.txt", "r");
	int value;
	fread(&value, sizeof(int), 1, infile);
	fclose(infile);
	printf("%d", value); // txt 파일에서는 이상하게 보이지만, 값이 저장되어있는것에는 문제가 없음.
#pragma endregion



	return 0;
}