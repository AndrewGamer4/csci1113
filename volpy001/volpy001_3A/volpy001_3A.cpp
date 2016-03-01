#include <iostream>
#include <cmath>
#include <time.h>
#include <string>
#include <cstdlib>

using namespace std;

char randomChar() 
{
    return "01. "[rand() % 4];
}

void printLine(char c, int spot, int len)
{
    for (int i = 0; i < len; ++i)
    {
        cout << (i == spot ? c : randomChar());
    }
    cout << endl;
}

int main()
{
    srand(time(0));
    string words;
    cout << "What do you want printed vertically? ";
    getline (cin, words);

    for (string::iterator itr = words.begin(); itr != words.end(); ++itr)
    {
        if (*itr != ' ') 
        { 
            printLine(*itr, 11, 20); 
        }
    }
    
    return 0;
}
