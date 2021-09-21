#pragma once
#include <iostream>

using namespace std;
using namespace System;
using namespace System::Drawing;

class Fantasma {
private:
	int x, y;
	int dx, dy;
	int width, height;
	int rgb;

public:
	Fantasma() {
		x = rand() % 90;
		y = 5;
		dx = 1;
		dy = 1;
		width = 6;
		height = 4;
		rgb = rand() % 5;
	}

	~Fantasma() {}

	void borrar() {
		Console::SetCursorPosition(x, y);    cout << "      ";
		Console::SetCursorPosition(x, y + 1); cout << "      ";
		Console::SetCursorPosition(x, y + 2); cout << "      ";
		Console::SetCursorPosition(x, y + 3); cout << "      ";
	}

	void mover() {

		if (x <= 3 || x + width >= 150) {
			dx *= -1;

		}
		if (y <= 3 || y + height >= 40)
		{
			dy *= -1;

		}
		x += dx;
		y += dy;
	}

	void changeColor() {
		rgb = rand() % 5;
	}

	void dibujar() {

		switch (rgb)
		{
		case 0:
			Console::ForegroundColor = ConsoleColor::Cyan; break;
		case 1:
			Console::ForegroundColor = ConsoleColor::Green; break;
		case 2:
			Console::ForegroundColor = ConsoleColor::Yellow; break;
		case 3:
			Console::ForegroundColor = ConsoleColor::Magenta; break;
		case 4:
			Console::ForegroundColor = ConsoleColor::Gray; break;
		}

		Console::SetCursorPosition(x, y);            cout << " ___  ";
		Console::SetCursorPosition(x, y + 1);        cout << "/o o\  ";
		Console::SetCursorPosition(x, y + 2);        cout << "|   | ";
		Console::SetCursorPosition(x, y + 3);        cout << "|,,,| ";
	}

	void changeDirection() {
		dy *= -1;
	}
	System::Drawing::Rectangle getHitbox() {
		return System::Drawing::Rectangle(x, y, height, width);
	}

};