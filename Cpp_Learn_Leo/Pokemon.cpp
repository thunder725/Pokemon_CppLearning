#include "Pokemon.h"

#include <iostream>
using namespace std;


Pokemon::Pokemon()
{
	mName = "Default";
	mDescription = "Default";
	mPetName = "Default";
	mMaxLifePoints = 1;
	mCurrentLifePoints = mMaxLifePoints;
}
Pokemon::Pokemon(string name, string desc, int maxLifePoints)
{
	mName = name;
	mDescription = desc;
	mPetName = mName;
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
	cout << mPetName << " has taken " << points << " hp of damages.\n";
	//Do not allow less than 0 health
	if (mCurrentLifePoints - points < 0)
	{
		//The pokemon dies
		cout << mPetName << " has passed out.... You should take better care of your pokemons\n";
		mCurrentLifePoints = 0;
	}
	else
	{
		mCurrentLifePoints -= points; // mCurrentLifePoints = mCurrentLifePoints - points;
		cout << mPetName << " now has " << mCurrentLifePoints << "/" << mMaxLifePoints << endl;
	}
}
void Pokemon::Heal(int points)
{
	cout << mPetName << " has been healed of " << points << " hp.\n";
	if (mCurrentLifePoints + points > mMaxLifePoints)
	{
		//The pokemon is full health
		cout << mPetName << "'s health is back to maximum.\n";
		mCurrentLifePoints = mMaxLifePoints;
	}
	else
	{
		mCurrentLifePoints += points;  // mCurrentLifePoints = mCurrentLifePoints + points;
		cout << mPetName << " now has " << mCurrentLifePoints << "/" << mMaxLifePoints << endl;
	}
}
//Add learn ability
//Add attack

void Pokemon::DisplaySumUp()
{
	cout << mPetName << " is a " << mName << endl;
	cout << "A " << mName << " is " << mDescription << endl;
	cout << mPetName << " has " << mCurrentLifePoints << "/" << mMaxLifePoints << " hp.\n";
}