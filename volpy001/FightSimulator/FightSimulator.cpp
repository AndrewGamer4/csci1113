#include <iostream>
#include <cmath>
#include <initializer_list>
#include <ctime>
#include <iomanip>
#include <cstdlib>

#include "FightSimulator.hpp"

using namespace std;

void Base::stats_m(std::initializer_list<int> stats)
{
    int i = 0;
    for (int x : stats)
    {
        m_stats[i] = x;
        i++;
    }
}

void Base::displayStats()
{
    for (int x : m_stats)
    {
        cout << x << ", ";
    }
    cout << endl;
}

void Base::setWeaponSkill(int val)
{
    m_stats[static_cast<int>(Stats_e::WS)] = val;
}

int Base::getWeaponSkill() const
{
    return m_stats[static_cast<int>(Stats_e::WS)];
}

void Base::setBallisticSkill(int val)
{
    m_stats[static_cast<int>(Stats_e::BS)] = val;
}

int Base::getBallisticSkill() const
{
    return m_stats[static_cast<int>(Stats_e::BS)];
}

void Base::setStrength(int val)
{
    m_stats[static_cast<int>(Stats_e::Invul)] = val;
}

int Base::getStrength() const
{
    return m_stats[static_cast<int>(Stats_e::Invul)];
}

void Base::setToughness(int val)
{
    m_stats[static_cast<int>(Stats_e::Invul)] = val;
}

int Base::getToughness() const
{
    return m_stats[static_cast<int>(Stats_e::Invul)];
}

void Base::setWounds(int val)
{
    m_stats[static_cast<int>(Stats_e::W)] = val;
}

int Base::getWounds() const
{
    return m_stats[static_cast<int>(Stats_e::W)];
}

void Base::setInitiative(int val)
{
    m_stats[static_cast<int>(Stats_e::I)] = val;
}

int Base::getInitiative() const
{
    return m_stats[static_cast<int>(Stats_e::I)];
}

void Base::setAttacks(int val)
{
    m_stats[static_cast<int>(Stats_e::A)] = val;
}

int Base::getAttacks() const
{
    return m_stats[static_cast<int>(Stats_e::A)];
}

void Base::setLeadership(int val)
{
    m_stats[static_cast<int>(Stats_e::Ld)] = val;
}

int Base::getLeadership() const
{
    return m_stats[static_cast<int>(Stats_e::Ld)];
}

void Base::setArmor(int val)
{
    m_stats[static_cast<int>(Stats_e::SV)] = val;
}

int Base::getArmor() const
{
    return m_stats[static_cast<int>(Stats_e::SV)];
}

void Base::setInvul(int val)
{
    m_stats[static_cast<int>(Stats_e::Invul)] = val;
}

int Base::getInvul() const
{
    return m_stats[static_cast<int>(Stats_e::Invul)];
}

void Base::nonVirtualFunction() //Not really sure what this does. Like I understand the concept behind virtual functions but i don't know what to do with it.
{
    cout << "Base::nonVirtualFunction" << endl;
}

void Base::virtualFunction()
{
    cout << "Base::VirtualFunction" << endl;
}

Zarakynel::Zarakynel() //If this is of race Demon, should it be Zarakynel::Zarakynel() or should there be a higher order class that Zarakynel() should be part of?
{
    static_assert(static_cast<int>(Stats_e::MAX) == 10, "Fuck you");

    stats_m({ 10, 3, 7, 7, 6, 10, 5, 10, 7, 3 }); 
}

void Zarakynel::nonVirtualFunction() //Why do we have a virtual and a non-virtual for Zarakynel?
{
    cout << "Zarakynel::nonVirtualFunction" << endl;
}

void Zarakynel::virtualFunction()
{
    cout << "Z::VirtualFunction" << endl;
}

Anggrath::Anggrath()
{
    static_assert(static_cast<int>(Stats_e::MAX) == 10, "Fuck you");

    stats_m({ 10, 4, 10, 8, 8, 5, 7, 10, 2, 3 });
}

void Anggrath::nonVirtualFunction()
{
    cout << "Anggrath::nonVirtualFunction" << endl;
}

void Anggrath::virtualFunction()
{
    cout << "A::VirtualFunction" << endl;
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

bool toHitRanged(const Base &X) //We should rename X right? Also should we just merge this with ToHitRangedCount?
{   
    int bs = X.getBallisticSkill();

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
    cout << "Enter number of shots: "; //For Testing. Will be Automated
    cin >> numShots;
    cout << endl;
    int numHits = 0;
    while (numShots > 0)
    {
        //BUGBUG -- TO COMPILE LATER if (toHitRanged() == true)
        {
            numHits++;
        }
        numShots--;
    }
    cout << endl << numHits << endl;

    return numHits;
}

bool toHitCombat(const Base &x1, const Base &x2) 
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

int toHitCombatCount(const Base &x1, const Base &x2)
{
    int numAttacks = 0; //BUGBUG  x1.getAttacks;
    int numHits = 0;
    while (numAttacks > 0)
    {
        //BUGBUG if (toHitCombat() == true) //What should I put in the ()? It probably has to do with the x1 and x2 but i don't know how to do it since x1 and x2 aren't really fleshed out
        {
            numHits++;
        }
        numAttacks--;
    }
    cout << endl << numHits << endl;

    return numHits;
}

int toWound(const Base &x1, const Base &x2)
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
    
    int temp = toHitRangedCount(); //Or ToHitCombatCount(). Can we make it into one thing or should we keep it as two?
    while (temp > 0)
    {
        if (rollD6() >= needs)
        {
            numWounds++;
        }
        temp--;
    }
    
    temp = toHitCombatCount(x1, x2); //Will need to change this to do either ranged or combat. 
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
    
void save(const Base &X)
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

bool rollOff(const Base &x1, const Base &x2) 
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













