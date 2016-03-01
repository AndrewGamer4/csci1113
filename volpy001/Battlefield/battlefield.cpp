#include <string>
#include <iostream>
#include <vector>

class WarriorBase {
protected:
    std::string m_name;
    int m_health;
protected:
    WarriorBase() : m_health(100) { // constructor, since no return type AND same name as class, so we want to initialize health with 100

    }
    WarriorBase(int health) : m_health(health) {// another constructor, except in this one the creator or child desides what the health is

    }

public:
    std::string name() const { return m_name; };
    void name(const std::string &n) { m_name = n; }
public:
    int health() const { return m_health; }
    void addHealth(int health) { m_health += health; } // no issues with this, I assume
public:
    virtual int hitAnother(WarriorBase& other) { return 0; } // for later
public:
    virtual bool getHit(int strength) { return true; } //is this the only palce we say that it's virtual? yes, you can also call it virtual in the children, but it's not required
    bool getHitPlain(int strength) { return true; } //is this the only palce we say that it's virtual? yes, you can also call it virtual in the children, but it's not required
};

class Orc : public WarriorBase {
public:
    Orc() : WarriorBase(200) {} // our orc constructor calls his parent (cmb) constructor with a much larger health than the default
public:
    bool getHitPlain(int strength)
    {
        return false;
    }
    bool getHit(int strengthOfHit) override {
        if (strengthOfHit < 10) // too soft a hit
        {
            return true;
        }

        if (strengthOfHit < 50) // medium, hurts
        {
            m_health -= strengthOfHit / 2;
            return m_health > 0; // returns true if still alive, false if dead'ish
        }

        m_health -= strengthOfHit; // full hit, full pain
        return m_health > 0; // returns true if still alive, false if dead'ish
    }
};

class Elf : public WarriorBase {
public:
    Elf() : WarriorBase(125) {}
public:
    bool getHitPlain(int strength) { return false; } //is this the only palce we say that it's virtual? yes, you can also call it virtual in the children, but it's not required
    bool getHit(int strengthOfHit) override {
        if (strengthOfHit < 10) // too soft a hit
        {
            return true;
        }

        if (strengthOfHit < 30) // medium, hurts
        {
            m_health -= strengthOfHit / 2;
            return m_health > 0; // returns true if still alive, false if dead'ish
        }

        m_health -= strengthOfHit; // full hit, full pain
        return m_health > 0; // returns true if still alive, false if dead'ish
    }
};

class Human : public WarriorBase {
public:
    bool getHitPlain(int strength) { return false; } //is this the only palce we say that it's virtual? yes, you can also call it virtual in the children, but it's not required
    bool getHit(int strengthOfHit) override {
        if (strengthOfHit < 15) // too soft a hit
        {
            return true;
        }

        if (strengthOfHit < 15) // medium, hurts
        {
            m_health -= strengthOfHit / 2;
            return m_health > 0; // returns true if still alive, false if dead'ish
        }

        m_health -= strengthOfHit; // full hit, full pain
        return m_health > 0; // returns true if still alive, false if dead'ish
    }
};

int main()
{
    // so let's simulate an orc and ahuman hitting each other
    std::vector<WarriorBase*> goodGuys;
    std::vector<WarriorBase*> badGuys;

    // so, if we change getHit to getHitPlain everywhere, we would expect instant death for eerybody, since getHitPlain returns false, except in the base
    // so, we have two vectors, one for goo, one for bad, so let's create some
    WarriorBase *cmb = new Orc;
    cmb->name("Orc1");
    badGuys.push_back(cmb);

    cmb = new Elf;
    cmb->name("Elf1");
    goodGuys.push_back(cmb);

    cmb = new Elf;
    cmb->name("Elf2");
    goodGuys.push_back(cmb);

    cmb = new Human;
    cmb->name("HumAhnold");
    goodGuys.push_back(cmb);
    cmb->addHealth(50);

    cmb = new Human;
    cmb->name("HumGump");
    goodGuys.push_back(cmb);

    for (auto *c : goodGuys) {
        std::cout << "G: " << c->name() << " health:" << c->health() << std::endl;
    }

    for (auto *c : badGuys) {
        std::cout << "B: " << c->name() << " health:" << c->health() << std::endl;
    }

    for (int i = 1; i < 15; ++i) { // I don't want to do a real battlefield, so I'm just going to go around and hiteverybody with the same force
        int force = i * 10; // every loop we'll slap 10-health points off of everyone

        for (WarriorBase *c : goodGuys) {
            auto alive = c->getHitPlain(force);
            if (alive) std::cout << c->name() << " hit with " << force << " is alive:" << alive << " health:" << c->health() << std::endl;
        }

        
        for (WarriorBase *c : badGuys) { //okay got it. 
            auto alive = c->getHitPlain(force);
            if (alive) std::cout << c->name() << " hit with " << force << " is alive:" << alive << " health:" << c->health() << std::endl;
        }
    }

    // this is a bad bad example, but the things from it that will be similar in FS
    //    virtual functions allow the caller (or source code) to have the same algorithm, but the effects differ depending on both the TYPE and the instance
    //    let me show you what I mean
    // so so far the effects differ by TYPE but not by instance -- both elfs die at same time, both humans at a diff time, 
    // but we want to give some Arnold's more health
    // so basically, humans have some common stuff, but individual humans have different characteriscs
    // also, your algorithm can have an effect on which cmb's actually get hit
    // so, together, you basically can have any "reality" to you simulation by both creating realistic types (dog, cat, etc) and realistic mix of individuals (arsik1, a2, lexi1, lucy, etc)
    // so far so good? y -- ok, so if we DIDN'T have polymorphism, watch
    // so far so good? yeah. i see how this will work with FS -- wtch
    // so, in fact, everybody lives and nobody dies -- why?
    // ??? forgot the words -- what's differnt getHit vs getHitPlain signatures?  how do we tell the compiler to call the children's function and not the parents? with the pointer?
    // c->getHitPlain(force) is thru a pointer
    // c->getHit(force) is also thru a pointer
    // nothing changed, and yet if I call getHit it chooses the children's health code, but if I call getHitPlain it chooses the parent's
    // so, what is the difference between getHit and getHitPlain to account for this children vs parent code?
    //the override? no
    //where do i look? parent
    // virtual yes
    // without virtual, the compiler looks at the type of the pointer itself
    // with irtual, it looks at what the pointer points to, and for us, it points to each individual race of combats
    WarriorBase *oneGoodGuy = goodGuys[0];
    oneGoodGuy->getHit(0);
    oneGoodGuy->getHitPlain(0);

    // if I call oneGoodGuy->getHitPlain, what does the COMPILER know at this point on line 167?
    //the location of the pointer? yes, but what else -- there are three words on line 167 -- the compiler has to figure out this:
    // so compiler has to call a method on each line 170 and 171, so which methods does it know about?
    // you and I know what goodGuys[0] is, since we hard coded it to be Ahnold, but the compiler has no idea (we could randomly generate,e tc)
    // so the only thing compiler knows about oneGoodGuy at location 167 is that it is a ?
    // no, of course he knows what the variable is called -- it says so on line 
    // you're the compiler -- which function do you call on 168? which do you call on 169? the body of the code ???
    // getHit and getHitPlain. i'm going to go to bed soon. I pulled an all nighter last night and i'm dying now. 

    // ok, but you'll need to watch some C++ ideos as well --you're not grasping some key concepts, and until you do, you'll struggle
    // but we'll continue;
    //gn. night dad.
    return 0;
}

