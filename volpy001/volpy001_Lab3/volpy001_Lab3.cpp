#include<iostream>
#include<cmath>
#include<string>
#include<iomanip>

using namespace std;

void warmUp1();
void warmUp2();
void warmUp3();
void stretch1();
void workout1();
void workout2();
void challenge1();
void challenge2();


int main()
{
    //warmUp1();
    //warmUp2();
    //warmUp3();
    //stretch1();
    //workout1();
    //workout2();
    //challenge1();
    challenge2();


    return 0;
}

void warmUp1()
{
    int number;
    cout << "How many Fibonacci numbers? ";
    cin >> number;
    number -= 2;
    
    /*
    p c       s
    ---
    0 1 print 1
    1 1       2
    1 2       3
    2 3       5
    3 5       8
    5 8       13
    */

    cout << "0 1";
    int p = 0;
    int c = 1;
    int s;

    for (int i = 0; i < number; i++)
    {
        s = c + p;
        p = c;
        c = s;

        cout << " " << s; 
    }
}

void warmUp2()
{
    int total = 0;
    for (int i = 1; i < 100; i++)
    {
        total += 1;
    }
}

void warmUp3()
{
    for (int i = 1; i <= 10; i++)
    {
        for (int j = 1; j <= 10; j++)
        {
            cout << setw(3) << j * i << " ";
        }
        cout << endl;
    }
}

void stretch1()
{
    int n;
    cout << "Input a positive integer: ";
    cin >> n;

    if (n < 1)
    {
        cout << "Positive Integers Only" << endl;
        return;
    }

    double oldGuess = n / 2.0;
    double newGuess = n;

    while (abs(newGuess - oldGuess) > oldGuess * 0.01)
    {
        oldGuess = newGuess;
        newGuess = (oldGuess + (n / oldGuess)) / 2;
        cout << newGuess << endl;
    }
    
    cout << "the Babylonian root is: " << fixed << newGuess << endl;
    cout << "the real root is: " << fixed << sqrt(n) << endl;

}

void workout1_example()
{
    double initialTemp = 6, surTemp = 25, decayRate = 1.355, stepHours = 0.1, simHours = 2; 
    
    cout << "Enter the initial temperature : ";
    cin >> initialTemp;
    cout << "Enter the temperature of the surroundings : ";
    cin >> surTemp;
    cout << "Enter the growth(decay) rate : ";
    cin >> decayRate;
    cout << "Enter the time step in hours : ";
    cin >> stepHours;
    cout << "Enter the simulation length in hours : ";
    cin >> simHours;
    double oldTemp = initialTemp;
    double newTemp = initialTemp;

    while (stepHours <= simHours)
    {
        newTemp = oldTemp + decayRate * (surTemp - oldTemp) * stepHours;
        oldTemp = newTemp;
        cout << setw(8) << fixed << setprecision(6) << stepHours << "   " << setw(9) << newTemp << endl;
        stepHours += 0.1;

    }
    
}


void workout1()
{
    double initialTemp = 37, surTemp = 25, decayRate = 0.4055, stepHours = 0.1, simHours = 2;

    //cout << "Enter the initial temperature : ";
    //cin >> initialTemp;
    //cout << "Enter the temperature of the surroundings : ";
    //cin >> surTemp;
    //cout << "Enter the growth(decay) rate : ";
    //cin >> decayRate;
    //cout << "Enter the time step in hours : ";
    //cin >> stepHours;
    //cout << "Enter the simulation length in hours : ";
    //cin >> simHours;
    double oldTemp = initialTemp;
    double newTemp = initialTemp;

    while (newTemp > 28)
    {
        newTemp = oldTemp + decayRate * (surTemp - oldTemp) * stepHours;
        oldTemp = newTemp;
        cout << setw(8) << fixed << setprecision(6) << stepHours << "   " << setw(9) << newTemp << endl;
        stepHours += 0.1;

    }
    int x = static_cast<int> (22 * 60 - stepHours * 60);
    cout << "time of death is: " << setfill('0') << setw(2) << x / 60 << ":" << setfill('0') << setw(2) << x % 60 << endl;
}

string int2roman(int value)
{
    if (value >= 900 && value <= 999) return "CM";
    if (value >= 500 && value <= 899) return "D";
    if (value >= 400 && value <= 499) return "CD";
    if (value >= 100 && value <= 399) return "C";
    if (value >= 90 && value <= 99) return "XC";
    if (value >= 50 && value <= 89) return "L";
    if (value >= 40 && value <= 49) return "XL";
    if (value >= 10 && value <= 39) return "X";
    if (value == 9) return "IX";
    if (value >= 5 && value <= 8) return "V";
    if (value == 4) return "IV";
    if (value >= 1 && value <= 3) return "I";
        
    return "0";
}

int int2romanLowerLim(int value)
{
    if (value >= 900 && value <= 999) return 900;
    if (value >= 500 && value <= 899) return 500;
    if (value >= 400 && value <= 499) return 400;
    if (value >= 100 && value <= 399) return 100;
    if (value >= 90 && value <= 99) return 90;
    if (value >= 50 && value <= 89) return 50;
    if (value >= 40 && value <= 49) return 40;
    if (value >= 10 && value <= 39) return 10;
    if (value == 9) return 9;
    if (value >= 5 && value <= 8) return 5;
    if (value == 4) return 4;
    if (value >= 1 && value <= 3) return 1;

    return 0;
}

void workout2()
{
    int value;
    cout << "Enter an integer value from 1 to 999: ";
    cin >> value;
    if (value < 1 || value > 999)
    {
        cout << "Invalid input. Program terminated." << endl;
        return;
    }
    cout << "Roman numeral equivalent: ";
    while (value > 0)
    {
        cout << int2roman(value);
        value -= int2romanLowerLim(value);
    }


}

void challenge1()
{
    int value;
    cout << "Input a positive integer: ";
    cin >> value;
    if (value < 0)
    {
        cout << "Input a positive integer: ";
        return;
    }
    
    do
    {
        cout << value % 10;
        value /= 10;
    }
    while (value > 0);
}

void challenge2()
{
    int value;
    cout << "Input a positive integer: ";
    cin >> value;
    
    if (value < 0)
    {
        cout << "Input a positive integer: ";
        return;
    }
    
    int factor = 2;
    cout << "Factors: ";

    while (value > 1)
    {
        if (value % factor == 0)
        {
            value /= factor;
            cout << factor;
    
            if (value > 1)
            {
                cout << "*";
            }
        }
        else
        {
            factor++;
        }
    }
}







