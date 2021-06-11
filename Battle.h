#pragma once
#include "Enemy.h"
#include "Alice.h"
#include "Weapon.h"
#include "Show_fighters.h"


class Battle
{
	//const char* battle_action[2] = { "attack", "weapon" };
	int attack_or_weapon;
	Enemy enemy;
	bool weapon_used;

public:

	Battle() {

		attack_or_weapon = 0;
		weapon_used = 0;

	}

	//+++++++++++++++++...+++++++++++++++++++++++

	//BELOW CODE USED FROM https://stackoverflow.com/questions/34842526/update-console-without-flickering-c

	//+++++++++++++++++...+++++++++++++++++++++++

	void setCursorPosition(int x, int y)
	{
		static const HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
		std::cout.flush();
		COORD coord = { (SHORT)x, (SHORT)y };
		SetConsoleCursorPosition(hOut, coord);
	}

	//+++++++++++++++++...+++++++++++++++++++++++

	void attack(Alice Alice, Enemy enemy) {

		enemy.is_hit(Alice.get_attack());
		Alice.is_hit(enemy.get_attack());
		return;
	}

	void you_have_used_a_weapon() {

		std::cout << "You can only chose a weapon once per battle!";
		return;

	}

	void weapon(Alice Alice, Maze maze) {

		if (weapon_used == 1) you_have_used_a_weapon(); return;
		Alice.pick_weapon(maze);
		attack(Alice, enemy);
		weapon_used = 1;
		return;
	}

	void action(Alice Alice, Maze maze, Enemy enemy) {

		switch (attack_or_weapon) {

		case 0: attack(Alice, enemy);
		case 1: weapon(Alice, maze);

		}

	}

	void move_pointer_up() {

		attack_or_weapon = 0;
		return;
	}

	void move_pointer_down() {

		attack_or_weapon = 1;
		return;
	}

	void change_to_chosen() {

		rang::fg::black;
		rang::bg::gray;
		return;
	}

	void revert() {

		rang::bg::reset;
		rang::fg::reset;
		return;
	}

	void show_actions() {

		std::cout << "--------------------------------\n";
		std::cout << "|";
		if (attack_or_weapon == 1) change_to_chosen();
		std::cout << "             Attack             ";
		revert();
		std::cout << "|\n";
		std::cout << "--------------------------------\n";
		
		std::cout << "--------------------------------\n";
		std::cout << "|";
		if (attack_or_weapon == 0) change_to_chosen();
		std::cout << "             Weapon             ";
		revert();
		std::cout << "|\n";
		std::cout << "--------------------------------\n";

		return;
	}

	void default_alice(Alice Alice) {

		Alice.return_to_default();
		return;

	}

	void restart_alice(Maze maze, Alice Alice) {

		Alice.return_to_default();
		
	}

	void show_enemy(Enemy enemy) {

		Show_fighters fighters;

		switch (enemy.get_enemy()) {

		case 0: fighters.cheshire_cat(); break;
		case 1: fighters.queen_of_heart(); break;
		case 2: fighters.white_rabbit(); break;
		case 3: fighters.mad_hatter(); break;

		}

		return;
	}

	void show_battle(Alice Alice, Enemy enemy, Maze maze) {

		maze.setCursorPosition(0, 0);

		std::cout << "------|ENEMY HP|-------\n";
		std::cout << "|" << enemy.get_attack() << "/" << enemy.get_max_health() << "|";
		std::cout << "-----------------------\n";

		show_enemy(enemy);

		show_actions();

		std::cout << "------|YOUR HP|-------\n";
		std::cout << Alice.get_attack() << "/" << Alice.get_max_health();
		std::cout << "-----------------------\n";

		return;

	}

	void battle(Alice Alice, Maze maze) {

		Enemy enemy;
		char direction = 'g';

		while (!Alice.died() || !enemy.died()) {

			direction = _getch();
			switch (direction) {

			case '\r': action(Alice, maze, enemy); break;
			case 'w': move_pointer_up(); break;
			case 's': move_pointer_down(); break;
			}

			show_battle(Alice, enemy, maze);

		}

		if (enemy.died()) return;
		default_alice(Alice);
		return;

	}

};

