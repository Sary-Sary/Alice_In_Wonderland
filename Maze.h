#pragma once
#include <iostream>
#include <vector>
class Maze
{
	friend class Game;
	std::vector <std::vector <int>> maze;
	int position_alice[2];
	int size;

public:

	Maze() {

		size = 10;
		//maze = new int* [size];

		/*for (size_t i = 0; i < size; i++) {

			//maze[i] = new int[size];

		}*/

		for (size_t i = 0; i < size; i++) {

			for (size_t j = 0; j < size; j++) {

				maze[i][j] = 0;

			}

		}

	}

	int size_of_rows() { return maze.size(); }
	int size_of_cols() { return maze[0].size(); }

	void show_mini_map() {

		_setmode(_fileno(stdout), _O_U16TEXT);

		for (size_t i = 0; i < size; i++) {

			for (size_t j = 0; j < size; j++) {

				switch (maze[i][j]) {

				case 0: std::wcout << " "; break;
				case 1: std::wcout << L"■"; break;
				case 2: std::wcout << L"人"; break; //Alice
				case 3: std::cout << "E"; break;
				case 4: std::cout << "W"; break;

				}

			}

		}


	}

	bool there_is_an_enemy(int i, int j) {

		return maze[i][j] == 3;

	}

	bool there_is_a_weapon(int i, int j) {

		return maze[i][j] == 4;

	}

	bool exit_has_been_reached() {

		return maze[position_alice[0]][position_alice[1]] == 6;

	}

	void move_up() {

		maze[position_alice[0]][position_alice[1]] = 0;
		position_alice[0]--;
		if (maze[position_alice[0]][position_alice[1]] == 0) maze[position_alice[0]][position_alice[1]] = 3;
		//show_maze();
		return;

	}

	void move_down() {

		maze[position_alice[0]][position_alice[1]] = 0;
		position_alice[0]++;
		if (maze[position_alice[0]][position_alice[1]] == 0) maze[position_alice[0]][position_alice[1]] = 3;
		//show_maze();
		return;
	}

	void move_left() {

		maze[position_alice[0]][position_alice[1]] = 0;
		position_alice[1]--;
		if (maze[position_alice[0]][position_alice[1]] == 0) maze[position_alice[0]][position_alice[1]] = 3;
		//show_maze();
		return;
	}

	void move_right() {

		maze[position_alice[0]][position_alice[1]] = 0;
		position_alice[1]++;
		if (maze[position_alice[0]][position_alice[1]] == 0) maze[position_alice[0]][position_alice[1]] = 3;
		//show_maze();
		return;
	}

	void teleportation_potion() {



	}

	void invisibility_cap() {



	}

};

/*
0 - Empty
1 - Wall
2 - Alice
3 - Enemy
4 - Weapon
5 - Entry
6 - Exit
*/