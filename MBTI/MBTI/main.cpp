#include"Header.h"
using namespace std;

// Value
int arr_Answer[4] = { 1,2,3,4 };
int curQuest; // 0 = IE, 1 = SN... 현재 어떤 카테고리의 질문을 받고 있는지

char MBTI[4];
/// <summary>
/// [a][b] // a : 어떤 질문인지 0~3, b : 몇 번째 질문인지 0~3
/// </summary>
const char* string_Question[4][4] =
{
	string_Question_I_E_1,string_Question_I_E_2,string_Question_I_E_3,string_Question_I_E_4,
	string_Question_S_N_1,string_Question_S_N_2,string_Question_S_N_3,string_Question_S_N_4,
	string_Question_T_F_1,string_Question_T_F_2,string_Question_T_F_3,string_Question_T_F_4,
	string_Question_J_P_1,string_Question_J_P_2,string_Question_J_P_3,string_Question_J_P_4,
};

struct STRUCT_Question
{
	int curQuestionCount = 0; // 몇 번째 문제를 하고 있는지
	int _result[4]; // 각 배열에 결과 저장
	int _FinalValue = 0; // 최종 수치값

	void QuestionInit()
	{
		curQuestionCount = 0;
		_FinalValue = 0;
	}
	void ChaneScore() // 1~4 번호 받은 것 치환 -3 -1 1 3
	{
		for (int i = 0; i < 4; i++)
		{
			switch (_result[i])
			{
			case 1:
				_FinalValue -= 3;
				break;
			case 2: _FinalValue -= 1;
				break;
			case 3:
				_FinalValue += 1;
			case 4:
				break;
				_FinalValue += 3;
				break;
			default:
				_FinalValue += 0;
				break;
			}
		}
	}

	char ProduceResult(char a, char b)
	{
		if (_FinalValue >= 0) // 0 이상일 때 왼쪽답 나온다.
		{
			return b;
		}
		else
		{
			return a;
		}
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
			printf("'%d' 를 선택하셨습니다. 다음 문제를 진행합니다.\n\n", _temp); // 이렇게 하면 아스키코드 값이 나옴.
			isEnd = true; // 여기서 종료
		}
		else
		{
			//if ((int)againInput == arr_Answer[0] || (int)againInput == arr_Answer[1] || 
				//(int)againInput == arr_Answer[2] || (int)againInput == arr_Answer[3] ) // [ o ] 
			if (againInput == '1' || againInput == '3' ||
				againInput == '2' || againInput == '4') // [ o ] 
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
int GetAnswer(const char* _char)
{
	//printf("질문 : [%s]\n", string_Question_I_E_1);
	printf("질문 : [%s]\n", _char);
	printf("나의 해당 점수는 ? \n그렇지 않다← [%d] , [%d] , [%d] , [%d] →매우 그렇다\n",
		arr_Answer[0], arr_Answer[1], arr_Answer[2], arr_Answer[3]);

	return AnswerInput();
}

void Question(STRUCT_Question* _question)
{
	//printf("실행하는 퀘스트 : %s");
	bool isQuestionEnd = false;
	while (!isQuestionEnd) // 퀘스트 끝 아닐 때만
	{
		if (_question->curQuestionCount == 3) // 다음 문제 카테고리로 이동
		{
			_question->_result[_question->curQuestionCount] = GetAnswer(string_Question[curQuest][_question->curQuestionCount]);
			_question->ChaneScore(); // 점수 치환

			curQuest += 1;
			isQuestionEnd = true;

			printf("다음 문제카테고리를 진행합니다\n");
			Sleep(1000);

			break;
		}
		else
		{
			//printf("\n%s", string_Question[curQuest][_question->curQuestionCount]);
			_question->_result[_question->curQuestionCount] = GetAnswer(string_Question[curQuest][_question->curQuestionCount]);
			_question->curQuestionCount += 1;
			continue;
		}
	}
	printf("\n\nQuestion 함수 탈출.");
}
void ResultPrint(char a, char b, char c, char d)
{
	printf("\n결과 출력\n");
	MBTI[0] = a;
	MBTI[1] = b;
	MBTI[2] = c;
	MBTI[3] = d;
	printf("\n\n\n 당신의 MBTI는 : %s", &MBTI);

	if (strcmp(MBTI, "ISTJ") == 0)
	{
		printf("\n당신의MBTI와 같은 사람은 퓨디파이");
	}
}
void Intro()
{
	printf("▣ MBTI테스트 만들기 ▣ \n");
}
int main()
{
	Intro();
	STRUCT_Question* ie; // 내향 / 외향
	STRUCT_Question* sn; // 감각 / 직관
	STRUCT_Question* tf; // 사고 / 감성
	STRUCT_Question* jp; // 판단 / 인식
	ie = (STRUCT_Question*)malloc(sizeof(STRUCT_Question));
	sn = (STRUCT_Question*)malloc(sizeof(STRUCT_Question));
	tf = (STRUCT_Question*)malloc(sizeof(STRUCT_Question));
	jp = (STRUCT_Question*)malloc(sizeof(STRUCT_Question));
	curQuest = 0;
	ie->QuestionInit();
	sn->QuestionInit();
	tf->QuestionInit();
	jp->QuestionInit();


	Question(ie);
	Question(sn);
	Question(tf);
	Question(jp);


	

	ResultPrint(
		ie->ProduceResult('I', 'E'), 
		sn->ProduceResult('S', 'N'),
		tf->ProduceResult('T', 'F'),
		jp->ProduceResult('J', 'P')
		);
	return 0;
}



