#include <cstdlib>

#include "DeckofCards.hpp"

using namespace std;

DeckOfCards::DeckOfCards()
{
    for (int i = 0; i < 52; i++)
    {
        deck[i] = i;
    }
    
    nextCard = 0;
    shuffle();
}


int DeckOfCards::dealCard()
{
    if (nextCard > 51)
    {
        shuffle();
    }

    return deck[nextCard++];
}

void DeckOfCards::shuffle()
{
    nextCard = 0;

    for (int i = 52-1; i > 0; i--)
    {
        int j = rand() % i;
        
        int temp = deck[i];
        deck[i] = deck[j];
        deck[j] = temp;
    }
}




