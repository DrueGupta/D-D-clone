#include <string>
#include "Player.h"
#include "Weapon.h"
using namespace std;

Weapon::Weapon(string name, int damage, int durability, string rarity)
{
	this->name = name;
	this->damage = damage;
	this->durability = durability;
	this->rarity = rarity;
}

Weapon::Wepaon() : Weapon("", 0, 0, "") {};
