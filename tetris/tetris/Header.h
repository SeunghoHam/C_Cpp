#define CRT_SECURE_NO_WARNINGS_

#include "TetrisHelper.h"
#include<cstdio>
#include<cstdlib>
#include<ctime>
#include<cstring>
#include<cmath>

#define GRID_WIDTH 7
#define GRID_HEIGHT 10
#define USERBLOCK_SIZE 3

int displayData[GRID_HEIGHT][GRID_WIDTH] = { 0, };

// 2번째 영상 16:35부터

// 배열의 정의 순서 displayData[3][2] 이라면 이런 순서로 된다.
/*
	14
	25
	36
*/

class Display
{
public:
	void draw()
	{
		for (int i = 0; i < GRID_HEIGHT; i++)
		{
			for (int k = 0; k < GRID_WIDTH; k++)
			{
				drawPosition(k, i, displayData[i][k] == 1);  // displayData[i][k] == 1 일대 true 를 반환한다.
			}
		}
	}
};

class GameEngine
{
public:
	enum class GameState
	{
		PLAYING, GAMEOVER,
	};
	GameState state = GameState::PLAYING;

	int gameGridData[GRID_HEIGHT][GRID_WIDTH] = {
		{0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0},
	};
	int userBlock[USERBLOCK_SIZE][USERBLOCK_SIZE] = {0, };
	int userBlockVarious[3][USERBLOCK_SIZE][USERBLOCK_SIZE] =
	{
		{
			{0,1,0},
			{0,1,0},
			{0,1,0}
		},
		{
			{0,0,0},
			{0,1,1},
			{0,1,1}
		},
		{
			{0,0,0},
			{0,1,0},
			{1,1,0}
		},

	};
	int blockX = 0; // userBlock의 x 좌표값
	int blockY = 0; // userBlock의 y 좌표값

	float elapsed = 0.0f;
	float controlCheck;
	void init()
	{
		// GameEngine초기화
		makeUserBlock();
	}

	void next(float dt, char keyboardInput) // while루프에서 매번 불려지는 함수.
	{
		if (state == GameState::GAMEOVER) return;
		elapsed += dt;
		if (elapsed >= 0.5f)
		{
			if (canGoDown())
			{
				blockY++;
			}
			else
			{
				// userblock을 gameGridData에 전사
				transcription();
				if (gameOverDecision())
				{
					state == GameState::GAMEOVER;
				}
			}

			elapsed -= 0.5f;
		}
		controlCheck += dt;

		if (keyboardInput == 'a' && canGoLeft() && controlCheck > 0.1f)
		{
			blockX--;
			controlCheck = 0.0f;
		}
		if (keyboardInput == 'd' && canGoRight() && controlCheck > 0.1f)
		{
			blockX++;
			controlCheck = 0.0f;
		}
		if (keyboardInput == 's' && controlCheck > 0.1f)
		{
			blockY++;
			controlCheck = 0.0f;
		}
	}

