#include "Battle.h"
#include "Pokemon.h"

#include <stdlib.h>
#include <iostream>
#include<vector>
using namespace std;

void Battle::PlayTurn()
{
	cout << "Choose your next move: \n";
	bFighters[0]->DisplayAbilities(); // why a -> and not a . wth ahhhhhh
	int chosenAttack = 0;
	cin >> chosenAttack; // index of the Move chosen

	// Damage
	// chosen Attack +1 because the DisplayAbilities goes from 1 to 1 but the data is 0 to 1
	bFighters[1]->Hurt(bFighters[0]->GetAbilityData(chosenAttack - 1).GetAbilityDamage());

	if (bFighters[1]->GetCurrentLifePoints() == 0)
	{
		EndBattle();
	}
	else
	{
		NextTurn();
	}
}

void Battle::NextTurn()
{
	// If it was turn one, then go turn 2 and inversly
	bPokemonTurnNumber = bPokemonTurnNumber == 1 ? 2 : 1;

	if (bPokemonTurnNumber == 2)
	{
		// Other pokemon chooses at random its attack

		srand(time(NULL));

		// 0 or 1 depending on how many it knows
		int chosenAttack = rand() % bFighters[1]->GetNumbersOfAbilitiesLearned();
		cout << "The opposing " << bFighters[1]->GetName() << " uses " << bFighters[1]->GetAbilityData(chosenAttack).GetAbilityName() << "\n";
		bFighters[0]->Hurt(bFighters[1]->GetAbilityData(chosenAttack).GetAbilityDamage());

		// If dead then stop
		if (bFighters[0]->GetCurrentLifePoints() == 0)
		{
			EndBattle();
		}
		else
		{		
			// Recursive but it will change bPokemonTurnNumber and call the other method
			NextTurn();
		}
	}
	else if (bPokemonTurnNumber == 1)
	{
		PlayTurn();
	}
}

void Battle::EndBattle()
{
	cout << "One player has died, the battle has ended. GGEZ";
}

Battle::Battle()
{
	bPokemonTurnNumber = 1;
	bFighters[0] = nullptr;
	bFighters[1] = nullptr;
}

Battle::Battle(Pokemon& PokemonOne, Pokemon& PokemonTwo)
{
	bPokemonTurnNumber = 1;
	bFighters[0] = &PokemonOne;
	bFighters[1] = &PokemonTwo;
}

Battle::~Battle()
{

}

void Battle::StartBattle()
{
	PlayTurn();
}
