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

	void show_empty();
	void show_wall();
	void show_idle();
	void show_alice(int animation_stage) {

		switch (animation_stage) {

		case 0: show_idle(); break;
		case 1: 
		}

	}
	void show_enemy();
	void show_weapon();
	void show_maze(int animation_stage, int alice_position [2]) {

		int cols = maze[0].size();
		int rows = maze.size();

		for (size_t i = 0; i < rows; i++) {

			for (size_t j = 0; j < cols; j++) {

				switch (maze[i][j]) {

				case 0: show_wall(); break;
				case 1: show_empty(); break;
				case 2: show_alice(animation_stage); break;
				case 3: show_enemy(); break;
				case 4: show_weapon(); break;

				}

			}

		}

	}

	void show_mini_map(int animation_stage) {

		for (size_t i = 0; i < size; i++) {

			for (size_t j = 0; j < size; j++) {

				switch (maze[i][j]) {

				case 0: show_wall(); break;
				case 1: show_empty(); break;
				case 2: show_alice(animation_stage); break;
				case 3: show_enemy(); break;
				case 4: show_weapon(); break;

				}

			}

		}


	}

};

