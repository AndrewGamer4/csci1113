#include <iostream>
#include <cstdlib>
#include <string>
#include <cmath>
#include <iomanip>


using namespace std;

void Prob_WarmUp1();
void Prob_Stretch1();
void Prob_Stretch2();
void Prob_Stretch3();
void Prob_Workout1();
void Prob_Challenge1();
void Prob_Challenge2();


int main ()
{
	//Prob_WarmUp1();
	
	//Prob_Stretch1();

	//Prob_Stretch2();

	//Prob_Stretch3();

	Prob_Workout1();

	//Prob_Challenge1();

	//Prob_Challenge2();

	return 0;
}


void Prob_WarmUp1 ()
{
	int totalStudents = 168;
	int labStudents = 34;

	cout << "Ratio is " << static_cast<double> (totalStudents) / labStudents << endl;
}


double Derive(double);
double DerivePrime(int, double);

void Prob_Stretch1()
{
	int x     = 20;
	double h  = 1e-14;
	
	cout << DerivePrime(x, h) << endl;
}

double Derive(double x)
{
	return x * x * x;
}

double DerivePrime(int x, double h)
{
	return ( Derive(x + h) - Derive(x) ) / (h);
}

double F2C(double);

void Prob_Stretch2()
{
	double tf;
	
	cin >> tf;
	
	char f     = 'F';
	double tc  = F2C(tf);
	char c     = 'C';

	cout << tf << f << "=" << tc;
	cout << c;
}

double F2C (double f)
{
	return (f - 32) * 5.0 / 9.0;
}


void Prob_Stretch3()
{
	cout << "What... is your name?" << endl;
	string name;
	getline(cin, name);

	cout << "What... is your quest?" << endl;
	string quest;
	getline(cin, quest);

	cout << "What... is the air-speed velocity of an unladen swallow?" << endl;
	string a3;
	getline(cin, a3);

}


void Prob_Workout1()
{
	int z = 5;
	int x = z;
	int y = z;
	/*

	5   5		y =
	4   20		y = x*y
	3   60		y = x*y
	2   120
	1   120
	0   ends

	*/

	while (--x)
	{
		y *= x;
	}

	cout << z << "! = " << y << endl;
}


void Prob_Challenge1()
{
	cout << "Partner 1's full name: ";
	string p1FullName;
	getline(cin, p1FullName);

	cout << "Partner 1's height (approximate): ";
	double p1Height;
	cin >> p1Height;


	cout << "Partner 2's full name (or an imaginary friend): ";
	string p2FullName;
	getline(cin, p2FullName);
	getline(cin, p2FullName);

	cout << "Partner 2's height: ";
	double p2Height;
	cin >> p2Height;

	double combinedHeight = ((p1Height*12) + (p2Height*12)) / 12.0; 

	cout << p1FullName << " , " << p2FullName << "    Combined Height = " << combinedHeight << endl;

}


void Prob_Challenge2 ()
{
	cout << "What is your full name?" << endl;
	string fullName;
	getline(cin, fullName);

	size_t space = fullName.rfind(' ');
	
	string lastName = fullName.substr(space + 1);
	string rest = fullName.substr(0, space);

	cout << lastName << ", " << rest << endl;

}







