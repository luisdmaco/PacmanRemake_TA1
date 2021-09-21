#include<iostream>
#include<conio.h>
#include "Pacman.h"
#include "Fantasma.h"
#include "Pacdots.h"
#include "Bonus.h"

using namespace std;
using namespace System;

int main() {
	srand(time(NULL));
	Console::CursorVisible = false;
	Console::SetWindowSize(210, 45);
	Pacman* pac; char key;
	pac = new Pacman();
	while (true) {
		pac->borrar();
		key = _getch();
		toupper(key);
		pac->mover(key);
		pac->dibujar();
		_getch();
		_sleep(100);
	}
	return 0;
}