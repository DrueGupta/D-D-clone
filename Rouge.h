#pragma once
#include "Player.h"
using namespace std;

class Rouge : public Player
{
public:
	bool specialOne(Player* target) override;
	bool specialTwo(Player* target) override;
};
