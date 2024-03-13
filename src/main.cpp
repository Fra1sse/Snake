#include "snake.h"

#include <iostream>
#include <conio.h>
#include <windows.h>

void main() {
	

	Snake game;

	game.Setup();
	while (game.game) {
		game.Draw();
		game.Control();
		game.Logic();
		Sleep(500);
	}

}