#include <iostream>
#include <cmath>
#include <string>
#include <cstdlib>

using namespace std;

bool prime(int);
bool fibonacci(int);

int main()
{
    int number;
    cout << "Give me a number, HUMAN: ";
    cin >> number;

    if (prime(number) == true)
    {
        cout << "That is (optimus) prime." << endl;
    }
    
    if (fibonacci(number) == true)
    {
        cout << "That is a Fibonacci.";
    }

    return 0;
}

bool prime(int number)
{
    for (int i = 2; i < number; i++)
    {
        if (number % i == 0)
        {
            return false;
        }
        continue;
    }
    return true;
}

bool fibonacci(int number)
{
    int current = 0;
    int first = 0;
    int second = 1;
    while (current < number)
    {
        int temp = second;
        second = first + second;
        first = temp;

        if (number == second)
        {
            return true;
        }
    }

    return false;
}














