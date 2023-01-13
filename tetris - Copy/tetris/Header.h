

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

// 배열의 정의 순서 displayData[3][2] 이라면 이런 순서로 된다.
/*
	14
	25
	36
*/