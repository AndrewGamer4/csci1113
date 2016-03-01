#ifndef TEST2_HPP
#define TEST2_HPP
#include <string>

class Race
{
private:

protected:
public:
    virtual void move() const = 0; // pure virtual, no implementation is possible
    virtual void foo();
    std::string name() const;
    std::string m_name;
};

class SpaceMarine : public Race
{
public:
    SpaceMarine(const std::string& name);

    void move() const;
public:
    int numGuns = 10;
};

class Tyranid : public Race
{
public:
    Tyranid(const std::string& name);

    void move() const;
public:
    int numTeeth = 15;
};

#endif //TEST2_HPP





