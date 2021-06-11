#pragma once
#include <iostream>
#include <fstream>
#include <vector>
#include "rang.hpp"
#include <cmath>
#include <random>
#include <conio.h>
#include <stdlib.h> 

class Maze
{
	friend class Game;
	std::vector <std::vector <int>> maze;
	unsigned position_alice[2] = { 0, 0 };
	unsigned position_entrance[2] = { 0,0 };
	unsigned size;
	const unsigned MAX_AMOUNT_OF_ENEMIES = 2;
	unsigned position_first_enemy[2] = { 0, 0 };
	unsigned position_second_enemy[2] = { 0, 0 };

public:

	void return_alice_to_start() {

		position_alice[0] = position_entrance[0];
		position_alice[1] = position_entrance[1];

	}

	void get_starting_position() {

		for (size_t i = 0; i < maze.size(); i++) {

			for (size_t j = 0; j < maze[1].size(); i++) {

				if (maze[i][j] == 5) position_entrance[0] = i; position_entrance[1] = j;

			}

		}

	}

	void add_enemy(unsigned enemy_position [2]) {

		int size_ = maze.size();
		auto gen = std::mt19937{ std::random_device{}() };
		auto dist = std::uniform_int_distribution<int>{ 0, size_ - 1 };
		int i = dist(gen);
		int j = dist(gen);

		while (maze[i][j] != 0) {

			i = dist(gen);
			j = dist(gen);

		}

		enemy_position[0] = i;
		enemy_position[1] = j;

		return;

	}

	Maze() {

		size = 10;

		position_entrance[0] = 0;
		position_entrance[1] = 0;

		position_alice[0] = position_entrance[0];
		position_alice[1] = position_entrance[1];

		for (size_t i = 0; i < size; i++) {

			maze.push_back(std::vector<int>());

			for (size_t j = 0; j < size; j++) {

				maze[i].push_back(0);

			}

		}

		add_enemy(position_first_enemy);
		add_enemy(position_second_enemy);

	}

	Maze(std::string level) {

		level.push_back('.');
		level.push_back('t');
		level.push_back('x');
		level.push_back('t');

		std::ofstream file_level (level);
		std::vector <int> temp;

		for (std::vector<int>::const_iterator i = temp.begin(); i != temp.end(); ++i) {
			file_level << *i << '\n';
		}

		unsigned size_temp = sqrt(temp.size());

		for (size_t i = 0; i < size_temp; i++) {

			maze.push_back(std::vector<int>());

			for (size_t j = 0; j < size; j++) {

				maze[i].push_back(temp[size_temp*i + j]);

			}

		}

		get_starting_position();
		return_alice_to_start();

		add_enemy(position_first_enemy);
		add_enemy(position_second_enemy);

	}

	//+++++++++++++++++...+++++++++++++++++++++++

	//BELOW CODE USED FROM https://stackoverflow.com/questions/34842526/update-console-without-flickering-c

	//+++++++++++++++++...+++++++++++++++++++++++

	void setCursorPosition(int x, int y)
	{
		static const HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
		std::cout.flush();
		COORD coord = { (SHORT)x, (SHORT)y };
		SetConsoleCursorPosition(hOut, coord);
	}

	//+++++++++++++++++...+++++++++++++++++++++++

	int size_of_rows() { return maze.size(); }
	int size_of_cols() { return maze[0].size(); }
	int maze_position(int i, int j) { return maze[i][j]; }

	void show_mini_map() {

		setlocale(LC_ALL, "en_US.UTF-8");

		setCursorPosition(0, 0);

		for (size_t i = 0; i < size; i++) {

			for (size_t j = 0; j < size; j++) {

				rang::bg::black;

				if (position_alice[0] == i && position_alice[1] == j)
				{ std::cout << rang::fg::yellow; std::wcout << L"┼"; std::cout << rang::fg::reset; break; }//Alice

				if ((position_first_enemy[0] == i && position_first_enemy[1] == j) || 
					(position_second_enemy[0] == i && position_second_enemy[1] == j))
				{ std::cout << rang::fg::red; std::wcout << L"µ"; std::cout << rang::fg::reset; break; }

				switch (maze[i][j]) {

				case 0: std::cout << " "; break;
				case 1: std::wcout << L"█"; break; //Wall
				//case 2: std::cout << rang::fg::yellow << rang::style::blink; std::wcout << L"┼"; std::cout << rang::fg::reset; break; //Alice
				//case 3:  //Enemy 
				case 4: std::cout << rang::fg::blue; std::wcout << L"¤"; std::cout << rang::fg::reset; break; //Chest/weapon
				case 5: std::cout << rang::fg::cyan; std::wcout << L"░"; std::cout << rang::fg::reset; break; //Entry
				case 6: std::cout << rang::fg::magenta; std::wcout << L"░"; std::cout << rang::fg::reset; break;//exit
				
				}

			}

			std::cout << "\n";

		}

		return;

	}

	bool there_is_an_enemy(int i, int j) {

		return (position_alice[0] == position_first_enemy[0] && position_alice[1] == position_first_enemy[1])
			|| (position_alice[0] == position_second_enemy[0] && position_alice[1] == position_second_enemy[1]);

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

	void move_alice(int i, int j) {

		position_alice[0] += i;
		position_alice[1] += j;
		return;
	}

	bool can_move_alice(int i, int j) { return maze[i][j] != 1; }

	void teleportation_potion() {

		if (position_alice[0] - 3 < 0) return;
		if (maze[position_alice[0] - 3][position_alice[1]] == 6) return;
		for (int i = 3; i > 0; i++) {

			if (maze[position_alice[0] - i][position_alice[1]] == 0) move_alice(-i, 0); return;

		}

		return;
		
	}

	int alice_x_position() { return position_alice[0]; }
	int alice_y_position() { return position_alice[1]; }

	void move_alice(int i, int j, int temp_alice [2]) {

		int diff_x = temp_alice[0] - position_alice[0];
		int diff_y = temp_alice[1] - position_alice[1];

		if (can_move_alice(position_alice[0] + i, position_alice[1] + j) && (abs(diff_x) < 2) && (abs(diff_y) < 2)) {

			position_alice[0] += i;
			position_alice[1] += j;

		}

		return;

	}

	void invisibility_cap() {

		unsigned position_alice_temp[2];
		position_alice_temp[0] = position_alice[0];
		position_alice_temp[1] = position_alice[1];
		char confirm = 'g';
		
		while (confirm != '\r') {

			confirm = _getch();
			switch (confirm) {

			case 'w': move_alice(-1, 0); break;
			case 'a': move_alice(0, -1); break;
			case 's': move_alice(1, 0); break;
			case 'd': move_alice(0, 1); break;

			}
		}

	}

	void change_enemy() {

		if (position_alice[0] == position_first_enemy[0] && position_alice[1] == position_first_enemy[1]) add_enemy(position_first_enemy);
		if (position_alice[0] == position_second_enemy[0] && position_alice[1] == position_second_enemy[1]) add_enemy(position_second_enemy);
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