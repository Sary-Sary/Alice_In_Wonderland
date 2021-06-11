#pragma once
#include "rang.hpp"
#include <random>

enum Weapons {

	TELEPORTATION_POTION = 3, 
	DRINK_ME_POTION = 10,
	EAT_ME_COOKIE = 40,
	MAGIC_FAN = 35,
	INVISIBILITY_CAP = 2,
	WHITE_OR_RED_ROSE = 10
};

class Weapon
{
	Weapons weapon = Weapons::TELEPORTATION_POTION;
	int weapons[6] = { TELEPORTATION_POTION, DRINK_ME_POTION, EAT_ME_COOKIE, MAGIC_FAN, INVISIBILITY_CAP,
	WHITE_OR_RED_ROSE };
	unsigned strength = 0;
	const char* descriptions[6] = {"Moves Alice 3 positions forward. If that position is not free,\n"
	"Alice is moved to the first available position.\n If the exit is less than 3 positions away, Alice does not move.",
	"Reduces Alice's abilities.", "Multiplies Alice's abilities tenfold.", "Shrinks the enemy and gives Alice an advantage.",
	"Turns Alice invisible and moves her two positions away by change, ignoring enemies.",
	"Alice does not know the colour of the rose when she decides to use it. The chance to get a red rose is 50%."};
	const char* weapon_name[6] = { "     Teleportation Potion     ", "       Drink-me Potion        ", 
		"        Eat-me Cookie         ", "          Magic Can           ", "       Invisibility Cap       ", 
		"      White or Red Rose       " };
	int weapon_number;

public:

	Weapon() {

		auto gen = std::mt19937{ std::random_device{}() };
		auto dist = std::uniform_int_distribution<int>{ 0, 5 };
		weapon_number = dist(gen);
		weapon = static_cast<Weapons>(weapons[weapon_number]);

		strength = (int)weapon;

	}

	int red_rose() {
		
		auto gen = std::mt19937{ std::random_device{}() };
		auto dist = std::uniform_int_distribution<int>{ 0, 1 };
		return dist(gen);

	}

	int get_strength() {

		if (weapon == WHITE_OR_RED_ROSE) {

			return (red_rose() == 1 ? 40 : 10);

		}

		return strength;

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

	void show_weapon(int i, bool chosen) {

		std::cout << "--------------------------------\n";
		std::cout << "|";
		if (chosen) change_to_chosen();
		std::cout << weapon_name[i];
		std::cout << "|\n";
		std::cout << "--------------------------------\n";

	}

	int get_weapon() { return weapon_number; }

	void show_description(int i) {

		std::cout << "\n";
		std::cout << descriptions[i];

	}

};

/*

--------------------------------
|     Teleportation Potion     |
--------------------------------
|      White or Red Rose       |
--------------------------------
|       Drink-me Potion        |
--------------------------------
|        Eat-me Cookie         |
--------------------------------
|          Magic Can           |
--------------------------------
|       Invisibility Cap       |
--------------------------------
|            Back              |
--------------------------------

.-^-.  
|___|


*/