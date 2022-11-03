#pragma once
#pragma warning(disalbe:4996)
#include"TetrisHelper.h"
#include<cstring>
#include<ctime>
#include<cmath>
#include<cstdlib>

// 시스템 추상화
#define GRID_WIDTH 7
#define GRID_HEIGHT 10
#define USERBLOCK_SIZE 3 


// 전역변수로 선언 
int displayData[GRID_HEIGHT][GRID_WIDTH]{ 0, }; // 배열 초기화 [줄][내용]. [y][x]

class Display
{
public:
	void draw()
	{
		for (int i = 0; i < GRID_HEIGHT; i++)
		{
			for (int k = 0; k < GRID_WIDTH; k++)
			{
				if (displayData[i][k] == 0) // 비어있다면
				{
					drawPosition(k, i, false);
				}
				else
					drawPosition(k, i, true);

				// ↓ 짧게쓰기
				// drawPosition(k, i, displayData[i][k] == 1);// GRID 중 0으로 할당되어있는 공간
				// displayData[i][k] ==1 : true /// displayData[i][k] == 0 : false


			}
		}
	}
};

class GameEngie // 게임데이터의 그리드(배열)관리, 사용자블록 관리
{
public:
	enum class GameState
	{
		PLAYING, GAMEOVER
	};
	GameState state = GameState::PLAYING;

	int gameGridData[GRID_HEIGHT][GRID_WIDTH] = // 게임 맵
	{
		{0,0,0,0,0,0,0,},
		{0,0,0,0,0,0,0,},
		{0,0,0,0,0,0,0,},
		{0,0,0,0,0,0,0,},
		{0,0,0,0,0,0,0,},
		{0,0,0,0,0,0,0,},
		{0,0,0,0,0,0,0,},
		{0,0,0,0,0,0,0,},
		{1,1,1,0,0,0,0,},
		{1,1,1,1,1,1,1,},
	};
	int userBlock[USERBLOCK_SIZE][USERBLOCK_SIZE] = // 현재 블록모양 정의
	{ 0,
	};

	int userBlockVarious[3][USERBLOCK_SIZE][USERBLOCK_SIZE] =
	{
		{
		{0,1,0,},
		{0,1,0},
		{0,1,0},
		},
		{
			{0,0,0,},
			{0,1,1,},
			{0,1,1,},
			},
		{
			{0,0,0,},
			{0,1,0,},
			{1,1,0,},
		},
	};
		// userBlock이 어느 위치에 있는지에 대한 y 좌표가 필요함
	int blockX = 0;
	int blockY = 0;

	float elapsed = 0.0f;
	float controlCheck = 0.0f;
	void init() // GameEngine 초기화
	{

	}

	// next는 while 루프에서 매번 불려지는 함수. 1/60 초 마다 실행됨
	void next(int _delta, char _keyboardInput)
	{
		if (state == GameState::GAMEOVER)
			return;
		// 블록을 계속 떨어뜨려야함
		elapsed += _delta;
		if (elapsed >= 0.5f)
		{
			if (canGoDown())
			{
				blockY++;
				if (gameOverDecision()) state == GameState::GAMEOVER;
			}
			else
			{
				// userBlock 을 gameGridData에 전사하면 된다.
				trans();
			}
			elapsed = -0.5f;
		}

		controlCheck = controlCheck + _delta;
		if (_keyboardInput == 'a' && canGoLeft() && controlCheck > 0.1f)
		{
			blockX--;
			controlCheck = 0.0f;
		}
		if (_keyboardInput == 'd' && canGoRight() && controlCheck > 0.1f)
		{
			blockX++;
			controlCheck = 0.0f;
		}
		if (_keyboardInput == 's' && canGoDown() && controlCheck > 0.1f)
		{
			blockY++;
			controlCheck = 0.0f;
		}
	}

	// 블록이 아래로 내려갈 수 있냐
	bool canGoDown()
	{
		for (int i = 0; i < USERBLOCK_SIZE; i++)
		{
			for (int k = 0; k < USERBLOCK_SIZE; k++)
			{
				if (userBlock[i][k] == 1 && // 이동하려는 칸에 블록이 존재하고 있다.
					i + blockY + 1 >= GRID_HEIGHT) // 현재 블록의 Y축 위치의 다음 칸(i + blockY + 1) 이 맵의 끝이다.
				{
					return false;

					if (userBlock[i][k] == 1 //
						&& gameGridData[i + blockY + 1][k + blockX] == 1)
					{
						return false;
					}
				}
				else
					// 아랫칸에 블록이 없거나, 맵의 끝이 아니다.
					return true;
			}
		}

	}

