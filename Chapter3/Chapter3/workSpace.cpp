#include"Header.h"
#define INTERVAL 1.0/60.0
#define INTERVAL2 0.016f


int main()
{
	
	float prev = (float)clock() / CLOCKS_PER_SEC;
	Display* display = new Display();
	GameEngie* gameEngine = new GameEngie();
	showConsoleCursor(false);
	//printf("INTERVAL : %.2f", INTERVAL);
	srand(time(0));

	gameEngine->init();
	while (true)
	{
		float curr = (float)clock() / CLOCKS_PER_SEC;
		float delta = curr - prev;
		// curr 이 커짐으로 인해서 delta의 값도 커짐

		//printf("조건 실행 전\n");
		if (delta < INTERVAL)continue; // 1 / 60 초마다 구문이 실행되게 한다.
		//printf("고고");
		prev = curr;
		
		bool left = keyState('a');
		bool right = keyState('d');
		bool down = keyState('s');

		if (left)
		{
			// 왼쪽으로 블록 이동
			gameEngine->next(delta, 'a');
		}	
		else if(right)
		{
			gameEngine->next(delta, 'd');
			// 블록 아래로 떨어짐(자동)
		}
		else if (down)
		{
			gameEngine->next(delta, 's');
		}
		else
		{
			gameEngine->next(delta, 0);
		}

		// 화면 출력
		gameEngine->makeDisplayData();
		display->draw();
		
		//if (gameEngine->state ==)// 게임종료 받아와야함
		{
			//break;
		}

		// 게임 상태 판단
	}
	return 0;
}