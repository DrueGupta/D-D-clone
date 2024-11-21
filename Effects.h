#pragma once;
#include <string>
#include "Player.h"
using namespace std;

class Effect
{
public:
	string type;
	int damage;
	int duration;
	Player* source;

	Effect(string type, int damage, int duration, Player* source);
	Effect();
};
