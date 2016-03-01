#include <iostream>
#include <string>

using namespace std;

void problemB();

int main()
{
    problemB();

    return 0;
}

void problemB()
{
    int total = 0;
    int next = 0;
    char operand = '+';
    cout << "Enter an operation: ";
    cin >> total;
    while (operand != '#')
    {
        cin >> operand;
        cin >> next;
        switch (operand) 
        {
            case '+': total += next;
                break;
            case '-': total -= next;
                break;
            case '*': total *= next;
                break;
            case '/': total /= static_cast<double>(next);
                break;
            case '#':
                break;
        }
    }
    cout << "Total is: " << total << endl;
}