#pragma once
#include <string>
class Pokemon
{
private:
	std::string mName;
	std::string mDescription;
	int mMaxLifePoints;
	int mCurrentLifePoints;
	//Should add Abilities later

public:
	std::string mPetName;
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
	//Add attack

	void DisplaySumUp();

};

