#include "Pokemon.h"

#include <iostream>
using namespace std;


Pokemon::Pokemon()
{
	mName = "Default";
	mDescription = "Default";
	petName = "Default";
	mMaxLifePoints = 1;
	mCurrentLifePoints = mMaxLifePoints;
}
Pokemon::Pokemon(string name, string desc, int maxLifePoints)
{
	mName = name;
	mDescription = desc;
	petName = mName;
	mMaxLifePoints = maxLifePoints;
	mCurrentLifePoints = mMaxLifePoints;
}
//Add constructor with abilities parameter

Pokemon::~Pokemon()
{
	//Empty until we have complex members
}

string Pokemon::GetName()
{
	return mName;
}
string Pokemon::GetDescription()
{
	return mDescription;
}
int Pokemon::GetMaxLifePoints()
{
	return mMaxLifePoints;
}
int Pokemon::GetCurrentLifePoints()
{
	return mCurrentLifePoints;
}
void Pokemon::Hurt(int points)
{
	cout << petName << " has taken " << points << " hp of damages.\n";
	//Do not allow less than 0 health
	if (mCurrentLifePoints - points < 0)
	{
		//The pokemon dies
		cout << petName << " has passed out.... You should take better care of your pokemons\n";
		mCurrentLifePoints = 0;
	}
	else
	{
		mCurrentLifePoints -= points; // mCurrentLifePoints = mCurrentLifePoints - points;
		cout << petName << " now has " << mCurrentLifePoints << "/" << mMaxLifePoints << endl;
	}
}
void Pokemon::Heal(int points)
{
	cout << petName << " has been healed of " << points << " hp.\n";
	if (mCurrentLifePoints + points > mMaxLifePoints)
	{
		//The pokemon is full health
		cout << petName << "'s health is back to maximum.\n";
		mCurrentLifePoints = mMaxLifePoints;
	}
	else
	{
		mCurrentLifePoints += points;  // mCurrentLifePoints = mCurrentLifePoints + points;
		cout << petName << " now has " << mCurrentLifePoints << "/" << mMaxLifePoints << endl;
	}
}
//Add learn ability
void Pokemon::LearnAbility(Ability ability)
{
	if (mAbilities.size() < maxAbilitiesCount)
	{
		//I can add ability
		mAbilities.push_back(ability);
		cout << mName << " learned : " << ability.GetAbilityName() << endl;
	}
	else
	{
		cout << mName << " already knows " << maxAbilitiesCount << " abilities.\n";
		//TODO choose ability to replace
		int choice = 0;
		do
		{
			DisplayAbilities();
			cout << "Which one do you want to replace ?";
			cin >> choice;
		} while (choice <= 0 || choice > maxAbilitiesCount);
		mAbilities[choice - 1] = ability;
		cout << "Ability was replaced with success.\n";
	}
	cout << "New abilities are : \n";
	DisplayAbilities();
}

void Pokemon::DisplayAbilities()
{
	cout << petName << " knows the following abilities : \n";
	for (int a = 0; a < mAbilities.size(); a++)
	{
		cout << "\t*" << (a + 1) << " : " << mAbilities[a].GetAbilityName()
			<< " | " << mAbilities[a].GetAbilityDescription()
			<< " | dmg : " << mAbilities[a].GetAbilityDamage() << " hp.\n";
	}
}
//Add attack

int Pokemon::GetNumbersOfAbilitiesLearned()
{
	return mAbilities.size();
}

Ability Pokemon::GetAbilityData(int index)
{
	return mAbilities[index];
}

void Pokemon::DisplaySumUp()
{
	cout << petName << " is a " << mName << endl;
	cout << "A " << mName << " is " << mDescription << endl;
	cout << petName << " has " << mCurrentLifePoints << "/" << mMaxLifePoints << " hp.\n";
}
