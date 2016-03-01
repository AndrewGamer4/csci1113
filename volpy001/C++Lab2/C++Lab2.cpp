#include <iostream>
#include <iomanip>
#include <string>
#include <cmath>

using namespace std;

void warmup1();
void stretch1();
void stretch2();
void stretch3();
void workout1();
void challenge1();

int main ()
{
//    warmup1();
//    stretch1();
//    stretch2();
//    stretch3();
//    workout1();
    challenge1();

    return 0;
}

void warmup1() 
{
    double L = 0;
    double v = 0;
    char temp;
    double exp = 0;
    double LR = 0;
    double c = 3 * pow(10, 10);
    cout << "Input value for L: ";
    cin >> L;
    cout << endl << "Input value for v (scientific notation[ex. 5.0e10): ";
    cin >> v;
    cin >> temp;
    cin >> exp;
    double V = v * pow(10, exp);

    LR = L * sqrt(1 - (pow(V, 2) / pow(c,2)));
    cout << LR << endl;
}

void stretch1()
{
    int weight;
    cout << "Weight: ";
    cin >> weight;

    int height;
    cout << "Height: ";
    cin >> height;

    int age;
    cout << "Age: ";
    cin >> age;

    char gender;
    double bars = 0;

    for (bool keepRunning = true; keepRunning;)
    {
        cout << "Enter M for male and F for female: ";
        cin >> gender;

        switch (gender)
        {
            case 'F': case 'f':
            {
                keepRunning = false;
                bars = (655 + (4.3 * weight) + (4.7 * height) - (4.7 * age)) / 230;
                break;
            }
            case 'M': case 'm':
            {
                keepRunning = false;
                bars = (66 + (6.3 * weight) + (12.9 * height) - (6.8 * age)) / 230;
                break;
            }
        }
    }

    cout << "Number of needed bars = " << bars << endl;
}

void stretch2()
{
    double temperature;
    cout << "Enter the Temperature: ";
    cin >> temperature;
    cout << endl;

    char system;
    double convertedTemperature;
    string systemName;

    for (bool keepRunning = true; keepRunning;)
    {
        cout << "Enter Celsius (c) or Fahrenheit (f): ";
        cin >> system;
        cout << endl;

        switch (system)
        {
            case 'c': case 'C':
            {
                keepRunning = false;
                convertedTemperature = temperature * (9.0 / 5.0) + 32;
                systemName = "Fahrenheit";
                break;
            }
            case 'f': case 'F':
            {
                keepRunning = false;
                convertedTemperature = (temperature - 32) * (5.0 / 9.0);
                systemName = "Celsius";
                break;
            }
        }
    }

    cout << "The temperature in " << systemName << " is " << convertedTemperature << endl;

}

void stretch3()
{
    int first;
    char operand;
    int second;
    cout << "Enter an operation: ";
    cin >> first;
    cin >> operand;
    cin >> second;

    int out;
    switch(operand)
    {
        case '+':
            out = first + second;
            break;
        case '-':
            out = first - second;
            break;
        case '*': 
            out = first * second;
            break;
        case '/':
            out = first / second;
            break;
        default:
            cout << "Error: Improper Operand";
    }

    cout << first << operand << second << " = " << out << endl;
}

void workout1()
{
    const double pay = 16.78;
    double hours, overtime = 0;
    cout << "Hours: ";
    cin >> hours;

    int dependent;
    cout << "Dependents: ";
    cin >> dependent;


    if (hours > 40.0)
    {
        overtime = hours - 40;
        hours = 40;
    }

    double totalPay = (hours * pay + overtime * 1.5 * pay);
    double socialSecutity = totalPay * 0.06;
    double federalIncomeTax = totalPay * 0.14;
    double stateIncomeTax = totalPay * 0.05;
    const int unionDues = 10;
    const int healthInsurance = dependent >= 3 ? 35 : 0;
    double takeHomePay = totalPay - socialSecutity - federalIncomeTax - stateIncomeTax - unionDues - healthInsurance;

    cout << fixed << setprecision(2) << "Total Pay          : " << totalPay << endl;
    cout << fixed << setprecision(2) << "Social Security    : " << socialSecutity << endl;
    cout << fixed << setprecision(2) << "Federal Income Tax : " << federalIncomeTax << endl;
    cout << fixed << setprecision(2) << "State Income Tax   : " << stateIncomeTax << endl;
    cout << fixed << setprecision(2) << "Union Dues         : " << unionDues << endl;
    cout << fixed << setprecision(2) << "Health Insurance   : " << healthInsurance << endl;
    cout << fixed << setprecision(2) << "Net Take Home Pay  : " << takeHomePay << endl;

}

void challenge1()
{
    cout << "What is your income (drachmas): ";
    int income;
    cin >> income;

    double tax;

    if (income <= 10000)
    {
        tax = 0;
    }
    else if (income <= 30000)
    {
        tax = 0 + (income - 10000) * 0.1;
    }
    else if (income <= 70000)
    {
        tax = 0 + (20000 * 0.1) + (income - 30000) * 0.2;
    }
    else
    {
        tax = 0 + (20000 * 0.1) + (40000 * 0.2) + (income - 70000) * 0.3;
    }

    cout << "Tax: " << tax << endl;

}

