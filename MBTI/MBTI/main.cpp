#include"Header.h"
//#include"Header.cpp"
using namespace std;
// Value
int arr_Answer[4] = { 1,2,3,4 };
int curQuest; // 0 = IE, 1 = SN...
struct Question_I_E
{
	int curQuestionCount; // 몇 번째 문제를 하고 있는지
	int _score;
	void ChaneScore(int i)
	{
		
	}
};
/// <summary>
/// 첫 번째 대답 후, 이 답을 이어갈지 확인
/// </summary>
/// <param name="_inputValue">처음 입력한 값</param>
int AskAgain(int& _finalreturnValue)
{
	//int _finalreturnValue;

	int _temp = _finalreturnValue;

	char againInput = NULL; // 입력한 답 확정 or 다시 입력하기 :: 입력확인용 변수
	// againInput을 char 형으로 받은 뒤, 반환할 때 int 형으로 형변환 시킴

	bool isEnd = false;
	while (!isEnd)
	{
		printf("\n 당신이 선택한 수는 [%d] 입니다", _temp);
		printf("\n 다시 선택하시려면 숫자를 , 다음 문제를 진행하려면 Enter를 입력해주세요 : \n");

		fseek(stdin, 0, SEEK_END);
		//againInput = NULL;
		//againInput = getchar(); // scanf_s 에서 '\n'가 인식을 못해서 getchar() 함수를 사용해야겠다
		scanf_s("%c", &againInput); // Enter 의 ASCII 코드를 알아와야함 = '\n'

		if (againInput == '\n') // Enter 입력일 때만 다음 문제 가도록 ,아니면 AskAgain 다시
		{
			//Sleep(1000);
			printf("'%d' 를 선택하셨습니다. 다음 문제를 진행합니다. ", _temp); // 이렇게 하면 아스키코드 값이 나옴.
			isEnd = true; // 여기서 종료
		}
		else
		{
			//if ((int)againInput == arr_Answer[0] || (int)againInput == arr_Answer[1] || 
				//(int)againInput == arr_Answer[2] || (int)againInput == arr_Answer[3] ) // [ o ] 
				if (againInput == '1' || againInput == '3' ||
					againInput == '2'|| againInput == '4' ) // [ o ] 
			{
				_temp = NULL; // 값이 바뀌게 되니까 _temp 초기화
				_temp = againInput - '0'; // 다른 값 전달 // chat to int 하는법 = '0' 을 뺌으로서 아스키코드값을 상수값으로 변환시킴
				printf("다른 답을 입력했음 : [%c]\n", againInput);
			}
			else // [ x ] 
			{
				printf("범위에 포함되지 않는 값을 입력하였다. 다시 입력해! \n");
			}
			continue; // AskAgain을 다시 돌기 위해서 continue;
		}
	} // While 종료
	return _temp;
	// AskAgain 함수가 끝나면 GetAnswer() 로 반환된다.
}
/// <summary>
/// 답 입력을 반환하여 문제의 score 에 합산된다.
/// </summary>
/// <returns></returns>
int AnswerInput() // call by reference 로 전달해야 ie->score 에 값이 저장되게 할 수 있음
{
	bool isEnd = false;
	while (!isEnd)
	{
		//printf("\nAnswerInput 구문 돕니다! \n ");
		int _input;
		fseek(stdin, 0, SEEK_END);
		scanf_s("%d", &_input);
		switch (_input)
		{
		case 1:
			return AskAgain(_input); // 재질문 후. ie->score 에 할당한다.
			isEnd = true;
			break;
		case 2:
			return AskAgain(_input); // 재질문 후. ie->score 에 할당한다.
			isEnd = true;
			break;
		case 3:
			return AskAgain(_input); // 재질문 후. ie->score 에 할당한다.
			isEnd = true;
			break;
		case 4:
			return AskAgain(_input); // 재질문 후. ie->score 에 할당한다.
			isEnd = true;
			return _input;
		default:
			printf("범위에 포함되지 않은 값 입니다. 다시 입력해주세요\n");
			continue;//다시 입력해야 하니까 재귀시킴
		}
	}
	



}
int GetAnswer()
{
	printf("질문 : [%s]\n", string_Question_I_E_1);
	printf("나의 해당 점수는 ? \n그렇지 않다← [%d] , [%d] , [%d] , [%d] →매우 그렇다\n",
		arr_Answer[0], arr_Answer[1], arr_Answer[2], arr_Answer[3]);

	return AnswerInput();
}

void Question(Question_I_E* _ie)
{
	switch (curQuest) // 현재 어떤 질문 상태인지
	{
	case 0: // I_E
		switch (_ie->curQuestionCount) // 이 단계전에 ie 정보가 없음
		{
		case 0:
			_ie->_score += GetAnswer(); // 더하는거로 해야 합산이 됨
			_ie->curQuestionCount += 1;
			break;
		case 1:
			break;
		case 2:
			break;
		case 3:
			//
			break;
		default:
			break;

			break;
		}
	default:
		break;
	}
}

void GetQuetionInformation()
{
	Question_I_E* ie;
	ie = (Question_I_E*)malloc(sizeof(Question_I_E));
	ie->curQuestionCount = 0;
	printf("IE의 퀘스트 카운트 : %d", ie->curQuestionCount);
}

void Intro()
{
	printf("▣ MBTI테스트 만들기 ▣ \n");
}
int main()
{
	Intro();
	Question_I_E* ie;
	ie = (Question_I_E*)malloc(sizeof(Question_I_E));
	ie->curQuestionCount = 0; // 구조체 포인터 경고 // 반환 값 없을때의 경우 설정해줘야함
	Question(ie);
	
	return 0;
}



