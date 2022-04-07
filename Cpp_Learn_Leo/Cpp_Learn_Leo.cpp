#include <iostream>
#include <stdlib.h>
#include "Pokemon.h"
#include "Battle.h"

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



// Exécuter le programme : Ctrl+F5 ou menu Déboguer > Exécuter sans débogage
// Déboguer le programme : F5 ou menu Déboguer > Démarrer le débogage

// Astuces pour bien démarrer : 
//   1. Utilisez la fenêtre Explorateur de solutions pour ajouter des fichiers et les gérer.
//   2. Utilisez la fenêtre Team Explorer pour vous connecter au contrôle de code source.
//   3. Utilisez la fenêtre Sortie pour voir la sortie de la génération et d'autres messages.
//   4. Utilisez la fenêtre Liste d'erreurs pour voir les erreurs.
//   5. Accédez à Projet > Ajouter un nouvel élément pour créer des fichiers de code, ou à Projet > Ajouter un élément existant pour ajouter des fichiers de code existants au projet.
//   6. Pour rouvrir ce projet plus tard, accédez à Fichier > Ouvrir > Projet et sélectionnez le fichier .sln.
