#pragma once
#include <iostream>
using namespace std;
using namespace System;
using namespace System::Drawing;

class Bonus
{
private:
	int x, y; // Coordenadas
	int Largo, Ancho;
public:
	Bonus() {

		x = rand() % 150;
		y = rand() % 40;
		Ancho = 1;
		Largo = 1;
	};
	~Bonus() {};

	void borrar() {
		Console::SetCursorPosition(x, y); cout << " ";
	}
	void dibujar() {
		Console::ForegroundColor = ConsoleColor::Blue;
		Console::SetCursorPosition(x, y); cout << char(219);
	}

	System::Drawing::Rectangle getHitbox() {
		return System::Drawing::Rectangle(x, y, Largo, Ancho);
	}
};