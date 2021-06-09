#pragma once
#include <fcntl.h>
#include <io.h>
#include "Weapon.h"

class Alice
{
	int current_health = 100;
	const int max_health = 100;
	int current_attack = 15;
	const int base_attack = 15;
	std::vector <Weapon> weapons_alice_has;

public:

	int amount_of_weapons() { return weapons_alice_has.size(); }

	void change_to_chosen() {

		rang::fg::black;
		rang::bg::gray;
		return;
	}

	void revert() {

		rang::fg::reset;
		rang::bg::reset;
		return;
	}

	void show_back_button(bool chosen) {

		std::cout << "--------------------------------\n";
		std::cout << "|";
		if (chosen) change_to_chosen();
		std::cout << "            Back              ";
		revert();
		std::cout << "|\n";
		std::cout << "--------------------------------\n";

	}

	void show_weapons(int chosen) {

		for (size_t i = 0; weapons_alice_has.size(); i++) 
			weapons_alice_has[i].show_weapon(weapons_alice_has[i].get_weapon(), i == chosen);
		show_back_button(chosen == 8);
		if (chosen != 8) weapons_alice_has[chosen].show_description(weapons_alice_has[chosen].get_weapon());
	}

	void increase_decrease_chosen(unsigned & action, int add) {

		if (action < amount_of_weapons() + 2) action += add;
		return;
	}

	void add_weapon(int weapon) {

		change_attack(weapons_alice_has[weapon].get_strength());
		weapons_alice_has.erase(weapons_alice_has.begin() + weapon);
		return;

	}

	void use_weapon(int weapon, Maze maze) {

		switch (weapons_alice_has[weapon].get_weapon()) {

		case 0: maze.teleportation_potion(); break;
		case 4: maze.invisibility_cap(); break;
		default: add_weapon(weapon);
		}

	}

	void show_info(int chosen) {



		return;
	}
	
	void pick_weapon() {

		char action = 'g';
		unsigned chosen = 0;
		show_weapons(chosen);

		do {

			switch (action) {

			case 'w': increase_decrease_chosen(chosen, 1); show_weapons(chosen); break;
			case 's': increase_decrease_chosen(chosen, -1); show_weapons(chosen); break;
			case 'i': 
			default: show_weapons(chosen);

			}

			action = _getch();

		} while (action != '\r');

		if (chosen == amount_of_weapons() + 1) return;
		use_weapon(chosen);
		return;

	}

	int get_attack() {

		return current_attack;

	}

	void change_attack(int weapon_attack) {

		current_attack = weapon_attack;
		return;

	}

	void is_hit(int enemy_attack) {

		current_health -= enemy_attack;
		return;

	}

	bool died() {

		return current_health < 1;

	}

	int get_current_health() {

		return current_health;

	}

	void add_weapon() {

		//Weapon weapon;

	}

	void sprite_idle() {

		/*
		<<<<<< >>>
		<<<<<< >>>
		<<<      >
		<<< >>> >>

		*/

		/*



	    '@}
		<O\
		/_>

		'@}
		<O\
		/_\
		
		{@'
		/o>
		<_\

		'@'
		/o\
		===

		 8
		/o\
		===

		*/
	}

};

/* 
                           _..._                                                                                          
          .---.        .-'_..._''.                                                                                       
          |   |.--.  .' .'      '.\     __.....__               .--.   _..._                                             
          |   ||__| / .'            .-''         '.             |__| .'     '.                                           
          |   |.--.. '             /     .-''"'-.  `.           .--..   .-.   .                                          
    __    |   ||  || |            /     /________\   \          |  ||  '   '  |                                          
 .:--.'.  |   ||  || |            |                  |          |  ||  |   |  |                                          
/ |   \ | |   ||  |. '            \    .-------------'          |  ||  |   |  |                                          
`" __ | | |   ||  | \ '.          .\    '-.____...---.          |  ||  |   |  |                                          
 .'.''| | |   ||__|  '. `._____.-'/ `.             .'           |__||  |   |  |                                          
/ /   | |_'---'        `-.______ /    `''-...... -'                 |  |   |  |                                          
\ \._,\ '/        .-'''-.       `                                   |  |   |  |                                          
 `--'  `"        '   _    \             _______                     '--'   '--'  .---.                     _______       
               /   /` '.   \    _..._   \  ___ `'.         __.....__             |   |             _..._   \  ___ `'.    
       _     _.   |     \  '  .'     '.  ' |--.\  \    .-''         '.           |   |           .'     '.  ' |--.\  \   
 /\    \\   //|   '      |  '.   .-.   . | |    \  '  /     .-''"'-.  `. .-,.--. |   |          .   .-.   . | |    \  '  
 `\\  //\\ // \    \     / / |  '   '  | | |     |  '/     /________\   \|  .-. ||   |    __    |  '   '  | | |     |  ' 
   \`//  \'/   `.   ` ..' /  |  |   |  | | |     |  ||                  || |  | ||   | .:--.'.  |  |   |  | | |     |  | 
    \|   |/       '-...-'`   |  |   |  | | |     ' .'\    .-------------'| |  | ||   |/ |   \ | |  |   |  | | |     ' .' 
     '                       |  |   |  | | |___.' /'  \    '-.____...---.| |  '- |   |`" __ | | |  |   |  | | |___.' /'  
                             |  |   |  |/_______.'/    `.             .' | |     |   | .'.''| | |  |   |  |/_______.'/   
                             |  |   |  |\_______|/       `''-...... -'   | |     '---'/ /   | |_|  |   |  |\_______|/    
                             |  |   |  |                                 |_|          \ \._,\ '/|  |   |  |              
                             '--'   '--'                                               `--'  `" '--'   '--'              

*/