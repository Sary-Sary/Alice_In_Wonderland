// Alice_In_Wonderland.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <conio.h>
#include <fcntl.h>
#include <io.h>
#include "Game.h"

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
	
	Game game;
	game.game();
	return 0;
}


