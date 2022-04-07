#pragma once
#include <string>

using namespace std;

class Ability
{

	// What is an ability (Move)
	// 
	// 
	// Name
	// Description
	// Damage
	// Energy Cost

	// Constructor/Destructior
	// Attributes Getters

private:
	string aName;
	string aDescription;
	int aDamage;
	// Assuming that there is only one type of energy
	int aEnergyCost;
	

public:
	Ability();
	Ability(string name, string desc, int damage);
	Ability(string name, string desc, int damage, int energyCost);

	~Ability();
	string GetAbilityName();
	string GetAbilityDescription();
	int GetAbilityDamage();
	int GetEnergyCost();

};