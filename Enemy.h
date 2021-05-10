#pragma once

enum enemies{Cheshire_cat = 0,
Queen_Of_Hearts = 20,
White_Rabbit = 25,
Mad_Hatter = 30};

class Enemy
{
	//int active_enemy;
	enemies enemy;
	const int max_health = 100;
	int current_health;
	int attack = 0;

};

