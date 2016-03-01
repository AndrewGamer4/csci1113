#include <iostream>

using namespace std;

void workout();

int main()
{
    cout << "I am done with the warmup" << endl << "Check me off!" << endl;

    int x = 2;
    int y = x / x;
    cout << x * x + y << endl;

    double tf;
    cout << "Enter a termperature (F): ";
    cin >> tf;
    char f = 'F';
    double tc = (9.0 / 5)* (tf - 32);
    char c = 'C';
    cout << tf << f << "=" << tc << c;

    return 0;
}