	bool canGoLeft()
	{
		for (int i = 0; i < USERBLOCK_SIZE; i++)
		{
			for (int k = 0; k < USERBLOCK_SIZE; k++)
			{
				if (userBlock[i][k] == 1 &&
					k + blockX - 1 < 0) // 좌로 이동 불가
					return false;

				if (userBlock[i][k] == 1
					&& gameGridData[i + blockY][k + blockX - 1] == 1) // 
					return false;

			}
		}
		return true;
	}
	bool canGoRight()
	{
		for (int i = 0; i < USERBLOCK_SIZE; i++)
		{
			for (int k = 0; k < USERBLOCK_SIZE; k++)
			{
				if (userBlock[i][k] == 1 &&
					k + blockX + 1 > GRID_WIDTH - 1) // 우로 이동 불가
					return false;

				if (userBlock[i][k] == 1
					&& gameGridData[i + blockY][k + blockX + 1] == 1) // 
					return false;

			}
		}
		return true;

	}

	bool isLineFilled(int y)
	{
		for (int i = 0; i < GRID_WIDTH; i++)
		{
			if (gameGridData[y][i] == 0)return false;
		}
		return true;
	}
	void eraseLine(int y)
	{
		for (int i = 0; i < GRID_WIDTH; i++)
		{
			gameGridData[y][i] = 0;
		}
	}

	// y 좌표를 기준으로 한 칸씩 아래로 내림
	void drop(int y)
	{
		for (int i = y; i >= 0; i--) // 아래칸 부터 시작하여 한 칸 씩 내려야한다.
		{
			for (int k = 0; k < GRID_WIDTH; k++)
			{
				gameGridData[i][k] = i - 1 < 0 ? 0 : gameGridData[i - 1][k];
			}
		}
	}
	// userblock을 gameGrid에 전사하는 함수
	void trans()
	{
		for (int i = 0; i < USERBLOCK_SIZE; i++)
		{
			for (int k = 0; k < USERBLOCK_SIZE; k++)
			{
				// makeDispalyData 처럼 최적화가 가능.
				gameGridData[i + blockY][k + blockX] =
					userBlock[i][k] == 1 ?
					userBlock[i][k] : gameGridData[i + blockY][k + blockX];
			}
		}
		// TODO : 한 줄일 가득 차 있는지 확인
		for (int i = 0; i < GRID_HEIGHT; i++)
		{
			if (isLineFilled(i))
			{
				eraseLine(i);
				drop(i);
			}
		}
		// 새로운 블록생성
		makeUserBlock();

	}


	bool gameOverDecision()
	{
		for (int i = 0; i < USERBLOCK_SIZE; i++)
		{
			for (int k = 0; k < USERBLOCK_SIZE; k++)
			{
				if (userBlock[i][k] == 1 && gameGridData[i + blockY][k + blockX] == 1)
				{
					return true; // 게임오버
				}
			}
		}
		return false;
	}
	void makeUserBlock()
	{
		blockX = GRID_WIDTH /2 - USERBLOCK_SIZE/2;
		blockY = 0;



		int various = rand() % 3;
		for (int i = 0; i < USERBLOCK_SIZE; i++)
		{
			for (int k = 0; k < USERBLOCK_SIZE; k++)
			{
				userBlock[i][k] = userBlockVarious[various][i][k];
			}
		}
		// TODO : 랜덤을 통해서 새로운 블록을 만든다.

	}

	//displayData로 gameGridData를 전산해주는 작업
	// 실제 게임 데이터를 화면에 출력할 수 있는 데이터로 교체
	void makeDisplayData()
	{
		// 현재 상태. 블록이 어떻게 차 있는지
		for (int i = 0; i < GRID_HEIGHT; i++)
		{
			for (int k = 0; k < GRID_WIDTH; k++)
			{
				displayData[i][k] = gameGridData[i][k]; // 초기화에서는 기존 gridData를 받아온다.
			}
		}

		for (int i = 0; i < USERBLOCK_SIZE; i++)
		{
			for (int k = 0; k < USERBLOCK_SIZE; k++)
			{
				if (i + blockY < 0  // userblock중에서 y좌표의 위치가 0보다 작음. 그리드보다 위에 존재함 (배열사이즈를 넘어감) 
					|| i + blockY > GRID_HEIGHT) // 그리드의 최대 크기보다 큼 (배열사이즈를 넘어감)
				{
					// DO NOTHING
				}
				else if (k + blockX < 0 || k + blockX > GRID_WIDTH)
				{
					// DO NOTHING
				}
				else
				{
					// CONDITION : 기존 블록과 현재 블록이 만났다
					// BECAUSE : userBlock 의 0부분을 gameGridData의 1 부분이어도 0으로 바꿔버리니까, 맵이 파괴됨
					// TODO:
					int _x = k + blockX;
					int _y = i + blockY;

					displayData[_y][_x] = userBlock[i][k] == 1 ? userBlock[i][k] : displayData[_y][_x];
					// 해당구문을 | 연산자로 짧게 해결할 수 있다.
					// | 연산자 : 비트 OR ( 하나라도 1이라면 1을 반환함) Bitwise
					// -> displayData[][] 가 1이라면 앞 구문을, 0이라면 뒷 구문을 실행한다.
					//displayData[_y][_x] = userBlock[i][k] | displayData[_y][_x]; // 이런식의 코드가 더 빠름
				}
			}
		}
	}
};