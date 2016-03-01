#include <iostream>
#include <iomanip>
#include <string>

#include "Bug.hpp"
#include "Complex.hpp"
#include "DeckOfCards.hpp"
#include <algorithm>

using namespace std;

void stretch1();
void stretch2();
void workout1();
void workout2();
void challenge(); //Yet to do

int main()
{
    srand(static_cast<unsigned int>(time(nullptr)));

    //stretch1();
    //stretch2();
    //workout1();
    //workout2();
    challenge();

    return 0;
}

void stretch1()
{
    Bug bug(10);

    bug.display();
    
    bug.move();
    bug.display();

    bug.turn();
    bug.display();

    bug.move();
    bug.display();

}

void stretch2()
{
    Complex c1;
    Complex c2;

    cout << "Enter values for real and imaginary coefficients: ";
    c1.input(cin);
    cout << "Enter values for real and imaginary coefficients: ";
    c2.input(cin);

    c1.output(cout);
    cout << endl;
    c2.output(cout);
    cout << endl;

    double temp;
    cout << "Enter a new value for the real coefficient: ";
    cin >> temp;

    c2.setReal(temp);
    cout << "The new real coefficient is " << c2.getReal() << endl;
    c2.output(cout);
    cout << endl;

}

string cardName(int card)
{
    static const string suit[13] = { "A", "2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K" };
    return suit[card % 13];
}

void displayHand(int hand[], int len)
{
    
    for (int i = 0; i < len; i++)
    {
        cout << cardName(hand[i]) << " ";
    }
    cout << endl;
}


void workout1()
{
    DeckOfCards deck;
    int hand[4];
    int verify[13];
    for (int i = 0; i < 13; i++)
    {
        verify[i] = 0;
    }

    for (int k = 0; k < 13; k++)
    {
        for (int i = 0; i < 4; i++)
        {
            int card = deck.dealCard();
            hand[i] = card;
            verify[card % 13]++;
        }

        displayHand(hand, 4);
    }

    for (int i = 0; i < 13; i++)
    {
        if (verify[i] != 4)
        {
            cout << "Not enough " << cardName(i) << endl;
        }
    }

}

int pointValue(int card)
{
    if (card >= 1 && card <= 9)             //card 1 is 2 points. card 2 is 3 points, etc
    {
        return card + 1;
    }

    return 10;
}



int scoreDealer(int hand[], int len)
{
    int sum = 0;
    int allAces = 0;
    for (int i = 0; i < len; i++)
    {
        
        int card = hand[i] % 13;
        if (card == 0)
        {
            allAces++;
        }
        else
        {
            sum += pointValue(card);
        }
    }

    if (allAces == 0)
    {
        return sum;
    }

    int availPoints = 21 - sum;
    if (allAces > availPoints)
    {
        return sum + allAces;                  //numAces are each 1 point per ace (best case) so will bust regardless that aces are 1 each
    }

    int otherAces = allAces - 1;              //only 1 ace is allowed to be 11 points. All others must be 1
    if (availPoints + otherAces > 11)         //availPoints + the other aces (which must be 1 point) > 11, then...
    {
        return sum + 11 + otherAces;
    }

    return sum + allAces;
}


void workout2()
{
    DeckOfCards deck;
    int hand[11];
    int len = 0;
    
    for (int i = 0; i < sizeof(hand)/sizeof(hand[0]); i++)
    {
        hand[i] = 0;
    }

    int count[6];
    for (int i = 0; i < sizeof(count) / sizeof(count[0]); i++)
    {
        count[i] = 0;
    }

    for (int k = 0; k < 10000; k++)
    {
        for (int i = 0; i < 11; i++)
        {
            int card = deck.dealCard();
            hand[i] = card;
            
            int points = scoreDealer(hand, i+1);
            if (points >= 17)
            {
                points = std::min(points, 22);               //min function makes anything above 22 becomes 22

                count[points - 17]++;
                break;
            }
        }
    }
    
    for (int i = 0; i < (sizeof(count) / sizeof(count[0]) -1); i++)
    {
        cout << "hands of " << i + 17 << ": " << setw(4) << count[i] << "  (" << setw(4) << fixed << setprecision(2) << static_cast<double>(count[i]) / 100.0 << "%)" << endl;
    }
    cout << "dealer bust: " << setw(4) << count[5] << "  (" << fixed << setprecision(2) << setw(4) << static_cast<double>(count[5]) / 100.0 << "%)" << endl;

}

void challenge()
{
    DeckOfCards deck;
    int hand[11] = { 0 };
    int len = 0;

    int count[6] = { 0 };


    for (int i = 0; i < 11; i++)                       
    {
        int card = deck.dealCard();
        hand[i] = card;

        int points = scoreDealer(hand, i + 1);
        if (points >= 17)
        {
            points = std::min(points, 22);               //min function makes anything above 22 becomes 22

            count[points - 17]++;
            break;
        }
        displayHand(hand, i);
    }
    for (int i = 0; i < 4; i++)
    {
        int card = deck.dealCard();
        hand[i] = card;
    }


}


