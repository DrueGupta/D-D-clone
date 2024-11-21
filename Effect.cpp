#include "Effects.h"

Effects::Effect(string type, int damage, int duration, Player* source)
{
	this->type = type;
	this->damage = damage;
	this->duration = duration;
	this->source = source;
	Effect::Effect() : Effect("")
}
