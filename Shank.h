#pragma once
#include<string>
#include"Weapon.h"
using namespace std;

class Shank : public Weapon
{
public:
	Shank();
	void equip(Player* owner) override;
	bool weaponSpecial(Player* owner, Player* target, string type);
};
