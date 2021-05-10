#pragma once
#include <vector>
#include "Maze.h"
class Game
{
public:

	void battle() {



	}

	bool move_up(Maze maze, int player_position[2]) {

		if (maze.there_is_an_enemy(player_position[0] - 1, player_position[1])) battle();
		if (maze.exit_has_been_reached(player_position[0] - 1, player_position[1])) return 1;
		maze.move_up(player_position);
		return 0;
	}

	bool move_left(Maze maze, int player_position[2]) {

		if (maze.there_is_an_enemy(player_position[0], player_position[1] - 1)) battle();
		if (maze.exit_has_been_reached(player_position[0], player_position[1] - 1)) return 1;
		maze.move_up(player_position);
		return 0;
	}

	bool move_down(Maze maze, int player_position[2]) {

		if (maze.there_is_an_enemy(player_position[0] + 1, player_position[1])) battle();
		if (maze.exit_has_been_reached(player_position[0] + 1, player_position[1])) return 1;
		maze.move_up(player_position);
		return 0;
	}

	bool move_right(Maze maze, int player_position[2]) {

		if (maze.there_is_an_enemy(player_position[0], player_position[1] + 1)) battle();
		if (maze.exit_has_been_reached(player_position[0], player_position[1] + 1)) return 1;
		maze.move_up(player_position);
		return 0;

	}

	bool move(char a, Maze maze, int player_position) {

		switch (a) {

		case 'w': return move_up(maze, &player_position); break;
		case 'a': return move_left(maze, &player_position); break;
		case 's': return move_down(maze, &player_position); break;
		case 'd': return move_right(maze, &player_position); break;

		}

		return 0;
	}

	void print_maze(Maze maze) {

		
	
	
	}

};

