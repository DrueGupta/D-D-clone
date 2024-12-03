#include "Rouge.h"
#include "Player.h"
#include "Weapon.h"
#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
using namespace std;

Rouge::Rouge(string name)
{
	this-> name = name;
	this-> className = "Rouge";
	int resource;
	this-> resourceName = "Stanima";
	this-> health = 100;
	this-> weapon = nullptr;
	this-> speed = 15;
	this-> dexterity = 20;
	this-> strength = 5;
	this-> armor = 5;
	this-> regenerationRate = 5;
	this-> hitChance = 75;
	this-> critChance = 20;
	this-> specialOneCost = 35;
	this-> specialOneName = "Sneak Attack";
	this-> specialTwoCost = 70;
	this-> specialTwoName = "Stunning Powder";
	vector<Effect> effects;
}

bool Rouge::specialOne(Player* target)
{
	if (this->resource >= this->specialOneCost)
	{
		this->resource -= this->specialOneCost;
		int dmg = rand() % 40 + this->strength;
		cout << this->name << " preforms a stealth attack against " << target->name 
			<< " for " << dmg << endl;
		return target->takeDamage(dmg, "Physical");
	}
	else
	{
		cout << "You don't have enough stamima to preform this action." << endl;
		return false;
	}
}
bool Rouge::specialTwo(Player* target)
{
	if (this->resource >= this->specialTwoCost)
	{
		this->resource -= this->specialTwoCost;
		int dur = rand() % 4 + 1;
		Effect stun("Stun", 0, dur, this);
		cout << this->name << " throws stunning powder at " << target->name 
			<< " and stuns them for " << dur << endl;
		target->effects.push_back(stun);
		return false;
	}
	else
	{
		cout << "You don't have enough stamima to preform this action." << endl;
		return false;
	}
}
