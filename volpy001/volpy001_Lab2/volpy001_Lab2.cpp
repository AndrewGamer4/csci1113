#include <iostream>
#include <cmath>
#include <cstdlib>
#include <iomanip>
#include <string>

using namespace std;

void warmUp1();
void stretch1();
void stretch2();
void stretch3();
void workout1();
void challenge1();
void foo();

int main()
{
	//warmUp1();
	//stretch1();
	//stretch2();
    //stretch3();
    //workout1();
    //challenge1();
    foo();

	return 0;
}
/*
Remap Caps to esc
add delay to tab completion
figure out why ctrl+shift down doesn't work
*/

void warmUp1()
{
	const double c = 3 * 1e10;

	double L;
	cout << "L = ";
	cin >> L;

	double tempV;
	char tempCh;
	int tempE;
	cout << "v = ";
	//if this format: 2.2e4, 2.2^4, 
	if (true)
	{
		cin >> tempV;  //reads 2.2
		cin >> tempCh; //reads e or ^ and throws it away
		cin >> tempE;  //reads 4
	}
	else // if this format: 2.2*10^4
	{
		cin >> tempV;  //reads 2.2
		cin >> tempCh; //reads * and throws it away
		cin >> tempE;  //reads 10 and throws it away
		cin >> tempCh; //reads ^ and throws it away
		cin >> tempE;  //reads 4
	}

	double v = tempV * pow(10, tempE);

	double LR = L * sqrt(1 - (pow(v, 2) / pow(c, 2)));

	cout << "LR = " << LR << endl;

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
    cout << "Enter an equation: ";
    int first;
    char oper;
    int last;

    cin >> first;
    cin >> oper;
    cin >> last;

    switch (oper)
    {
        case '+':
        {
            cout << first << " " << oper << " " << last << " = " << first + last << endl;
            break;
        }
        case '-':
        {
            cout << first << " " << oper << " " << last << " = " << first - last << endl;
            break;
        }
        case '*':
        {
            cout << first << " " << oper << " " << last << " = " << first * last << endl;
            break;
        }
        case '/':
        {
            cout << first << " " << oper << " " << last << " = " << static_cast<double> (first) / last << endl;
            break;
        }
    }

}


void workout1 ()
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
    
    double totalPay           = (hours * pay + overtime * 1.5 * pay);
    double socialSecutity     = totalPay * 0.06;
    double federalIncomeTax   = totalPay * 0.14;
    double stateIncomeTax     = totalPay * 0.05;
    const int unionDues       = 10;
    const int healthInsurance = dependent >= 3 ? 35 : 0;
    double takeHomePay        = totalPay - socialSecutity - federalIncomeTax - stateIncomeTax - unionDues - healthInsurance;

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

void foo ()
{
    int n = 5;
    int sum = n;
    while (--n > 0)
    {
        sum += n;
    }
    cout << sum << endl;
}



