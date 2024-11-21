#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <ctime>
#include "Effects.h"
using namespace std;

class Player
{
	public:
	string name;
	string className;
	int resource;
	string resourceName;
	int health;
	Weapon weapon;
	int speed;
	int dexterity;
	int strength;
	int armor;
	int regenerationRate;
	int hitChance;
	int critChance;
	int specialOneCost;
	string specialOneCost;
	int specialTwoCost;
	string specialTwoCost;
	vector<Effect> effects;

	virtual bool attack(Player* target);
	virtual bool specialOne(Player* target, string type) = 0;
	virtual bool specialTwo(Player* target, string type) = 0;
	virtual bool processEffects(Player* source, bool& loseATurn);
	virtual bool takeDamage(int damage, string type);

};
