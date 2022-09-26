#include"Header.h"
//#include"Header.cpp"



// Value
int arr_Answer[4] = { -3,-1,1,3 };
int curQuest; // 0 = IE, 1 = SN...
struct Question_I_E
{
	int curQuestionCount; // 몇 번째 문제를 하고 있는지
	int _score;
	void ChaneScore(int i)
	{

	}
};

int GetAnswer()
{
	printf("[%s]\n" , string_Question_I_E_1);
	printf("당신의 해당 점수는 ? :  %d, %d, %d, %d : ",
		arr_Answer[0], arr_Answer[1], arr_Answer[2], arr_Answer[3]); // 이 부분이 문제인가? 값 할당을 하지 않고 실행시켜서?
		//1, 2, 3, 4);

	int _input;
	fseek(stdin, 0, SEEK_END);
	scanf_s("%d", &_input);
	switch (_input)
	{
	case -3:
		printf("\n당신이 선택한 수는 [%d] 입니다", _input);
		
		break;
	case -1:
		printf("\n당신이 선택한 수는 [%d] 입니다", _input);
		break;
	case 1:
		printf("\n당신이 선택한 수는 [%d] 입니다", _input);

		break;
	case 3:
		printf("\n당신이 선택한 수는 [%d] 입니다", _input);
		break;
	default:
		printf("다시 입력해주세요\n");
		break;
	}
	
	return _input;
}

void Question(Question_I_E* _ie)
{
	switch (curQuest) // 현재 어떤 질문 상태인지
	{
	case 0: // I_E
		switch (_ie->curQuestionCount) // 이 단계전에 ie 정보가 없음
		{
		case 0:
			_ie->_score = GetAnswer();
			break;
		case 1:
			break;
		case 2:
			break;
		case 3:
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
int main()
{
	Question_I_E* ie;
	ie = (Question_I_E*)malloc(sizeof(Question_I_E));
	ie->curQuestionCount = 0;
	//GetQuetionInformation();
	//arr_Answer[0] = 1;
	//arr_Answer[1] = 2;
	//arr_Answer[2] = 3;
	//GetAnswer();
	Question(ie);
	//printf("%s", string_Question_I_E_1);
	return 0;
}


