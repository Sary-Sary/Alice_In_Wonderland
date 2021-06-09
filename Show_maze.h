#pragma once
#include "Maze.h"
#include "rang.hpp"

class Show_maze : public Maze
{
public:

	void show_empty(int row);
	void show_wall(int row);

	/*
	
	|||||
	|||||
	|||||
	|||||
	|||||
	*/

	void show_idle(int row);
	void show_alice(int animation_stage, char direction, int row) {

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
	void show_maze(int animation_stage_alice, int direction, int alice_position[2], Maze maze) {

		int cols = maze[0].size_maze();
		int rows = maze.size_maze();

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

};

