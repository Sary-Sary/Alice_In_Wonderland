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

		for (size_t i = 0; i < size; i++) {

			//maze[i] = new int[size];

		}

		for (size_t i = 0; i < size; i++) {

			for (size_t j = 0; j < size; j++) {

				maze[i][j] = 0;

			}

		}

	}

	void show_empty(int row);
	void show_wall(int row);
	void show_idle(int row);
	void show_alice(int animation_stage,char direction, int row) {

		switch (direction) {

		case 'w': show_idle(row); break;
		case 'a': break;
		case 's': break;
		case 'd': break;
		case 'i': break;
		}

	}
	void show_enemy();
	void show_weapon();
	void show_maze(int animation_stage_alice, int direction, int alice_position [2]) {

		int cols = maze[0].size();
		int rows = maze.size();

		for (size_t i = 0; i < rows; i++) {

			for (size_t j = 0; j < cols; j++) {

				for (int block_row = 0; block_row < 5; block_row++) {

					switch (maze[i][j]) {

					case 0: show_empty(block_row); break;
					case 1: show_wall(block_row); break;
					case 2: show_alice(animation_stage_alice, direction, block_row); break;
					case 3: show_enemy(); break;
					case 4: show_weapon(); break;

					}

				}

			}

		}

	}

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