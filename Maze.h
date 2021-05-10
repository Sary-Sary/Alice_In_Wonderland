#pragma once
#include <iostream>
#include <vector>
class Maze
{
	std::vector <std::vector <int>> maze;
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

					case 0: show_wall(block_row); break;
					case 1: show_empty(block_row); break;
					case 2: show_alice(animation_stage_alice, direction, block_row); break;
					case 3: show_enemy(); break;
					case 4: show_weapon(); break;

					}

				}

			}

		}

	}

	void show_mini_map(int animation_stage) {

		for (size_t i = 0; i < size; i++) {

			for (size_t j = 0; j < size; j++) {

				switch (maze[i][j]) {

				case 0: std::cout << "-"; break;
				case 1: std::cout << " "; break;
				case 2: std::cout << "A"; break;
				case 3: std::cout << "E"; break;
				case 4: std::cout << "W"; break;

				}

			}

		}


	}

	bool there_is_an_enemy(int i, int j) {

		return maze[i][j] == 3;

	}

	bool exit_has_been_reached(int i, int j) {

		return maze[i][j] == 5;

	}

	bool move_up(int position[2]) {

		if (position[0] - 1 < 0) return 0; //Alice has reached the boundries of the maze
		if (maze[position[0] - 1][position[1]] == 0) return 0; //There is a wall upwards 
		//do stuff...



		//if (position[0] - 1 = 5) return 1; //Alice has reached the exit

	}

};

