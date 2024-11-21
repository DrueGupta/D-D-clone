#include <string>
#include "Player.h"
using namespace std;

class Weapon
{
public:
	string name;
	int damage;
	int durability;
	string rarity;
	virtual void equip(Player* owner) = 0;
	virtual bool weaponSpecial(Player* owner, Player* target, string type) = 0;
	Weapon(string nsmae, int damage, int durability, string rarity);
	Weapon();
};
