#pragma once
#include <random>

enum Enemies{CHESHIRE_CAT = 0,
QUEEN_OF_HEARTS = 20,
WHITE_RABBIT = 25,
MAD_HATTER = 30};

class Enemy
{
	//int active_enemy;
	Enemies enemy = Enemies::CHESHIRE_CAT;
	int enemies[4] = { CHESHIRE_CAT, QUEEN_OF_HEARTS, WHITE_RABBIT, MAD_HATTER };
	const unsigned max_health = 100;
	unsigned current_health = 100;
	unsigned attack = 0;

public:

	Enemy() {

		auto gen = std::mt19937{ std::random_device{}() };
		auto dist = std::uniform_int_distribution<int>{ 0, 3 };
		enemy = static_cast<Enemies>(enemies[dist(gen)]);

		current_health = 100;
		attack = get_attack();
	}

	void is_hit(int alices_attack) {

		current_health -= alices_attack;
		return;

	}

	int get_attack() {

		if ((int)enemy == 30) {

			auto gen = std::mt19937{ std::random_device{}() };
			auto dist = std::uniform_int_distribution<int>{ 0, 30 };
			return dist(gen);
			
		}

		return (int)enemy;

	}

	bool died() {

		return current_health < 1;

	}

};

