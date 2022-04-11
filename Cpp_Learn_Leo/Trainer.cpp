#include "Trainer.h"

#include <iostream>
#include <math.h>
#include <stdlib.h>
using namespace std;

Trainer::Trainer()
{
	tTrainerClass = "GAMEFREAK";
	tName = "Morimoto";
	tCatchphrase = "#BringBackNationalDex";
	tMoneyGiven = 0;
	tPokeballNumber = 0;
	tcurrentOutPokemon = 0;
}

Trainer::Trainer(string _class, string name, string catchphrase, vector<Pokemon> Team, int moneyGiven)
{
	tTrainerClass = _class;
	tName = name;
	tCatchphrase = catchphrase;
	tPokemonTeam = Team;
	tMoneyGiven = moneyGiven;
	tPokeballNumber = 0;
	tcurrentOutPokemon = 0;
}

Trainer::Trainer(string _class, string name, string catchphrase, vector<Pokemon> Team, int moneyGiven, int pokeballCount)
{
	tTrainerClass = _class;
	tName = name;
	tCatchphrase = catchphrase;
	tPokemonTeam = Team;
	tMoneyGiven = moneyGiven;
	tPokeballNumber = pokeballCount;
	tcurrentOutPokemon = 0;
}

Trainer::~Trainer()
{
	tPokemonTeam.~vector();
}

string Trainer::GetTrainerClass()
{
	return tTrainerClass;
}

string Trainer::GetTrainerName()
{
	return tName;
}

string Trainer::GetTrainerCatchphrase()
{
	return tCatchphrase;
}

int Trainer::GetMoneyGiven()
{
	return tMoneyGiven;
}

int Trainer::GetPokeballsRemaining()
{
	return tPokeballNumber;
}

int Trainer::GetCurrentOutPokemonIndex()
{
	return tcurrentOutPokemon;
}

void Trainer::SetCurrentOutPokemonIndex(int set)
{
	tcurrentOutPokemon = set;
}

int Trainer::GetTeamSize()
{
	return tPokemonTeam.size();
}

int Trainer::GetRemainingPokemonNumber()
{
	// Foreach loop (wtf)
	int numberRemaining = 0;
	for (Pokemon p : tPokemonTeam)
	{
		if (p.GetCurrentLifePoints() > 0)
		{
			numberRemaining++;
		}
	}

	return numberRemaining;
}

Pokemon& Trainer::GetCurrentOutPokemon()
{
	return GetPokemonByIndex(tcurrentOutPokemon);
}

Pokemon& Trainer::GetPokemonByIndex(int index)
{
	if (index >= 0 && index < tPokemonTeam.size())
	{
		return tPokemonTeam[index];
	}
	else
	{
		cerr << "You tried to access a pokemon that doesn't exist: index " << index;
		Pokemon defaultP = Pokemon();
		return defaultP;
	}
	
}

bool Trainer::TryCatchPokemon(Pokemon& target)
{
	srand(time(NULL));
	// good luck decyphering https://bulbapedia.bulbagarden.net/wiki/Catch_rate
	
	// Catch rate average will be around 120;
	int firstPart = (3 * target.GetMaxLifePoints() - 2 * target.GetCurrentLifePoints()) / (3 * target.GetMaxLifePoints());
	int a = min(firstPart, 255);

	if (a == 255) { return true; }

	int shakeProbability = 65536 / pow((255/a), .1875);

	// Do 4 checks
	// If one of the check fails, the pokemon is not caught
	for (int i = 0; i < 4; i++)
	{
		if ((rand() % 65535) > shakeProbability)
		{
			return false;
		}
	}

	// Otherwise it is caught

	return true;
}

void Trainer::AddPokemonToTeam(Pokemon& target)
{
	if (tPokemonTeam.size() == 6) { return; }
	else
	{
		tPokemonTeam.push_back(target);
	}
}

void Trainer::SendPokemon(int pokemonIndex)
{
	cout << tTrainerClass << " " << tName << " sends out their " << GetPokemonByIndex(pokemonIndex).GetName() << endl;

	SetCurrentOutPokemonIndex(pokemonIndex);
}

void Trainer::RetrievePokemon()
{
	cout << tTrainerClass << " " << tName << " retrieves their " << GetCurrentOutPokemon().GetName() << endl;

}

void Trainer::SwitchPokemon(int replacingPokemonIndex)
{
	RetrievePokemon();
	SendPokemon(replacingPokemonIndex);
}




void Trainer::BuyItem()
{
}

void Trainer::SellItem()
{
}

void Trainer::IntroduceTrainer()
{
	cout << tTrainerClass << " " << tName << " wants to fight`!\n"
}
