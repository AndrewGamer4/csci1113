#include <iostream>
#include <iomanip>
#include <cmath>
#include <initializer_list>
#include <ctime>
#include <cstdlib>

#include "TestLab3.h"

using namespace std;

int main()
{
    Zarakynel x = 
    return 0;
}

int rollD6()
{
    return (rand() % 6) + 1;
}

int rollD3()
{
    return (rand() % 3) + 1;
}

void numRollResults()
{
    int rolls;
    cout << "enter a number: ";
    cin >> rolls;

    int rollResults[6] = { 0 };

    for (int i = 0; i <= rolls - 1; i++)
    {
        int x = rollD6() - 1;
        rollResults[x]++;
    }

    for (int i = 0; i < sizeof(rollResults) / sizeof(rollResults[0]); i++)
    {
        cout << rollResults[i] << "  ";
    }
    cout << endl;
}
/*
bool toHitRanged(int bs) 
{
    if (bs > 5)
    {
        if (rollD6() > 1)
        {
            return true;
        }
        bs %= 6;
    }

    return rollD6() > 6 - bs;
}

int toHitRangedCount()
{
    int numShots = 0;
    cout << endl;
    int numHits = 0;
    while (numShots > 0)
    {
        if (toHitRanged(bs) == true)
        {
            numHits++;
        }
        numShots--;
    }
    cout << endl << numHits << endl;

    return numHits;
}
*/

bool toHitCombat()
{
    double WSAttacker = x1.getWeaponSkill();
    double WSTarget = x2.getWeaponSkill();
    int diff = static_cast<int>(WSAttacker - WSTarget);
    int needs;

    if (diff > 2 * WSAttacker)
    {
        needs = 5;
    }
    if (diff >= 0 && diff <= 2 * WSAttacker)
    {
        needs = 4;
    }
    if (diff < 0)
    {
        needs = 3;
    }

    return rollD6() >= needs;
}

int toHitCombatCount()
{
    int numAttacks = x1.getAttacks;
    int numHits = 0;
    while (numAttacks > 0)
    {
        if (toHitCombat() == true) 
        {
            numHits++;
        }
        numAttacks--;
    }
    cout << endl << numHits << endl;

    return numHits;
}

int toWound()
{
    int StrWeapon;
    int Strength = x1.getStrength();
    int Toughness = x2.getToughness();
    int numWounds = 0;
    int needs;
    int diff = Toughness - StrWeapon; //How would i get it to do either StrWeapon or Strength depending on if it's coming from ToHitRangedCount or ToHitCombatCount? 

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
            break;
    }
    /*
    int temp = toHitRangedCount(); //Or ToHitCombatCount(). Can we make it into one thing or should we keep it as two?
    while (temp > 0)
    {
        if (rollD6() >= needs)
        {
            numWounds++;
        }
        temp--;
    }
    */

    int temp = toHitCombatCount(x1, x2); //Will need to change this to do either ranged or combat. 
    while (temp > 0)
    {
        if (rollD6() >= needs)
        {
            numWounds++;
        }
        temp--;
    }
    return numWounds;
}

void save()
{
    int ArmorSave = X.getArmor();
    int InvulSave = X.getInvul();
    int Wounds = X.getWounds();

    int numWoundRollsLeft = 0; //BUGBUG -- COMPILE toWound();

    while (Wounds > 0 || numWoundRollsLeft > 0)
    {
        int temp = rollD6();

        if (ArmorSave < InvulSave)
        {
            if (temp < ArmorSave)
            {
                Wounds--;
            }
        }
        else if (temp < InvulSave)
        {
            Wounds--; //Wounds will probably need to be a & or * so that they change here. At the end of the programs, we will need to change Wounds beck to their initial number so 
                      //the Wounds are not saved permanently. Might be a better way. 
        }
        numWoundRollsLeft--;
    }

    if (Wounds == 0)
    {
        cout << "Name" << "is dead"; //How to get his Name
    }
}

bool rollOff()
{
    //If it returns true, x1 goes first, if it returns false, x2 goes first
    while (true)
    {
        int x1firstRoll = rollD6();
        int x2firstRoll = rollD6();

        if (x1firstRoll > x2firstRoll) return true;
        if (x1firstRoll < x2firstRoll) return false;
    }
}





