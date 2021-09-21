#pragma once
#include <vector>
#include <iostream>
#include "Bonus.h"
#include "PacDots.h"
#include "Fantasma.h"
#include "Pacman.h"
using namespace std;
using namespace System;
using namespace System::Drawing;

class Controller {
private:
	Pacman* pacman;
	vector<PacDots*> dots;
	vector<Fantasma*> fantasmas;
	vector<Bonus*> bonus;
	int puntos;
public:
	Controller() {
		pacman = new Pacman();
		puntos = 0;
		for (int i = 0; i < 100; i++)
			addDots();
		for (int i = 0; i < 4; i++)
			addFantasmas();
		for (int i = 0; i < 10; i++)
			addBonus();
	};
	~Controller() {};

	int getPuntos() { return puntos; };
	void addDots() {
		PacDots* dot = new PacDots();
		dots.push_back(dot);
	};
	void addFantasmas() {
		Fantasma* ghost = new Fantasma();
		fantasmas.push_back(ghost);
	};
	void addBonus() {
		Bonus* bon = new Bonus();
		bonus.push_back(bon);
	};
	void borrarTodo() {
		Console::SetCursorPosition(1, 1); cout << "     ";
		Console::SetCursorPosition(1, 2); cout << "     ";
		Console::SetCursorPosition(1, 3); cout << "     ";
		Console::SetCursorPosition(1, 4); cout << "     ";
		pacman->borrar();
		for (int i = 0; i < 100; i++)
			dots[i]->borrar();
		for (int i = 0; i < 4; i++)
			fantasmas[i]->borrar();
		for (int i = 0; i < 10; i++)
			bonus[i]->borrar();
	};
	void moverFantasmas() {
		for (int i = 0; i < 4; i++)
			fantasmas[i]->mover();
	};
	void dibujarTodo() {
		pacman->dibujar();
		for (int i = 0; i < 100; i++)
			dots[i]->dibujar();
		for (int i = 0; i < 4; i++)
			fantasmas[i]->dibujar();
		for (int i = 0; i < 10; i++)
			bonus[i]->dibujar();
	};
	int getNumDots() { return dots.size(); };
	Pacman* getPacman() {
		return pacman;
	};
	void colision() {
		for (int i = 0; i < 4; i++)//pacman-fantasma
		{
			if (pacman->hitbox().IntersectsWith(fantasmas[i]->getHitbox())) {
				fantasmas[i]->changeDirection();
				pacman->setVida((pacman->getVida()) - 1);
			}
		}
		for (int i = 0; i < 100; i++)//pacman-dots
		{
			if (pacman->hitbox().IntersectsWith(dots[i]->getHitbox())) {
				dots[i]->borrar();
				puntos++;
			}
		}
		for (int i = 0; i < 10; i++)//pacman-bonus
		{
			if (pacman->hitbox().IntersectsWith(bonus[i]->getHitbox())) {
				bonus[i]->borrar();
				pacman->boostspeed();
				_sleep(5000);//5 segundos
				pacman->boostSpeednt();

			}

		};

	};

};