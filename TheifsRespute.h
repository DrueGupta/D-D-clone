#pragma once
#include<string>
#include"Weapon.h"
#include "Player.h"
using namespace std;

class TheifsRespute : public Weapon
{
public:
	TheifsRespute();
	void equip(Player* owner) override;
	bool weaponSpecial(Player* owner, Player* target, string type);
};
