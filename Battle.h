#pragma once
#include "Enemy.h"
class Battle
{
	//const char* battle_action[2] = { "attack", "weapon" };
	int attack_or_weapon;
	Enemy enemy;

public:

	void attack(Alice Alice) {

		enemy.is_hit(Alice.get_attack);
		Alice.is_hit(enemy.get_attack);

	}

	void weapon(Alice Alice) {

		Alice.add_weapon();
		attack(Alice);

	}

	void action(Alice Alice) {

		switch (attack_or_weapon) {

		case 0: attack(Alice);
		case 1: weapon(Alice);

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

	void battle(Alice Alice) {

		Enemy enemy;
		char direction = 'g';

		while (!Alice.died() || !enemy.died()) {

			direction = _getch();
			switch (direction) {

			case '\n': action(Alice); break;
			case 'w': move_pointer_up(); break;
			case 's': move_pointer_down(); break;
			}

		}

	}

};

