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
				drawPosition(k, i, displayData[i][k] == 1);// GRID 중 0으로 할당되어있는 공간
				// displayData[i][k] ==1 : true /// displayData[i][k] == 0 : false
			}
		}
	}
};

class GameEngie // 게임데이터의 그리드(배열)관리, 사용자블록 관리
{
public:
	int gameGridData[GRID_HEIGHT][GRID_WIDTH] = // 게임 맵
	{ 
		0,0,0,0,0,0,0, 
		 0,0,0,0,0,0,0,
		 0,0,0,0,0,0,0,
		 0,0,0,0,0,0,0,
		 0,0,0,0,0,0,0,
		 0,0,0,0,0,0,0,
		 0,0,0,0,0,0,0,
		 0,0,0,0,0,0,0,
		 0,0,0,0,0,0,0,
		 0,0,0,0,0,0,0,
	};
	int userBlock[USERBLOCK_SIZE][USERBLOCK_SIZE] = // 현재 블록모양 정의
	{	1,1,1,
		0,0,1,
		0,0,1
	};


	// userBlock이 어느 위치에 있는지에 대한 y 좌표가 필요함
	int blockX = 0;
	int blockY = 0;

	float elapsed = 0.0f;

	void init() // GameEngine 초기화
	{

	}
	// next는 while 루프에서 매번 불려지는 함수.
	void next(int _delta, char _keyboardInput)
	{
		// 블록을 계속 떨어뜨려야함
		elapsed += _delta;
		if (elapsed >= 0.5f)
		{
			blockY++;
			//elapsed = 0.0f;
			elapsed = -0.5f;
		}
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
				displayData[i][k] = gameGridData[i][k];
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
					// TODO:
					int _x = k + blockX;
					int _y = i + blockY;

					//displayData[_y][_x] = userBlock[i][k] == 1 ? userBlock[i][k] : displayData[_y][_x];
					// 해당구문을 | 연산자로 짧게 해결할 수 있다.
					// | 연산자 : 비트 OR ( 하나라도 1이라면 1을 반환함) 
					// -> displayData[][] 가 1이라면 앞 구문을, 0이라면 뒷 구문을 실행한다.
					displayData[_y][_x] = userBlock[i][k] | displayData[_y][_x]; // 이런식의 코드가 더 빠름
				}
			}
		}
	}

	void draw()
	{

	}
};