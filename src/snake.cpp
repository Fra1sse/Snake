

#include "snake.h"

void Snake::Setup()
{
	game = true;
	dir = stop; //направление
	width = 11;
	height = 11;
	x = width / 2;
	y = height / 2;
	fruitX = rand() % width;
	fruitY = rand() % height;
	points = 0; //очки
	ntail = 0;
}

void Snake::Fruit()
{
	fruitX = rand() % width;
	fruitY = rand() % height;

	if (fruitX == x && fruitY == y) Fruit();
	else for (int i = 0; i < ntail; i++) {
		if (tailX[i] == fruitX && tailY[i] == fruitY) Fruit();
	}
}

void Snake::Draw() {


	system("cls");
	for (int i = 0; i < width + 2; i++)
		std::cout << "#";
	std::cout << std::endl;

	for (int i = 0; i < height; i++) {
		for (int j = 0; j < width + 2; j++) {
			if (j == 0 || j == width + 1)
				std::cout << "#";
			else if (i == y && j == x)
				std::cout << "O";
			else if (i == fruitY && j == fruitX)
				std::cout << "F";
			else {
				bool print = false;
				for (int k = 0; k < ntail; k++) {
					if (tailY[k] == i && tailX[k] == j) {
						std::cout << "o";
						print = true;
					}
				}
				if (!print)
					std::cout << " ";
			}
		}
		std::cout << std::endl;
	}

	for (int i = 0; i < width + 2; i++)
		std::cout << "#";
	std::cout << std::endl;

	std::cout << "Points" << points << std::endl;
}

void Snake::Control() {
	if (_kbhit()) {
		switch (_getch()) {
		case 'w':
			dir = up;
			break;
		case 's':
			dir = down;
			break;
		case 'd':
			dir = right;
			break;
		case 'a':
			dir = left;
			break;
		case 'x':
			game = false;
			break;
		default:
			break;
		}
	}
}


void Snake::Logic() {
	int prevX = tailX[0];
	int prevY = tailY[0];
	int prev2X, prev2Y;
	tailX[0] = x;
	tailY[0] = y;
	for (int i = 1; i < ntail; i++) {
		prev2X = tailX[i];
		prev2Y = tailY[i];
		tailX[i] = prevX;
		tailY[i] = prevY;
		prevX = prev2X;
		prevY = prev2Y;
	}
	switch (dir) {
	case left:
		x--;
		break;
	case right:
		x++;
		break;
	case up:
		y--;
		break;
	case down:
		y++;
		break;
	default:
		break;
	}

	if (x < 0 || x > width - 1 || y < 0 || y > height - 1) {
		game = false;
	}

	for (int i = 0; i < ntail; i++) {
		if (tailX[i] == x && tailY[i] == y)
			game = false;
	}

	if (fruitX == x && fruitY == y) {
		points += 10;
		ntail++;
		Fruit();
	}
}
