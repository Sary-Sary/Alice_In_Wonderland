#pragma once
#include <vector>
#include<conio.h>
#include "Enemy.h"
#include "Maze.h"
#include "Alice.h"
#include "Battle.h"

class Game
{


public:


	void battle(Alice Alice) {

		Battle battle;
		battle.battle(Alice);
		return;
	}

	void move_up(Maze maze, Alice Alice) {

		if (maze.position_alice[0] == 0 || maze.maze[maze.position_alice[0] - 1][maze.position_alice[1]] == 1) return;
		if (maze.there_is_an_enemy(maze.position_alice[0] - 1, maze.position_alice[1])) battle(Alice);
		if (maze.there_is_a_weapon(maze.position_alice[0] - 1, maze.position_alice[1])) Alice.add_weapon();
		maze.move_up();
		return;
	}

	void move_left(Maze maze, Alice Alice) {

		if (maze.position_alice[1] == 0 || maze.maze[maze.position_alice[0]][maze.position_alice[1] - 1] == 1) return;
		if (maze.there_is_an_enemy(maze.position_alice[0], maze.position_alice[1] - 1)) battle(Alice);
		if (maze.there_is_a_weapon(maze.position_alice[0], maze.position_alice[1] - 1)) Alice.add_weapon();
		maze.move_up();
		return;
	}

	void move_down(Maze maze, Alice Alice) {

		if (maze.position_alice[0] == 9 || maze.maze[maze.position_alice[0] + 1][maze.position_alice[1]] == 1) return;
		if (maze.there_is_an_enemy(maze.position_alice[0] + 1, maze.position_alice[1])) battle(Alice);
		if (maze.there_is_a_weapon(maze.position_alice[0] + 1, maze.position_alice[1])) Alice.add_weapon();
		maze.move_up();
		return;
	}

	void move_right(Maze maze, Alice Alice) {

		if (maze.position_alice[1] == 9 || maze.maze[maze.position_alice[0]][maze.position_alice[1] + 1] == 1) return;
		if (maze.there_is_an_enemy(maze.position_alice[0], maze.position_alice[1] + 1)) battle(Alice);
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
		case 'm': 
		}

		return maze.exit_has_been_reached();
	}

	void print_maze(Maze maze) {
	
		return;

	}

	void start_scene() {

		//animation

		_getch();

		return;

	}

	void game() {

		start_scene();

		char direction = 'g';
		Maze maze;
		Alice Alice;
		bool end_reached = false;

		while (!end_reached) {

			direction = _getch();

			end_reached = move(direction, maze, Alice);

		}


	}

};

