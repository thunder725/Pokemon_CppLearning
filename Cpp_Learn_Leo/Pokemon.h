#pragma once
#include <string>
#include <vector>
#include "Ability.h"
class Pokemon
{
private:
	std::string mName;
	std::string mDescription;
	int mMaxLifePoints;
	int mCurrentLifePoints;
	//Should add Abilities later
	std::vector<Ability> mAbilities;
public:
	std::string petName;
	const int maxAbilitiesCount = 2;
	Pokemon();
	Pokemon(std::string name, std::string desc, int maxLifePoints);
	//Add constructor with abilities parameter

	~Pokemon();

	std::string GetName();
	std::string GetDescription();
	int GetMaxLifePoints();
	int GetCurrentLifePoints();
	void Hurt(int points);
	void Heal(int points);
	//Add learn ability
	void LearnAbility(Ability ability);
	void DisplayAbilities();
	//Add attack

	int GetNumbersOfAbilitiesLearned();
	Ability GetAbilityData(int index);

	void DisplaySumUp();

};