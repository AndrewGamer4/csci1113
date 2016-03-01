#include <iostream>
#include <iomanip>
#include <fstream>
#include <cmath>
#include <string>
#include <ctime>

using namespace std;

void warmUp1();
void stretch1();
void stretch2();
void stretch3();
void workout1();
void workout2();
void challenge();

int main()
{
    srand(time(nullptr));
    //warmUp1();
    //stretch1();
    //stretch2();
    //stretch3();
    //workout1();
    workout2();
    //challenge();

    return 0;
}

void warmUp1()
{
    int mm, dd, yyyy;
    char ch;
    cout << "Enter a date in mm/dd/yyyy format: ";
    cin >> mm >> ch >> dd >> ch >> yyyy;

    cout << "Year, month, day: " << yyyy << "," << mm << "," << dd << endl;
}

int timeToMinutes(int hours, int mins)
{
    return hours * 60 + mins;
}

void stretch1()
{
    
    while (true)
    {

        int hh, mm;
        char ch;
        cout << "Enter a time duration (hh:mm) ";
        cin >> hh >> ch >> mm;

        cout << "Total Minutes: " << timeToMinutes(hh, mm) << endl;

        cout << "Continue? (y/n): ";
        cin >> ch;
        if (ch != 'y') break;
    }
}

void minutesToTime(int minute_value, int& hours, int& mins)
{
    hours = minute_value / 60;
    mins = minute_value % 60;
}

void stretch2()
{
    while (true)
    {
        int mm, hours, mins;
        char ch;
        cout << "Enter a number of minutes: ";
        cin >> mm;
        minutesToTime(mm, hours, mins);
        cout << "Hours:minutes is " << hours << ":" << mins << endl;

        cout << "Continue? (y/n): ";
        cin >> ch;
        if (ch != 'y') break;
    }
}

void elapsedTime(int h1, int m1, int h2, int m2, int& h, int& m)
{
    h = abs(h1 - h2);
    m = abs(m1 - m2);
}

void stretch3()
{
    
    while (true)
    {
        int h1, m1, h2, m2, h, m;
        char ch;
        cout << "Enter the first time (hours:minutes) : ";
        cin >> h1 >> ch >> m1;
        cout << "Enter the second time (hours:minutes) : ";
        cin >> h2 >> ch >> m2;

        elapsedTime(h1, m1, h2, m2, h, m);
        cout << "Elapsed time is: " << h << setfill('0') << setw(2) << m << endl;

        cout << "Continue? (y/n): ";
        cin >> ch;
        if (ch != 'y') break;
    }
}

void workout1()
{
    ofstream flightData;
    flightData.open("flightData.dat");

    if (!flightData.is_open())
    {
        cout << "File was not successfully opened";
        return;
    }

    string flightNum, ET, AT;
    string str;
    while (true)
    {
        cout << "Enter the flight number: ";
        cin >> flightNum;
        if (flightNum == "end") return;
        cout << "Enter the scheduled/actual arrival times: ";
        cin >> ET;
        cin >> AT;
        
        flightData << setw(10) << flightNum << setw(6) << ET << setw(6) << AT << endl;
    }
    flightData.close();
}

void workout2()
{
    string inFile;
    cout << "Enter flightData file name (flightData.dat): ";
    cin >> inFile;

    ifstream f;
    f.open(inFile);
    if (!f.is_open())
    {
        cout << "File did not open successfully" << endl;
        return;
    }
    
    string flightNum, minFlightNum, maxFlightNum;
    int hh1, mm1, hh2, mm2, hh, mm, minutes = 0, count = 0, min = 60 * 24, max = 0, currentMinutes;
    char ch;

    while (!f.eof())
    {
        ++count;
        f >> flightNum >> hh1 >> ch >> mm1 >> hh2 >> ch >> mm2;
        elapsedTime(hh1, mm1, hh2, mm2, hh, mm);
        currentMinutes = timeToMinutes(hh, mm);
        cout << currentMinutes << endl;
        minutes += currentMinutes;
        if (currentMinutes < min) { min = currentMinutes; minFlightNum = flightNum; }
        if (currentMinutes > max) { max = currentMinutes; maxFlightNum = flightNum; }
    }
    f.close();

    if (count == 0) return;


    minutesToTime(minutes / count, hh, mm);
    cout << "Average Flight Delay: " << hh << ":" << setfill('0') << setw(2) << mm << endl;

    minutesToTime(min, hh, mm);
    cout << "Minimum Flight Delay: " << hh << ":" << setfill('0') << setw(2) << mm << endl;

    minutesToTime(max, hh, mm);
    cout << "Maximum Flight Delay: " << hh << ":" << setfill('0') << setw(2) << mm << endl;
}

void diceRoll(int& first, int &second)
{
    first = rand() % 6 + 1;
    second = rand() % 6 + 1;
}

void displayRoll(int n, int m)
{
    cout << "[" << n << "," << m << "]";
}


void challenge()
{
    int first, second, total;
    diceRoll(first, second);
    total = first + second;
    cout << "Initial rolls is: ";
    displayRoll(first, second);
    cout << " = " << total << endl;

    if (total == 7 || total == 11)
    {
        cout << "You Win!" << endl;
        return;
    }
    if (total == 2 || total == 3 || total == 12)
    {
        cout << "Craps! Sorry, you lose" << endl;
        return;
    }
    
    int point = total;
    cout << "Point is " << point << ". Roll again" << endl;

    while (true)
    {
        diceRoll(first, second);
        total = first + second;
        cout << "Roll is: ";
        displayRoll(first, second);
        cout << " = " << total;
        if (total == 7) { cout << "  Sorry, you lose" << endl; return; }
        if (total == point) { cout << "  You win!" << endl; return; }
        cout << endl;
    }
}





