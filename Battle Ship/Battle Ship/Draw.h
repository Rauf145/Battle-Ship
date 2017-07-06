#pragma once
#include <iostream>
using namespace std;
enum Colors
{
	BLACK,
	DARKBLUE,
	DARKGREEN,
	DARKCYAN,
	DARKRED,
	DARKMAGENTA,
	BROWN,
	LIGHTGREY,
	GREY,
	BLUE,
	GREEN,
	CYAN,
	RED,
	MAGENTA,
	YELLOW,
	WHITE
};

#define COLOR(foreground, background) SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), background * 16 + foreground)
#define COORDS(row, col) SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { (short)col, (short)row })
#define RAND(min, max) rand() % (max - min + 1) + min

template <typename T> void drawData(T data, Colors c1, Colors c2, int row = -1, int col = -1)
{
	COLOR(c1, c2);
	if (row >= 0 && col >= 0)
	{
		COORDS(row, col);
	}
	cout << data;
	COLOR(LIGHTGREY, BLACK);
}

void draw(int row, int col, int height, int width, Colors c)
{
	COLOR(c, c);
	for (size_t i = row; i < row + height; i++)
	{
		for (size_t j = col; j < col + width; j++)
		{
			if (i == row || i == row + height - 1 || j == col || j == col + width - 1)
			{
				COORDS(i, j);
				cout << ' ';
			}
		}
	}
	COLOR(LIGHTGREY, BLACK);
}


