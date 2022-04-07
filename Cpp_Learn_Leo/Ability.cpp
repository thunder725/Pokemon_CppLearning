#include "Ability.h"

#include <iostream>
using namespace std;

Ability::Ability()
{
	aName = "Default";
	aDescription = "Descriptionless attack.";
	aDamage = 0;
	aEnergyCost = 1;
}

Ability::Ability(string name, string desc, int damage, int energyCost)
{
	aName = name;
	aDescription = desc;
	aDamage = damage;
	aEnergyCost = energyCost;
}

Ability::Ability(string name, string desc, int damage)
{
	aName = name;
	aDescription = desc;
	aDamage = damage;
	aEnergyCost = 0;
}

Ability::~Ability()
{
	//Empty until we have complex members
}

string Ability::GetAbilityName()
{
	return aName;
}

string Ability::GetAbilityDescription()
{
	return aDescription;
}

int Ability::GetAbilityDamage()
{
	return aDamage;
}

int Ability::GetEnergyCost()
{
	return aEnergyCost;
}