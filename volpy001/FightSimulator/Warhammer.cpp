#include <iostream>
#include <iomanip>
#include <cmath>
#include <initializer_list>
#include <ctime>

#include "FightSimulator.hpp"

using namespace std;

/*
Current Version:

Steps:
1.) Roll off to see who goes first. 
2.) The x1 that goes first moves, shoots, and charges.
3.) If x1 charges, x2 gets to Overwatch
4.) If Overwatch doesn't kill x1, then x1 gets Hammer of Wrath (if applicable)
5.) Then they fight based on personal Stats until one of them has 0 Wounds left

*/


void numRollResults();
int rollResults[];
void foo();

int main()
{
    srand(time(nullptr));

    foo();

     return 0;
}

void foo()
{
    Zarakynel z1;
    Anggrath a1;

    Base *bases[] = {&z1, &a1};

    for (auto b : bases)
    {
        b->nonVirtualFunction();
    }

    for (auto b : bases)
    {
        b->virtualFunction();
    }

    return;

    for (auto b : bases) //What does the auto b: bases do?
    {
        cout << b->getBallisticSkill() << endl;
    }

    z1.setBallisticSkill(10); //What does this do if we've already got it hard coded? Does this change it?

    for (auto b : bases)
    {
        cout << b->getBallisticSkill() << endl;
    }
}
        
/*
void firstMove(const base &x1, const base &x2)
{
    if (rollOff(x1, x2) == true) war(x1, x2);    
    else 
    {
        war(x2,x1); //switch the 

    }
}

void war(const base &x1, const base &x2)
{
        if (x1 != combat) // Need a new bool to check if in combat or not.
        {
            move() // need to make a function to move them. This isn't super important now as current iteration of the FightSimulator is just what's outlined above.
            
            cout << "Number of Shooting hits: " << toHitRangedCount() << endl; //just for testing.
            toWound(x1, x2); 
            save(x2); //how to get Wounds to return here to check?
            if (x2.Wounds() == 0) return; //need Wounds to be a & or * so that changes in save() will change it here.
        }

        if (charge() == true)
        {
            //Overwatch
            //Hammer of Wrath

            //check initiative of x1 vs. x2. the one with > Initiative goes first
            cout << "Number of Combat hits by " << x1 << " : " << toHitCombatCount() << endl;
            toWound(x1, x2); //definitely need to rename x1 and x2 as it gets confusing. x1 is the one that is doing the action. x2 is the one that gets the action done to it. 
            save(x2);
            if (x2.Wounds() == 0) return;

            auto temp = x2; //not sure what the type is since we need to switch x1 and x2 for this section
            x1 = x2;
            x2 = temp; 

            cout << "Number of Combat hits by " << x1 << " : " << toHitCombatCount() << endl;
            toWound(x1, x2); //definitely need to rename x1 and x2 as it gets confusing. x1 is the one that is doing the action. x2 is the one that gets the action done to it.
            save(x2);
            if (x2.Wounds() == 0) return;
        
            while (true) //is it better to do: x1.Wounds() != 0 || x2.Wouds() != 0
            {
                    //check initiative of x1 vs. x2. the one with > Initiative goes first
                cout << "Number of Combat hits by " << x1 << " : " << toHitCombatCount() << endl;
                toWound(x1, x2); //definitely need to rename x1 and x2 as it gets confusing. x1 is the one that is doing the action. x2 is the one that gets the action done to it. 
                save(x2);
                if (x2.Wounds() == 0) return;

                auto temp = x2; //not sure what the type is since we need to switch x1 and x2 for this section
                x1 = x2;
                x2 = temp; 

                cout << "Number of Combat hits by " << x1 << " : " << toHitCombatCount() << endl;
                toWound(x1, x2); //definitely need to rename x1 and x2 as it gets confusing. x1 is the one that is doing the action. x2 is the one that gets the action done to it.
                save(x2);
                if (x2.Wounds() == 0) return;
            }
        }
}

void zarakynel(//bunch of &'s to her abilities and weapons) //There must be a better way but I want to be able to do all of her character specific things in her class/functions
{
    Gargantuan() // create a class called Gargantuan that has certain rules that can be overwritten by user specific rules but are otherwise all used.
    
    CCWeapon::souleaterSword() //every CCWeapon has an int Str, int AP, and string type. The number of times it's used is x1.getAttacks();
    {
        Str = getStrength();
        AP = 1;
        instantDeath(); //make a function that does Instant Death
        specialistWeapon(); //don't need it now but need to make a function Specialist Weapon;
        if (x2.Wounds(Final) < x2.Wounds(Initial)) //need a way to check if other person's Wounds went down. 
        {
            if (rollD6() > 1 && x1.Wounds() < 10) ++x1.Wounds();
        }
    }
    RWeapon::deathlyRapture() //every RWeapon has a int Range, int Str, int AP, int numShots, 
    {
        Range = 36;
        Str = 6;
        AP = 3;
        numShots = diceRoll();
        Pinning (); // doesn't matter for this one but create a Pinning function.
    }

    reRollToHitCombat(); //create a function that allows to re-roll To Hits in combat
    reRollToWound(); //create a function that allows to re-roll To Wounds 
    assaultGrenades(); // create a function that does assault grenades
    if (charge == true) //same charge from void war() 
    {
        x1.Attacks() += rollD3(); //make this a temporary change.
    }

    if (x2 != "fearless") //need a way to search in x2 if they are fearless or not. No idea how to do that
    {
        if (x2.passLeadership() == false) // 
        {
            //x2 cannot attack
        }
    }
    demonOfSlaanesh(); // make a class Demon of Slaanesh that contains Demon(), Fleet(), Hatred(demonsOfKhorne), Rending, Run an additional 3", 
}

void anggrath(//bunch of &'s to her abilities and weapons)
{
    FlyingGargantuan() // create a class called FlyingGargantuan that has certain rules that can be overwritten by user specific rules but are otherwise all used.
    
    CCWeapon::axeOfKhorne()
    {
        Str = x1.getStrength();
        AP = 2;
        void decapitatingBlow()
        {
            if ([//need a way to get ToWound's rollD6 but I don't really want to store it] == 6)
            {
                insatntDeath();
            }
        }
        specialistWeapon();
    }

    RWeapon::bloodlashOfKhorne()
    {
        Range = 12;
        Str = 7;
        AP = 3;
        numShots = 2;
    }

    bloodFrenzy(); //doesn't matter here
    assaultGrenades(); // create a function that does assault grenades
    if (charge == true) //same charge from void war()
    {
    x1.Attacks() += rollD6(); //make this a temporary change.
    }
    
    demonOfKhorne(); // create a class DemonofKhorne that contains Demon(), FuriousCharge(), Hatred(demonsOfSlaanesh)
}

*/    











