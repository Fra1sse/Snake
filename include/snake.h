#pragma once


#include <iostream>
#include <conio.h>
#include <windows.h>

class Snake {
public:
	void Setup();
	void Fruit();
	void Draw();
	void Control();
	void Logic();

	bool game;
private:


	enum sides { stop = 0, left, right, up, down };
	sides dir;
	int x, y;
	int width, height;
	int fruitX, fruitY;
	int points;
	int tailX[121], tailY[121], ntail;
};