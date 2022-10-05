#include"Header.h"
#define INTERVAL 1.0/60.0 // 0.016초(60)프레임을 만들기 위해서
#define INTERVAL2 0.016f


int main()
{
	
	float prev = (float)clock() / CLOCKS_PER_SEC;
	Display* display = new Display();
	GameEngie* gameEngine = new GameEngie();
	showConsoleCursor(false);

	//printf("INTERVAL : %d", INTERVAL);
	while (true)
	{
		float curr = (float)clock() / CLOCKS_PER_SEC;
		float delta = curr - prev;
		// curr 이 커짐으로 인해서 delta의 값도 커짐

		//printf("조건 실행 전\n");
		if (delta < INTERVAL)continue; // 1 / 60 초마다 구문이 실행되게 한다.
		
		//printf("조건 실행 후\n");
		prev = curr;
		
		
		//print("%.3f", curr);
		
		bool left = keyState('a');
		bool right = keyState('d');

		if (left)
		{
			// 왼쪽으로 블록 이동
		
		}
		else
		{
			// 블록 아래로 떨어짐(자동)
		}
		gameEngine->next(delta, 0);

		// 화면 출력
		gameEngine->makeDisplayData();
		display->draw();
		
		// 게임 상태 판단
	}
	return 0;
}