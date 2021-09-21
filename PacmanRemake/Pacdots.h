#pragma once
#include <iostream>
using namespace std;
using namespace System;
using namespace System::Drawing;

class PacDots
{
private:
	int x, y; // Coordenadas
	int Largo, Ancho;
public:
	PacDots() {
		x = rand() % 150;
		y = rand() % 40;
		Ancho = 1;
		Largo = 1;
	}
	~PacDots() {};
	void borrar() {
		Console::SetCursorPosition(x, y); cout << " ";
	}
	void dibujar() {
		Console::ForegroundColor = ConsoleColor::Red;
		Console::SetCursorPosition(x, y); cout << char(254);
	}

	System::Drawing::Rectangle getHitbox() {
		return System::Drawing::Rectangle(x, y, Largo, Ancho);
	}
};