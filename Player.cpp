#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <ctime>
#include "Player.h"
using namespace std;

bool Player::attack(Player* target)
{
	int hitRoll = rand() % 100 + 1;
	if (hitRoll > this->hitChance)
	{
		//git gudder moron
		cout << this->name << "missed" << endl;
		return false;
	}
	int damage = rand() % this->weapon.damage + 1 + this->strength;
	int critRoll = rand() % 100 + 1;
	if (critRoll <= this->critChance)
	{
		//CROCKET
		cout << this->name << "landed a critical strike" << endl;
		damage *= 2;
	}
	cout << this->name << " attacked " << target->name << " with the " << this->weapon.name << " for "
		<< damage << endl;
	return target->takeDamage(damage, "Physical");
}

bool Player::processEffects(Player* source, bool& loseATurn)
{
	bool dead = false;
	//What type of debuff are you suffering from?
	for (Effect& effect : this->effects)
	{
		//Poison
		if (effect.type == "Posion")
		{
			cout << this->name << "has been posioned and takes" << effect.damage << endl;
			dead = takeDamage(effect.damage, "Posion");
			effect.duration--;
		}
	}
	//Debuff has expired
	for (int i = 0; i < this->effects.size(); i++)
	{
		if (effects[i].duration == 0)
		{
			removeEffect(this->effects, i);
			i--;
		}
	}
	//Skill issue
	return dead;
}
void removeEffect(vector<Effect>& effects, int index)
{
	for (int i = index; i < effects.size() -1; i++)
	{
		effects[i] = effects[i + 1];
	}
	effects.pop_back();
}
bool Player::takeDamage(int damage, string type)
{
	//Dodge
	if (type == "Physical")
	{
		int dodgeRoll = rand() % 100 + 1;
		if (dodgeRoll <= this->dexterity)
		{
			cout << this->name << "dodged" << endl;
			return false;
		}
	}
	//Armor
	if (type == "Physical");
	{
		if (this->armor > 0)
		{
			cout << this->name << "'s armor protected them by " << this->armor << endl;
			int tempDmg = damage;
			damage -= this->armor;
			this->armor = this->armor - (tempDmg * 0.20);
			if (this->armor < 0)
				this->armor = 0;
		}
	}
	//LMAAAAAAAAAAOOOOOOOO
	this->health -= damage;
	if (this->health <= 0)
		return true;
	else
		return false;
}
