#define _USE_MATH_DEFINES

#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

int main() 
{
    //double rad;
    //cout << "Enter the radius of a circle: ";
    //cin >> rad;

    //cout << "Area: " << M_PI * pow(rad,2) << endl;
    //cout << "Circumference: " << 2 * M_PI * rad << endl;
    //return 0;
    
    for (int i = 1; i < 11; i++)
    {
        cout << endl;
        for (int j = 1; j < 11; j++)
        {
            cout << setw(3) << i * j << "  ";
        }
    }
    return 0;
}


