#pragma once
#include <string>
#include "Pokemon.h"
#include "Ability.h"


using namespace std;

class Battle
{
	// Reference of the 2 pokemon fighting
	// whose turn it is
	// 
	// Constructors / Destruccors
	// StartBattle Function
	// 
	// PlayTurn -> Let the player choose what they want to do - do damage to opponent
	// 
	// NextTurn -> End of turn
	// 
	// EndBattle

private:
	// 1 or 2 for the pokemon number (one or two)
	int bPokemonTurnNumber;
	Pokemon* bFighters[2]{};

	// Let the player choose what they want to do
	void PlayTurn();

	// Switch whoose turn it is
	void NextTurn();

	// End the battle (how???)
	void EndBattle();

public:
	Battle();
	Battle(Pokemon& PokemonOne, Pokemon& PokemonTwo);

	~Battle();

	// Setup the battle
	void StartBattle();

};

