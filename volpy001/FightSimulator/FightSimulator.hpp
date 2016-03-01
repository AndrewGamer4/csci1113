#pragma once
#ifndef FIGHT_SIMULATOR
#define FIGHT_SIMULATOR


enum class Stats_e
{
    WS,
    BS,
    S,
    T,
    W,
    I,
    A,
    Ld,
    SV,
    Invul,
    MAX,

};

class Base
{
protected:
    int m_stats[static_cast<int>(Stats_e::MAX)];
    void stats_m(std::initializer_list<int> stats);
    void displayStats();
public: 
    void setBallisticSkill(int val);
    int getBallisticSkill() const;
public: 
    void setInvul(int val);
    int getInvul() const;
public: 
    void setWeaponSkill(int val);
    int getWeaponSkill() const;
public: 
    void setStrength(int val);
    int getStrength() const;
public: 
    void setToughness(int val);
    int getToughness() const;
public: 
    void setWounds(int val);
    int getWounds() const;
public: 
    void setInitiative(int val);
    int getInitiative() const;
public: 
    void setAttacks(int val);
    int getAttacks() const;
public: 
    void setLeadership(int val);
    int getLeadership() const;
public: 
    void setArmor(int val);
    int getArmor() const;

public:
    void nonVirtualFunction();
    virtual void virtualFunction();
};

class Zarakynel : public Base
{
public:
    Zarakynel();
public:
    void nonVirtualFunction();
    void virtualFunction();
};
class Anggrath : public Base
{
public:
    Anggrath();
public:
    void nonVirtualFunction();
    virtual void virtualFunction();
};





#endif //FIGHT_SIMULATOR

