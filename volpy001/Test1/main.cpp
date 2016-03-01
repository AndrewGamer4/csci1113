#include <iostream>
#include <cmath>
#include <initializer_list>
#include <ctime>

#include "../FightSimulator/FightSimulator.hpp"

using namespace std;

void ToWound();
int ToHitRangedCount();
void numRollResults();
bool toHit(); //TEMPORARY JUST TO TEST

int main()
{
    void ToWound();

    return 0;
}



int Dice::rollDice()
{
    return (rand() % 6) + 1;
}

void numRollResults()
{
    int rolls;
    cout << "enter a number: ";
    cin >> rolls;

    int rollResults[6] = { 0 };

    Dice dice;
    for (int i = 0; i <= rolls - 1; i++)
    {
        int x = dice.rollDice() - 1;
        rollResults[x]++;
    }

    for (int i = 0; i < sizeof(rollResults) / sizeof(rollResults[0]); i++)
    {
        cout << rollResults[i] << "  ";
    }
    cout << endl;
}


bool toHit() //TEMPORARY JUST TO TEST
{
    int bs;
    cout << "Enter Shooter's BS: ";
    cin >> bs;
    cout << endl;

    if (bs > 5)
    {
        if (Dice::rollDice() > 1)
        {
            return true;
        }
        bs %= 6;
    }

    return Dice::rollDice() > 6 - bs;
}

int ToHitRangedCount()
{
    int numShots = 0;
    cout << "Enter number of shots: ";
    cin >> numShots;
    cout << endl;
    int numHits = 0;
    while (numShots > 0)
    {
        if (toHit() == true)
        {
            numHits++;
        }
        numShots--;
    }
    cout << endl << numHits << endl;

    return numHits;
}

void ToWound()
{
    int StrWeapon;
    cout << "Enter Weapon Strength: ";
    cin >> StrWeapon;
    cout << endl;
    //int Strength;
    //int Strength = X.getStrength();
    int Toughness;
    cout << "Enter Toughness: ";
    //int Toughness = X.getToughness();
    cin >> Toughness;
    int numWounds = 0;
    int needs;
    int diff = Toughness - StrWeapon;

    if (diff < -2)
    {
        diff = -2;
    }

    switch (diff)
    {
        case -2:
            needs = 2;
            break;
        case -1:
            needs = 3;
            break;
        case 0:
            needs = 4;
            break;
        case 1:
            needs = 5;
            break;
        case 2: case 3:
            needs = 6;
            break;
        default:
            needs = 7;
            cout << "Can't Wound";
            break;
    }

    int temp = ToHitRangedCount();
    while (temp > 0)
    {
        if (Dice::rollDice() > needs - 1)
        {
            numWounds++;
        }
        temp--;
    }

    cout << "Number of Wounds = " << numWounds << endl;
}









