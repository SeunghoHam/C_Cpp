

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

// �迭�� ���� ���� displayData[3][2] �̶�� �̷� ������ �ȴ�.
/*
	14
	25
	36
*/