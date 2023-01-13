#include<cstdio>
#include<cmath>

void foo(int param);
int main()
{
	/*
	비트와이즈 연산 : 비트를 기준으로 논리연산 하는것.

		비트와이즈and : &연산자
		비트와이즈 or : | 연산자 활용
		왼쪽 쉬프트 : << 이항연산자 활용 [ 왼쪽으로 한 칸씩 비트이동, 0은 무시 ]
		오른쪽 쉬프트 : >> 이항연산자 활용[ 오른쪽으로 한 칸씩 비트이동 ]


		비트와이즈 연산을 왜 해야하는가?
		컴퓨터는 기본적으로 비트와이즈 연산을 베이스로 사칙연산을 한다. → 더 빠름
			ex) 쉬프트 연산 : "<< n":  n 만큼 2를 곱한 값, " >> n " : n 만큼 0.5를 곱한 값


		비트와이즈는 카테고리를 선별해내기 위해 많이 사용한다.
		int = 32비트. 비트 하나하나에 할당해줄 수 있음. ex) Unity Layer 같이 레이어 구분하는거
		*/

	int v1 = 1; // 0001
	int v2 = 3; // 0011

	//(or = 둘 중 하나라도 true 라면 true반환)
	int bitwise_or = v1 | v2;
	//~result(bitwise_or) = 3 (int 형을 4비트로 가정 int = 32bit)
	//각 비트마다 or 연산을 하여[0, 0, 1, 1] 의 값이 된다.

	int bitwise_and = v1 & v2;

	int shift_left = v2 << 1; // 0110  = 6
	int shift_right = v2 >> 1; // 0001 = 1

	printf("Bitwise_or : %d\n", bitwise_or);
	printf("Bitwise_and : %d\n", bitwise_and);
	printf("shift_left : %d\n", shift_left);
	printf("shift_right : %d\n", shift_right);

	
	// 충돌 레이어 [ 적, 지형지물, 적, X안씀 ]
	int mario_category = 8 + 4 + 2 + 1; // [ 1, 1, 1, 1 ] 
	int enemy_category = 0 + 4 + 2 + 1; // [ 0, 1, 1, 1 ]
	int ghost_category = 0 + 0 + 2 + 1; // [ 0, 0, 1, 1 ]
	int terrain_category = 0 + 4 + 0 + 0; // [0, 1, 1, 0 ]


	foo(1 | 2 | 4); // 이러면 다 들어가네?


	// 만약 mario 와 enemy 가 충돌을 함 ( and 연산 ) 
	// 결과 : 1이 나옴 충돌. true

	// 만약 ghost와 terrain 이 충돌을 함
	// 결과 : 0이 나옴. 충돌 fasle
	return 0;
}


// 비트와이즈 연산의 응용
// 파라미터로 받은 int 가 여러 카테고리를 받는다는 가정
void foo(int param)
{
	int category1 = 1;
	int category2 = 1 << 1;
	int category3 = 1 << 2;

	if ((category1 & param) != 0) // param이랑 비트와이즈and 연산 한 값이 0이 아니다 = 둘다 1 이어야 1
	{
		printf("카테고리 1에 포함\n");
	}
	if ((category2 & param) != 0)
	{
		printf("카테고리 2에 포함\n");
	}
	if ((category3 & param) != 0)
	{
		printf("카테고리 3에 포함\n");
	}
}