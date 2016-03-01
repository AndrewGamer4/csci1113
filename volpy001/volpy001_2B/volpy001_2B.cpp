#include <iostream>

using namespace std;

int main()
{
    int next;
    int total;
    char operation;

    cout << "Enter an equation: ";
    cin >> total;

    while (true)
    {
        cin >> operation;
        if (operation == '#') 
            break;

        cin >> next;
        switch (operation)
        {
            case '*': total *= next; break;
            case '/': total /= next; break;
            case '+': total += next; break;
            case '-': total -= next; break;
        }
    }

    cout << total;

    return 0;
}








