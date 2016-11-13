/*********************************************************************
 ** Author: Rob Navarro
 ** Date: November 8, 2015
 ** Description: This defines the interface for the Creature class.
 *********************************************************************/

#ifndef Creature_hpp
#define Creature_hpp

#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string>
#include "Die.hpp"

class Creature {
protected:
    std::string type;
    int armor;
    int strength;
    bool alive;
    bool cutAchilles;
public:
    virtual int attack() = 0;
    virtual int defense() = 0;
    int getArmor();
    int getStrength();
    void setStrength(int);
    bool getAlive();
    void setAlive(bool);
    std::string getType();
    bool getAchilles();
    void setAchilles(bool);
};

class Barbarian: public Creature {
private:
public:
    Barbarian();
    int attack();
    int defense();
    void setAchilles(bool);
    
};

class Goblin: public Creature {
public:
    Goblin();
    int attack();
    int defense();
};

class Reptile: public Creature {
private:
public:
    Reptile();
    int attack();
    int defense();
    void setAchilles(bool);
};

class BlueMen: public Creature {
private:
public:
    BlueMen();
    int attack();
    int defense();
    void setAchilles(bool);
};

class Shadow: public Creature {
private:
public:
    Shadow();
    int attack();
    int defense();
    void setAchilles(bool);
};

#endif /* Creature_hpp */
