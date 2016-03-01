#include <iostream>


#include "Bug.hpp"

using namespace std;

Bug::Bug()
    : position(0)
    , dir(1)
{

}

Bug::Bug(int position)
    : position(position)
    , dir(1)
{

}

void Bug::turn()
{
    dir = -dir;
}

void Bug::move()
{
    position += dir;
}

void Bug::display()
{
    cout << "position = " << position << ", " << "direction = " << dir << endl;
}

