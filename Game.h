#pragma once
#include <vector>
#include<conio.h>
#include "Enemy.h"
#include "Maze.h"
#include "Alice.h"
#include "Battle.h"
#include "rang.hpp"
#include <string>

class Game
{
public:

	void battle(Alice Alice, Maze maze) {

		Battle battle;
		battle.battle(Alice, maze);



		return;
	}

	void move_up(Maze maze, Alice Alice) {

		if (maze.position_alice[0] == 0 || maze.maze[maze.position_alice[0] - 1][maze.position_alice[1]] == 1) return;
		if (maze.there_is_an_enemy(maze.position_alice[0] - 1, maze.position_alice[1])) battle(Alice, maze);
		if (maze.there_is_a_weapon(maze.position_alice[0] - 1, maze.position_alice[1])) Alice.add_weapon();
		maze.move_up();
		return;
	}

	void move_left(Maze maze, Alice Alice) {

		if (maze.position_alice[1] == 0 || maze.maze[maze.position_alice[0]][maze.position_alice[1] - 1] == 1) return;
		if (maze.there_is_an_enemy(maze.position_alice[0], maze.position_alice[1] - 1)) battle(Alice, maze);
		if (maze.there_is_a_weapon(maze.position_alice[0], maze.position_alice[1] - 1)) Alice.add_weapon();
		maze.move_up();
		return;
	}

	void move_down(Maze maze, Alice Alice) {

		if (maze.position_alice[0] == 9 || maze.maze[maze.position_alice[0] + 1][maze.position_alice[1]] == 1) return;
		if (maze.there_is_an_enemy(maze.position_alice[0] + 1, maze.position_alice[1])) battle(Alice, maze);
		if (maze.there_is_a_weapon(maze.position_alice[0] + 1, maze.position_alice[1])) Alice.add_weapon();
		maze.move_up();
		return;
	}

	void move_right(Maze maze, Alice Alice) {

		if (maze.position_alice[1] == 9 || maze.maze[maze.position_alice[0]][maze.position_alice[1] + 1] == 1) return;
		if (maze.there_is_an_enemy(maze.position_alice[0], maze.position_alice[1] + 1)) battle(Alice, maze);
		if (maze.there_is_a_weapon(maze.position_alice[0], maze.position_alice[1] + 1)) Alice.add_weapon();
		maze.move_up();
		return;

	}

	void show_mini_map(Maze maze) {

		maze.show_mini_map();
		return;
	}

	bool move(char a, Maze maze, Alice Alice) {

		switch (a) {

		case 'w': move_up(maze, Alice); break;
		case 'a': move_left(maze, Alice); break;
		case 's': move_down(maze, Alice); break;
		case 'd': move_right(maze, Alice); break;
		case 'm': maze.show_mini_map(); break;
		case 'i': Alice.pick_weapon(maze); break;
		}

		return maze.exit_has_been_reached();
	}

	void print_maze(Maze maze) {
	
		return;

	}

	void start_scene() {

		setlocale(LC_ALL, "en_US.UTF-8");
		char action = 'g';

		std::cout << rang::fg::cyan;
		std::wcout << L"▄▀█ █░░ █ █▀▀ █▀▀   █ █▄░█   █░█░█ █▀█ █▄░█ █▀▄ █▀▀ █▀█ █░░ ▄▀█ █▄░█ █▀▄\n" <<
					  L"█▀█ █▄▄ █ █▄▄ ██▄   █ █░▀█   ▀▄▀▄▀ █▄█ █░▀█ █▄▀ ██▄ █▀▄ █▄▄ █▀█ █░▀█ █▄▀\n";

		std::cout << "                                PRESS ANY BUTTON                       ";

		action = _getch();

		std::cout << rang::fg::reset;

		return;

	}

	void game() {

		
		start_scene();

		char direction = 'g';
		Alice Alice;
		bool end_reached = false;
		const unsigned amount_of_levels = 10;
		int current_level = 0;

		while (current_level < amount_of_levels) {

			Maze maze(std::to_string(current_level));

			while (!end_reached) {

				direction = _getch();

				end_reached = move(direction, maze, Alice);


			}
		}		

		return;

	}

};

