#include <stdio.h>
#include <time.h>
#include <Windows.h>
#include "snake.h"

int main() {
	srand(time(0));
	CONSOLE_CURSOR_INFO cci;
	cci.bVisible = FALSE;	//取消光标 
	cci.dwSize = sizeof(cci);
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE),&cci);	
	init_wall();
	init_food();
	init_snake();
	play();
	return 0;
}
