#pragma once
#include <string>
#include <vector>
#include "Pokemon.h"
#include "Ability.h"

using namespace std;

class Trainer
{
private:
	// Name of the Trainer Class
	string tTrainerClass;

	// Name of the Trainer
	string tName;

	// "Catchphrase"
	string tCatchphrase;

	// Money they give
	int tMoneyGiven;

	// Their team
	vector<Pokemon> tPokemonTeam;

	int tPokeballNumber;

	int tcurrentOutPokemon;

	// Their items
	// vector<Item> tInventory;
	
public:

	Trainer();
	Trainer(string _class, string name, string catchphrase, vector<Pokemon> Team, int moneyGiven);
	Trainer(string _class, string name, string catchphrase, vector<Pokemon> Team, int moneyGiven, int pokeballCount);

	~Trainer();
	
	// Get / Set for paramaters
	string GetTrainerClass();
	string GetTrainerName();
	string GetTrainerCatchphrase();
	int GetMoneyGiven();
	int GetPokeballsRemaining();
	int GetCurrentOutPokemonIndex();
	void SetCurrentOutPokemonIndex(int set);

	int GetTeamSize();
	int GetRemainingPokemonNumber();
	Pokemon& GetCurrentOutPokemon();
	Pokemon& GetPokemonByIndex(int index);

	// Catch
	bool TryCatchPokemon(Pokemon& target);
	void AddPokemonToTeam(Pokemon& target);

	// Send
	void SendPokemon(int pokemonIndex);

	// Recall
	void RetrievePokemon();
	
	// Switch
	void SwitchPokemon(int replacingPokemonIndex);

	// Buy
	void BuyItem();
	
	// Sell
	void SellItem();

	void IntroduceTrainer();

};