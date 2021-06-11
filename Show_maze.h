#pragma once
#include "Maze.h"
#include "rang.hpp"
#include <cmath>
#include <algorithm>

class Show_maze : public Maze
{
public:

	void show_empty(int row) {

		std::cout << "    ";
		return;
	}

	void show_wall(int row) {

		setlocale(LC_ALL, "en_US.UTF-8");

		switch (row) {

		case 1: std::wcout << "";

		}

	}


	void up_alice(int row, int animation_stage) {

		switch (row) {

		case 0: std::cout << "     "; break;
		case 1: (animation_stage == 1 ? std::cout << "  p  " : std::cout << "  q  "); break;
		case 2: std::cout << " / \\ "; break;
		case 3: std::cout << " === "; break;
		case 4: std::cout << "     "; break;
		}

		animation_stage = (animation_stage == 1 ? 0 : 1);

		return;

	}

	void down_alice(int animation_stage, int row) {

		switch (row) {

		case 0: std::cout << "     "; break;
		case 1: std::cout << " 'î' "; break;
		case 2: std::cout << " /o\\ "; break;
		case 3: std::cout << " === "; break;

		}

		animation_stage = (animation_stage == 1 ? 0 : 1);

		return;

	}


	void left_alice(int animation_stage, int row) {

		switch (row) {

		case 0: std::cout << "     "; break;
		case 1: std::cout << " {@' "; break;
		case 2: std::cout << " /o> "; break;
		case 3: (animation_stage == 0 ? std::cout << " <_\\ " : std::cout << " /_\\ "); break;

		}

		animation_stage = (animation_stage == 2 ? 0 : 1);

		return;

	}

	void right_alice(int animation_stage, int row) {

		switch (row) {

		case 0: std::cout << "     "; break;
		case 1: std::cout << " {@' "; break;
		case 2: std::cout << " /o> "; break;
		case 3: (animation_stage == 0 ? std::cout << " /_> " : std::cout << " /_\\ "); break;

		}

		animation_stage = (animation_stage == 2 ? 0 : 1);

		return;

	}

	void show_alice(int animation_stage, char direction, int row) {

		switch (direction) {

		case 'w': up_alice(row, animation_stage); break;
		case 'a': left_alice(animation_stage, row);  break;
		case 's': down_alice(animation_stage, row); break;
		case 'd': right_alice(animation_stage, row); break;
		
		}

	}

	void show_enemy(int row) {

		switch (row) {

		case 3: std::cout << ".-=-.";
		case 4: std::cout << "<-0->";
		case 5: std::cout << "v.v.v";
		default: std::cout << "     ";

		}
			
		return;
	}

	void show_chest(int row) {

		switch (row) {

		case 3: std::cout << ".-^-.";
		case 4: std::cout << "|   |";
		case 5: std::cout << "|---|";
		default: std::cout << "     ";
		}

		return;

	}

	void show_maze(int animation_stage_alice, int direction, int alice_position[2], Maze maze) {

		unsigned rows = maze.size_of_rows();
		unsigned cols = maze.size_of_cols();

		setCursorPosition(0, 0);

		int start_i = (0 > maze.alice_x_position() - 3 ? 0 : maze.alice_x_position() - 3);
		int start_j = (0 > maze.alice_y_position() - 1 ? 0 : maze.alice_y_position() - 1);

		int end_i = (cols < maze.alice_x_position() + 3 ? rows : maze.alice_x_position() + 3);
		int end_j = (rows < maze.alice_x_position() + 1 ? rows : maze.alice_x_position() + 1);

		for (size_t i = start_i; i < end_i; i++) {

			for (size_t j = start_j; j < end_j; j++) {

				for (int block_row = 0; block_row < 5; block_row++) {

					switch (maze.maze_position(i, j)) {

					case 0: show_empty(block_row); break;
					case 1: show_wall(block_row); break;
					case 2: show_alice(animation_stage_alice, direction, block_row); break;
					case 3: show_enemy(block_row); break;
					case 4: show_chest(block_row); break;

					}

				}

			}

		}

	}

};

