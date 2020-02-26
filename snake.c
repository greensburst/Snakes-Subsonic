#include <stdio.h>
#include <Windows.h>
#include <conio.h>
#include "snake.h"

SNAKE 	snake;
FOOD 	food;
int dx = 0;
int dy = 0;
int tailx = 0;
int taily = 0;

void init_food() {
	
	food.x = rand() % (WIDTH) + 1;
	food.y = rand() % (HEIGHT) + 1;
}

void init_snake() {
	
	snake.size = 5;
	
	for(size_t i = 0; i < 5; i++) {
		snake.body[i].x = WIDTH / 2 + i;
		snake.body[i].y = HEIGHT / 2;
	}
}

void init_wall() {
	
	for(size_t y = 0; y <= HEIGHT+1; y++) {
		for(size_t x = 0; x <= WIDTH+1; x++) {
			if(x == 0 || x == WIDTH+1 || y == HEIGHT+1 || y == 0) {
				printf("=");
			} else {
				printf(" ");
			}
		}
		printf("\n");
	}
}

void show() {
	
	COORD coord = {food.x, food.y};	//存放光标位置
	
	//光标定位 
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coord);
	putchar('#'); 
	
	for(size_t i = 0; i < snake.size; i++) {
		coord.X = snake.body[i].x;
		coord.Y = snake.body[i].y;
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coord);
		i ? putchar('*') : putchar('@');
	}
	
	coord.X = tailx;
	coord.Y = taily;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coord);
	putchar(' ');
}

void play() {
	
	char ctrl = 'A';
	
	while(snake.body[0].x >= 1 && snake.body[0].x <= WIDTH && snake.body[0].y >= 1 && snake.body[0].y <= HEIGHT) {
		for(size_t i = 1; i < snake.size; i++) {
			if(snake.body[0].x == snake.body[i].x && snake.body[0].y == snake.body[i].y) {
				return;
			}
		}
		
		if(snake.body[0].x == food.x && snake.body[0].y == food.y) {
			snake.size++;
			init_food();
		}
		
		if(_kbhit()) {	//判断按键是否按下 
			ctrl = _getch();
		}	
		
		switch(ctrl) {
			case 'w':
			case 'W':
				dx = 0;
				dy = -1;
				break;
			case 'a':
			case 'A':
				dx = -1;
				dy = 0;
				break;
			case 's':
			case 'S':
				dx = 0;
				dy = 1;
				break;
			case 'd':
			case 'D':
				dx = 1;
				dy = 0;
				break;
		}
		
		tailx = snake.body[snake.size-1].x;
		taily = snake.body[snake.size-1].y;
		
		for(size_t i = snake.size - 1; i > 0; i--) {
			snake.body[i].x = snake.body[i-1].x;
			snake.body[i].y = snake.body[i-1].y;
		}
		snake.body[0].x += dx;
		snake.body[0].y += dy;
		
		show();
		
		Sleep(500);
	}
}
