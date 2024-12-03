#include<string>
#include "Weapon.h"
#include "TheifsRespute.h"
#include "Effects.h"
using namespace std;

TheifsRespute::TheifsRespute()
{
	this->name = "Bane of London";
	this->damage = 10;
	this->durability = 100;
	this->rarity = "Rare";
}
void Shank::equip(Player* owner)
{
	owner->dexterity += 10;
}
bool Shank::weaponSpecial(Player* owner, Player* target, string type)
{
	int dmg = rand() % 8 + 1;
	int dur = rand() % 5 + 1;
	Effect p("Posion", dmg, dur, owner);
	cout << target->name << " has been poisoned by the Bane of London" << endl;
	target->effects.push_back(effect);
}
