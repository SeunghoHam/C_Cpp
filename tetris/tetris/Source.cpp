#include"Header.h"

#define INTERVAL 1.0/60.0
int main()
{
	srand(time(0)); // 퍼포먼스를 위해 매번 하는것보다 시작시에 한번 하는게 좋음
	float prev = (float)clock() / CLOCKS_PER_SEC;
	Display* display = new Display();
	GameEngine* _gameEngine = new GameEngine();
	_gameEngine->init();

	showConsoleCursor(false);

	while (true)
	{
		float curr = (float)clock() / CLOCKS_PER_SEC;
		float dt = curr - prev;

		if (dt < INTERVAL) continue;
		prev = curr;

		

		bool left = keyState('a');
		bool right = keyState('d');
		bool down = keyState('s');
		if (left)
		{
			// TODO : 왼쪽 클릭
			_gameEngine->next(dt, 'a');
		}
		else if(right)
		{
			_gameEngine->next(dt, 'd');
			// TODO : 그냥 떨어짐
		}
		else if (down)
		{
			_gameEngine->next(dt, 's');
		}
		else
		{
			_gameEngine->next(dt, 0);
		}
		// 화면출력

		_gameEngine->next(dt,0);
		_gameEngine->makeDisplayData();
		display->draw();

		if (_gameEngine->state == GameEngine::GameState::GAMEOVER)
		{
			break;
		}

		// 게임 상태 판별
		
	}
	return 0;
}

