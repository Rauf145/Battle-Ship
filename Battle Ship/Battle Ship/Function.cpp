#include <iostream>
#include <time.h>
#include <Windows.h>
#include <conio.h>
#include "Draw.h"

using namespace std;

void ShowConsoleCursor(bool showFlag);
void LogicOfMenu(short move_x);


//void Function()
//{
//
//}

void Drawmenu()
{
	srand(time(0));
	int button = 0;
	short move_x = 12, move_y = 60;
	ShowConsoleCursor(0);
	draw(4, 50, 20, 27, CYAN);
	while (true)
	{
		button = 0;
		COORDS(9, 59);
		COLOR(rand() % 16 + 1, BLACK);
		cout << "BATTLE SHIP";
		COLOR(LIGHTGREY, BLACK);
		COORDS(12, 60);
		if (move_x == 12)
			COLOR(YELLOW, BLACK);
		cout << "New game";	
		COLOR(LIGHTGREY, BLACK);
		COORDS(15, 60);
		if (move_x == 15)
			COLOR(YELLOW, BLACK);
		cout << "Continue";
		COLOR(LIGHTGREY, BLACK);
		COORDS(18, 62);
		if (move_x == 18)
			COLOR(YELLOW, BLACK);
		cout << "Exit";
		COLOR(LIGHTGREY, BLACK);
		COORDS(27, 59);
		COORDS(move_x, move_y);
		if (kbhit())
			button = getch();
	}
}

void LogicOfMenu(short move_x)
{

}

void ShowConsoleCursor(bool showFlag)
{
	HANDLE out = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO     cursorInfo;
	GetConsoleCursorInfo(out, &cursorInfo);
	cursorInfo.bVisible = showFlag; // set the cursor visibility
	cursorInfo.dwSize = 100;
	SetConsoleCursorInfo(out, &cursorInfo);
}