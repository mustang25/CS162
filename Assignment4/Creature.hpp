/*********************************************************************
 ** Author: Rob Navarro
 ** Date: November 22, 2015
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
    std::string name;
    int armor;
    int strength;
    std::string team;
    bool alive;
    bool cutAchilles;
public:
    virtual int attack() = 0;
    virtual int defense() = 0;
    virtual void heal() = 0;
    virtual ~Creature();
    int getArmor();
    int getStrength();
    void setStrength(int);
    bool getAlive();
    void setAlive(bool);
    std::string getType();
    bool getAchilles();
    void setAchilles(bool);
    void setName(std::string);
    std::string getName();
    void setTeam(std::string);
    std::string getTeam();
};

class Barbarian: public Creature {
private:
public:
    Barbarian();
    ~Barbarian();
    int attack();
    int defense();
    void heal();
    void setAchilles(bool);
    
};

class Goblin: public Creature {
public:
    Goblin();
    ~Goblin();
    int attack();
    int defense();
    void heal();
};

class Reptile: public Creature {
private:
public:
    Reptile();
    ~Reptile();
    int attack();
    int defense();
    void heal();
    void setAchilles(bool);
};

class BlueMen: public Creature {
private:
public:
    BlueMen();
    ~BlueMen();
    int attack();
    int defense();
    void heal();
    void setAchilles(bool);
};

class Shadow: public Creature {
private:
public:
    Shadow();
    ~Shadow();
    int attack();
    int defense();
    void heal();
    void setAchilles(bool);
};

#endif /* Creature_hpp */
