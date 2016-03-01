#ifndef BUG_HPP
#define BUG_HPP

class Bug
{
public:
    Bug();
    Bug(int position);
public:
    void move();
    void turn();
    void display();
public:
    int position;
    int dir;
};


#endif //BUG_HPP
