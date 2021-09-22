#include<iostream>
#include<conio.h>
#include "Pacman.h"
#include "Fantasma.h"
#include "Pacdots.h"
#include "Bonus.h"
#include "Controller.h"

using namespace std;
using namespace System;

int main() {
	srand(time(NULL));
	Console::SetWindowSize(152, 42);
	char key;
	int temporizador;
	temporizador = 0;
	bool ganador;
	Controller* controller = new Controller();
	controller->dibujarTodo();

	while (true)
	{
		Console::CursorVisible = false;

		controller->borrarTodo();
		controller->colision();

		if (controller->getPacman()->getVida() == 0)
		{
			ganador = false;
			break;
		}
		if (controller->getNumDots() == 0)
		{
			ganador = true;
			break;
		}


		controller->moverFantasmas();
		if (_kbhit())
		{
			key = _getch();
			key = toupper(key);
			controller->getPacman()->mover(key);
		}

		controller->dibujarTodo();
		_sleep(100);
		temporizador++;
		if (temporizador == 1200)
		{
			ganador = false;
			break;
		}

	}
	Console::Clear();
	switch (ganador)
	{
	case true:
		cout << "Ganaste :D" << "\n";
		cout << "Puntuacion: " << controller->getPuntos() << "\n";
		break;
	case false:
		cout << "Perdiste T_T" << "\n";
		cout << "Puntuacion: " << controller->getPuntos() << "\n";
		break;
	}

	_getch();
	return 0;
}