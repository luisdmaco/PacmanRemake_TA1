#pragma once
#define KEY_UP    72
#define KEY_LEFT  75
#define KEY_RIGHT 77
#define KEY_DOWN  80
#include<iostream>
#include<conio.h>
using namespace std;
using namespace System;
using namespace System::Drawing;
class Pacman {
private:
	int largo, ancho;
	int dx, dy;
	int vidas;
	int x, y;
public:
	Pacman() {
		largo = 4;
		ancho = 5;
		dx = 1;
		dy = 1;
		vidas = 3;
		x = 20;
		y = 20;
	};
	~Pacman() {};
	void borrar() {
		Console::SetCursorPosition(x, y); cout << "     ";
		Console::SetCursorPosition(x, y + 1); cout << "     ";
		Console::SetCursorPosition(x, y + 2); cout << "     ";
		Console::SetCursorPosition(x, y + 3); cout << "     ";
	}
	void mover(char key) {
		switch (key) {
		case 'A': //OR KEY_LEFT (changed it to try a possible error)
			if (x <= 3) 
				x -= dx; 
			break;
		case 'D': //OR KEY_RIGHT (changed it to try a possible error)
			if (x + ancho >= 208) 
				x += dx;
			break;
		case 'W': //OR KEY_UP (changed it to try a possible error)
			if (y <= 3)
				y -= dy;
			break;
		case 'S': //OR KEY_DOWN (changed it to try a possible error)
			if (y + largo >= 43)
				y += dy;
			break;
		}
	}
	void boostspeed() {
		dx = 2;
	}
	void boostSpeednt() {
		dx = 1;
	}
	Rectangle hitbox() {
		return Rectangle(x, y, ancho, largo);
	}
	void setVida(int vidaux) {
		vidas = vidaux;
	}
	int getVida() {
		return vidas;
	}
	void dibujar() {
		Console::ForegroundColor = ConsoleColor::Yellow;
		Console::SetCursorPosition(x, y); cout << " __";
		Console::SetCursorPosition(x, y + 1); cout << "/ o\ ";
		Console::SetCursorPosition(x, y + 2); cout << "|   <";
		Console::SetCursorPosition(x, y + 3); cout << "\__ /";
	};
};
