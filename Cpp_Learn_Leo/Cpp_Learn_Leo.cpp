#include <iostream>
#include <stdlib.h>
#include "Pokemon.h"
#include "Battle.h"
#include "Trainer.h"

using namespace std; // Using the STANDARD namespace

//void Damage(int value)
//{
//    value -= 2;
//    cout << value << "\n";
//}
//
//void DamageAtPointer(int &value)
//{
//    value -= 2;
//    cout << value << "\n";
//}

int main()
{  
    /*int life = 10;
    cout << &life << "\n";

    cout << life << "\n";
    Damage(life);
    cout << life << "\n";
    DamageAtPointer(life);
    cout << life << "\n";*/

    /*srand(time(NULL));

    float total = 0;
    int maxRolls = 742793;

    for (int i = 0; i < maxRolls; i++)
    {
        int rnd;
        rnd = (rand() % 6 + 1) + (rand() % 6 + 1);

        total += rnd;
    }

    total /= maxRolls;
    cout << "The average roll after " << maxRolls << " rolls is " << total << "\n";

    float errorPercentage;

    errorPercentage = abs((7 - total)) / 7 * 100;

    cout << "It is a deviation of " << errorPercentage << "% from the expected mean being 7" << "\n";

    if (errorPercentage < 0.001)
    {
        cout << "DEVIATION UNDER THE TRIPLE DIGIT INCREDIBLE!!!!!!!!!\n==================[INCREDIBLE]==================\n";
    }*/

    cout << "\n \n \n";

    // cout << "============PIKACHU=============\n";
    Pokemon pikachu = Pokemon("Pikachu", "chunky boi", 40);
    // pikachu.DisplaySumUp();
    // cout << "=========================\n";
    // pikachu.petName = "Pika Pika";
    // pikachu.Hurt(6);
    // pikachu.Heal(12);
    // pikachu.DisplaySumUp();
    Ability thunderShock = Ability("Thunder Shock", "Goes bzzzz", 30, 2);
    Ability gnaw = Ability("Gnaw", "Gnaws", 10);
    // Ability cutie = Ability("Cutie Pie", "2 Cute 2 be true", 10);
    pikachu.LearnAbility(thunderShock);
    pikachu.LearnAbility(gnaw);
    // pikachu.LearnAbility(cutie);

    Pokemon staryu = Pokemon("Staryu", "Low-grade Power Ranger", 40);
    Ability waterGun = Ability("Water Gun", "Shoots Water", 20);
    Ability waterPulse = Ability("Water Pulse", "Water wave", 30);
    staryu.LearnAbility(waterGun);
    staryu.LearnAbility(waterPulse);

    Battle newBattle = Battle(pikachu, staryu);
    newBattle.StartBattle();

}



// Ex??cuter le programme??: Ctrl+F5 ou menu D??boguer??> Ex??cuter sans d??bogage
// D??boguer le programme??: F5 ou menu D??boguer??> D??marrer le d??bogage

// Astuces pour bien d??marrer??: 
//   1. Utilisez la fen??tre Explorateur de solutions pour ajouter des fichiers et les g??rer.
//   2. Utilisez la fen??tre Team Explorer pour vous connecter au contr??le de code source.
//   3. Utilisez la fen??tre Sortie pour voir la sortie de la g??n??ration et d'autres messages.
//   4. Utilisez la fen??tre Liste d'erreurs pour voir les erreurs.
//   5. Acc??dez ?? Projet??> Ajouter un nouvel ??l??ment pour cr??er des fichiers de code, ou ?? Projet??> Ajouter un ??l??ment existant pour ajouter des fichiers de code existants au projet.
//   6. Pour rouvrir ce projet plus tard, acc??dez ?? Fichier??> Ouvrir??> Projet et s??lectionnez le fichier .sln.
