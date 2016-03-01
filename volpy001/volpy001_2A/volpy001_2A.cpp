#include <iostream>
#include <cmath>
#include <string>
#include <time.h>

using namespace std;

void pennies();
void dice();

int main()
{
    srand(time(0));
    pennies();
    dice();

    return 0;
}

void pennies()
{
    int total = 0;
    
    for (int i = 0; i < 1000000; i++)
    {
        int win = 0;

        for (int j = 0; j < 12; j++)
        {
            if (rand() % 2 == 1)
            {
                win++;
            }
        }

        total += win;
    }
    
    double average = static_cast<double>(total) / 1000000.0;
    cout << "Average income from penny game: " << fixed << average << endl;
}

void dice()
{
    int total = 0;

    for (int i = 0; i < 1000000; i++)
    {
        int win = 0;

        for (int j = 0; j < 2; j++)
        {
            win = (rand() % 6 + 1) + (rand() % 6 + 1);
        }

        total += win;
    }

    double average = static_cast<double>(total) / 1000000.0;
    cout << "Average income from dice game: " << fixed << average << endl;







}

