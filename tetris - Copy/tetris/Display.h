#ifndef __DISPLAY_H__
#define __DISPLAY_H_


#include"Header.h"


extern int displayData[GRID_HEIGHT][GRID_WIDTH] = { 0, };
class Display
{
public:
	void draw()
	{
		for (int i = 0; i < GRID_HEIGHT; i++)
		{
			for (int k = 0; k < GRID_WIDTH; k++)
			{
				drawPosition(k, i, displayData[i][k] == 1);  // displayData[i][k] == 1 일때 true 를 반환한다.
			}
		}
	}
};

#endif // !__DISPLAY_H__
