#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string>

using namespace std;

void warmUp1();
void warmUp2();
void stretch1();
void stretch2();
void workout1();
void challenge1();
void challenge2();

int main()
{
    warmUp1();
    warmUp2();
    stretch1();
    stretch2();
    workout1();
    challenge1();
    challenge2();

    return 0;
}

/*
Prints out 10 and then 5
*/

double babylonianRoot(double n)
{
    if (n < 1)
    {
        cout << "Positive Integers Only" << endl;
        return 0.0;
    }

    double oldGuess = n / 2.0;
    double newGuess = n;

    while (abs(newGuess - oldGuess) > oldGuess * 0.01)
    {
        oldGuess = newGuess;
        newGuess = (oldGuess + (n / oldGuess)) / 2;
    }

    return newGuess;
}

void warmUp1()
{
    char ch;
    double value;
    do
    {
        cout << "enter a value: ";
        cin >> value;

        cout << "square root of " << value << " is " << babylonianRoot(value) << endl;

        cout << "continue? (y/n): ";
        cin >> ch;
        cout << endl;
    }
    while (ch == 'y');
}

bool isLeapYear(int year)
{
    if (year % 400 == 0 || year % 4 == 0 && year % 100 != 0) {return true; }
    else { return false; }
}

void warmUp2()
{
    int year;
    char ch;

    do
    {
        cout << "enter a year value: ";
        cin >> year;

        cout << year << " is ";
        if (isLeapYear(year) == true) {cout << "a leap year"; }
        else {cout << "not a leap year"; }
    
        cout << endl << "continue? (y/n): ";
        cin >> ch;
    } while (ch == 'y');
}

int last_day(int month, int year)
{
    switch (month)
    {
        case 1: case 3: case 5: case 7: case 8: case 10: case 12:
            return  31;
            break;
        case 4: case 6: case 9: case 11:
            return 30;
            break;
        case 2:
            if (isLeapYear(year) == true) { return 28; }
            else { return 29; }
            break;
        default: 
            return 0;
    }
}

void stretch1()
{
    int month;
    int year;
    char ch;

    do
    {
        cout << "enter month and year: ";
        cin >> month;
        cin >> year;

        cout << "days in month: " << last_day(month, year) << endl;
        
        cout << "continue? (y/n): ";
        cin >> ch;
    }
    while (ch == 'y');
}

void stretch2()
{
    int month;
    int day;
    int year;
    char ch;

    do
    {
        cout << "enter a date as mm dd yyyy: ";
        cin >> month;
        cin >> day;
        cin >> year;

        if (last_day(month, year) == day) 
        {
            day = 1;
            if (month == 12)
            {
                month = 1;
                year++;
            }
            else { month++; }
        }
        else { day++; }

        cout << "next day is : " << month << "  " << day << "  " << year << endl;

        cout << "continue? (y/n): ";
        cin >> ch;
    }
    while (ch == 'y');
}

double power(double x, int n)
{
    const double total = x;
    while (n > 1)
    {
        x *= total;
        n--;
    }

    return x;
}

double rootN(double x, int n)
{
    double oldGuess = 1;
    double newGuess = 2;

    while (abs(newGuess - oldGuess) > oldGuess * 0.01)
    {
        oldGuess = newGuess;
        newGuess = (1.0 / n) * ((n - 1) * oldGuess + (x / (power(oldGuess, n-1))));
    }

    return newGuess;
}

void workout1()
{
    char ch;
    double value;
    int root;

    do
    {
        cout << "enter value and root: ";
        cin >> value;
        cin >> root;

        cout << "the root is: " << rootN(value, root) << endl;

        cout << "continue? (y/n): ";
        cin >> ch;
    }
    while (ch == 'y');

}

int GCD(int a, int b)
{
    int gcd;
    int q;
    int r = 1;

    if (a < b)
    {
        int temp = a;
        a = b;
        b = temp;
    }

    int j = b;

    while (r > 0)
    {
        q = a / b;
        r = a % b;
        a = b;
        b = r;
        if (r > 0)
        {
            j = r;
        }
    }

    return j;
}

void challenge1()
{
    char ch;
    int first;
    int second;

    do
    {
        cout << "enter two integer values: ";
        cin >> first;
        cin >> second;

        cout << "greatest common divisor is: " << GCD(first, second) << endl;

        cout << "continue? (y/n): ";
        cin >> ch;
    }
    while (ch == 'y');
}

bool check_eqp(int e, int p, int q)
{
    return GCD(e, (p - 1)*(q - 1)) == 1;
}

int char_to_number(char letter)
{
    return (int)letter - '0';
}

int encode(int a, int e, int n)
{
    return (static_cast<int>(pow(static_cast<double>(a), e)) % n);
}
void challenge2()
{
    int e, p, q, n;
    char letters[4];
    int numbers[4];
    int encoded[4];
    cout << "Input e, p, and q: ";
    cin >> e;
    cin >> p;
    cin >> q;

    if (check_eqp(e, p, q) == false)
    {
        cout << "Error: GCD of e and (p-1)*(q-1) is not 1)" << endl;
        exit(0);
    }

    cout << "Input four upper case letters: ";
    n = p * q;


    for (int i = 0; i < 4; i++)
    {
        cin >> letters[i];
        numbers[i] = char_to_number(letters[i]);
        encoded[i] = encode(numbers[i], e, n);
    }

    cout << "The encoding of ";

    for (int j = 0; j < 4; j++)
    {
        cout << letters[j] << " ";
    }

    cout << "is ";

    for (int k = 0; k < 4; k++)
    {
        cout << encoded[k] << " ";
    }
}




