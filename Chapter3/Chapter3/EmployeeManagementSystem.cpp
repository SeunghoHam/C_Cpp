#include"EMS.h"

int main()
{
	Employee* employee[100];
	int count = 0; // 처음 사원수 = 0
	while (true)
	{
		printf("정보 입력 \n");
		printf("1. 사원 보기 \n");
		printf("2. 사원 추가 \n");
		printf("3. 사원 삭제 \n");
		printf("4. 프로그램 종료 \n");

		int input;

		fseek(stdin, 0, SEEK_END);
		scanf("%d", &input);
		if (input == 1)
		{
			printf("[사원보기 입력]\n");
		
			for (int i = 0; i < count; i++)
			{
				employee[i]->printImpormation();
			}
			continue;
		}
		else if (input == 2)
		{
			char* name = getString("사원명 입력 : ");
			int gender = getInt("성별 입력(1 남성, 2 여성) :");
			char* rank = getString("직급 입력 : ");

			Employee* obj = new Employee(name, gender, rank); //new 할당으로 동적생성
			employee[count] = obj; // 할당 시킬때는 0
			//employee[count] = new Employee(name, gender, rank);

			count++;
			delete[] name;
			delete[] rank;
			//obj->~Employee();
			//delete obj;
			continue;
		}

		else if (input == 3)
		{
			// 삭제가 안되는 이유
			int number = getInt("사원번호를 입력 : ");
			int deletedIndex = -1;
			for (int i = 0; i < count; i++)
			{
				if (number == employee[i]->num)
				{
					printf("입력값 : %d", i);
					delete employee[i];
					deletedIndex = i;
					continue;
				}
			}

			if (deletedIndex >= 0) // 뭔가를 삭제했다. // 값 땡겨넣기
			{
				for (int i = deletedIndex; i < count - 1; i++)
				{
					employee[i] = employee[i + 1];
				}
			}

			count--;
			printf("\n삭제 완료\n");
		}
		else if (input == 4)
		{

			printf("프로그램 종료\n");
			break;
		}
		else
		{
			printf("올바르지 않은 값. 다시 입력해주세요\n");
			continue;
		}

	}
}

int getInt(const char* prompt)
{
	int input;
	printf("%s", prompt);
	fseek(stdin, 0, SEEK_END);
	scanf_s("%d", &input);
	return input;
}

/// <summary>
/// 
/// </summary>
/// <param name="prompt">먼저 출력하게 될 값 : </param>
/// <returns></returns>
char* getString(const char* prompt) // GetString 이라는 함수가 끝나면 파괴된다.
{
	// 배열 = 주소값
	// 배열 = 포인터
	//char input[100]; //이런식으로 작성하면 반환한 주소값의 값이 파괴된다.
	char* input = new char[100]; // new 키워드를 이용하여 동적할당
	printf("%s", prompt);

	fseek(stdin, 0, SEEK_END);
	scanf("%99[^\n]s", input);
	//printf("getString 입력 : %s", input);
	return input;
}
