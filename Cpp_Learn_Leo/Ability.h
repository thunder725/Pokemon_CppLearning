#pragma once
#include <string>
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
	std::string aName;
	std::string aDescription;
	int aDamage;
	// Assuming that there is only one type of energy
	int aEnergyCost;
	

public:
	Ability();
	Ability(std::string name, std::string desc, int damage, int energyCost);

	~Ability();
	std::string GetAbilityName();
	std::string GetAbilityDescription();
	int getAbilityDamage();
	int getEnergyCost();

};