﻿#pragma once
#include <fcntl.h>
#include <io.h>

class Alice
{
	int current_health = 100;
	const int max_health = 100;
	int current_attack = 15;
	const int base_attack = 15;

public:

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

	void add_weapon();

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