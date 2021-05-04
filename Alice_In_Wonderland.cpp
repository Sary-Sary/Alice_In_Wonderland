// Alice_In_Wonderland.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <conio.h>
#include <fcntl.h>
#include <io.h>

void create_maze(int maze [10][10]) {

	//open maze #

	for (size_t i = 0; i < 10; i++) {

		for (size_t j = 0; j < 10; j++) maze[i][j] = 1;

	}

	maze[0][0] = 0;
	maze[5][6] = 5;

	return;
}

void print(int maze[10][10]) {

	system("CLS");

	for (size_t i = 0; i < 10; i++) {

		for (size_t j = 0; j < 10; j++) std::cout << maze[i][j];

		std::cout << "\n";

	}

}

void move_left(int maze[10][10], int & i, int & j) {

	if (i == 10) return;

	j++;
	maze[i][j] = 0;
	maze[i][j - 1] = 1;
}

void move_char(int maze[10][10], char a, int & i, int & j) {

	switch (a) {

	case 'd': move_left(maze, i, j);

	}

	print(maze);

	return;
}

int main()
{
	/*for (int i = 0; i < 10; i++) {

		system("CLS");
		std::cout << "'@}\n<O\\\n/ >";
		//std::chrono::seconds dura(1);
		system("CLS");
		//std::this_thread::sleep_for(dura);
		std::cout << "'@}\n/O\\\n/ \\";
		//std::this_thread::sleep_for(dura);
		system("CLS");
		std::cout << "'@}\n/O>\n >";
	}*/
	int maze[10][10];
	create_maze(maze);

	char move = 'm';
	print(maze);
	move = _getch();
	int i = 0;
	int j = 0;
	while (1) {

		move = _getch();
		move_char(maze, move, i, j);
	}

}