	bool canGoDown() // 내려갈 수 있나.
	{
		for (int i = 0; i < USERBLOCK_SIZE; i++)
		{
			for (int k = 0; k < USERBLOCK_SIZE; k++)
			{
				if (userBlock[i][k] == 1 && i + blockY + 1 >= GRID_HEIGHT)
					return false;
				if (userBlock[i][k] == 1 && gameGridData[i + blockY + 1][k + blockX] == 1)
					return false;
				//else return true;
			}
		}
	}
	bool canGoLeft()
	{
		for (int i = 0; i < USERBLOCK_SIZE; i++)
		{
			for (int k = 0; k < USERBLOCK_SIZE; k++)
			{
				if (userBlock[i][k] == 1 && k + blockX - 1 < 0) // 전체 스크린 범위 지정
					return false;
				if (userBlock[i][k] == 1 && gameGridData[i + blockY][k + blockX - 1] == 1) // 전사되어있는 블럭으로 인한 범위지정
					return false;
			}

		}
		return true;

		
	bool canGoRight()
	{
		for (int i = 0; i < USERBLOCK_SIZE; i++)
		{
			for (int k = 0; k < USERBLOCK_SIZE; k++)
			{
				if (userBlock[i][k] == 1 && k + blockX + 1 > GRID_WIDTH - 1) // 전체 스크린 범위 지정
					return false;
				if (userBlock[i][k] == 1 && gameGridData[i + blockY][k + blockX + 1] == 1) // 전사되어있는 블럭으로 인한 범위지정
					return false;
			}
		}

		return true;
	}

	bool isLineFilled(int y) // 현재 라인이 1로 꽉 차있는지 검사
	{
		for (int i = 0; i < GRID_WIDTH; i++)
		{
			if (gameGridData[y][i] == 0)return false; // 현재 y좌표의 줄에 0이 있다면 바로 false반환
		}
		return true;
	}

	void eraseLine(int y) // 라인 지우기
	{
		for (int i = 0; i < GRID_WIDTH; i++)
		{
			gameGridData[y][i] = 0;

		}
	}
	// y 좌표를 기준으로 한 칸씩 아래로 내림
	void drop(int y)
	{
		for (int i = y; i >= 0; i--) // 좌표계는 좌측상단이 ( 0 , 0 ) 이어서 y 부터 시작해서 한 칸씩 내려야 한다. 0부터 시작하게 되면 복사, 할당이 반복됨
		{
			for (int k = 0; k < GRID_WIDTH; k++)
			{
				gameGridData[i][k] = i - 1 < 0 ? 0 : gameGridData[i - 1][k];
			}
		}
	}
	void transcription() // userBlock 을 gameGrid에 전사하는 함수
	{
		for (int i = 0; i < USERBLOCK_SIZE; i++)
		{
			for (int k = 0; k < USERBLOCK_SIZE; k++)
			{
				//makeDisplayData 처럼 최적화 가능
				int _x = k + blockX;
				int _y = i + blockY;
				gameGridData[_y][_x] = userBlock[i][k] | gameGridData[_y][_x];
			}
		}
		// 한 줄이 가득 차 있는지 확인
		for (int i = 0; i < GRID_HEIGHT; i++)
		{
			if (isLineFilled(i))
			{
				eraseLine(i);
				drop(i);
			}
		}
		// 새로운 블록 생성
		makeUserBlock();
	}

	bool gameOverDecision()
	{
		for (int i = 0; i < USERBLOCK_SIZE; i++)
		{
			for (int k = 0; k < USERBLOCK_SIZE; k++)
			{
				if (userBlock[i][k] == 1 && gameGridData[i + blockY][k+blockX] == 1)
				{
					return false;
				}
			}
		}
	}

	void makeUserBlock()
	{
		blockX = GRID_WIDTH /2 - USERBLOCK_SIZE/ 2; // 정 중앙
		blockY = 0;
		// TODO 랜덤을 통해서 새로운 블록 제작

		int various = rand() % 3;
		for (int i = 0; i < USERBLOCK_SIZE; i++) {
			for (int k = 0; k < USERBLOCK_SIZE; k++)
			{
				userBlock[i][k] = userBlockVarious[various][i][k];
			}
		}
	}
	// 실제 게임 데이터를 화면에 출력할 수 있는 데이터로 변경
	void makeDisplayData()
	{
		for (int i = 0; i < GRID_HEIGHT; i++)
		{
			for (int k = 0; k < GRID_WIDTH; k++)
			{
				displayData[i][k] = gameGridData[i][k];
			}
		}

		for (int i = 0; i < USERBLOCK_SIZE; i++)
		{
			for (int k = 0; k < USERBLOCK_SIZE; k++)
			{
				// i = userBlock 의 사이즈, blockY = userBlock의 y좌표
				if (i + blockY < 0 || i + blockY > GRID_HEIGHT)
				{
					// DONOTHING
				}
				else if (k + blockX <0 || k + blockX> GRID_WIDTH)
				{
					// DONOTHING
				}
				else
				{
					// TODO : GridData 지워지지 않게 하기
					//displayData[i + blockY][k + blockX] = userBlock[i][k]; // userBlock 자체를 그대로 넣는 것이기 때문에, 이미 채워져 있는 공간이 있어도 userBlock에서 비어있다면 비어있게 된다.
					//displayData[i + blockY][k + blockX] = userBlock[i][k] == 1 ? userBlock[i][k] : displayData[i + blockY][k + blockX]; -> 길이 줄이기

					int _x = k + blockX;
					int _y = i + blockY;
					displayData[_y][_x] = userBlock[i][k] | displayData[_y][_x];
				}
			}
		}
	}
};