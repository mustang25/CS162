/*********************************************************************
 ** Author: Rob Navarro
 ** Date: November 22, 2015
 ** Description: This implements the Creature class.
 *********************************************************************/

#include "Creature.hpp"
#include "Die.hpp"

//getter/setter methods for creature class
Creature::~Creature() {}

int Creature::getArmor() {
    return armor;
}

int Creature::getStrength() {
    return strength;
}

void Creature::setStrength(int newStrength) {
    strength = newStrength;
}

bool Creature::getAlive() {
    return alive;
}

void Creature::setAlive(bool newAlive) {
    alive = newAlive;
}

std::string Creature::getType() {
    return type;
}

bool Creature::getAchilles() {
    return cutAchilles;
}

void Creature::setAchilles(bool newAchilles) {
    cutAchilles = newAchilles;
}

void Creature::setName(std::string newName) {
    name = newName;
}

std::string Creature::getName() {
    return name;
}

void Creature::setTeam(std::string newTeam) {
    team = newTeam;
}

std::string Creature::getTeam() {
    return team;
}

//Default constructor for the Barbarian subclass
Barbarian::Barbarian() {
    type = "Barbarian";
    armor = 0;
    strength = 12;
    cutAchilles = false;
    alive = true;
}

Barbarian::~Barbarian() {}

//Implementation of the heal function. If the 6 sided die rolls and positive number then that amount from the roll is added back to the creatures health.
void Barbarian::heal() {
    Die d1(6);
    int rollVal;
    rollVal = d1.roll();
    int currentStrength = getStrength();
    if (rollVal % 2 == 0) {
        if (rollVal + currentStrength >= 12) {
            setStrength(12);
        }
        else {
            setStrength(rollVal + currentStrength);
        }
    }
}

//Implementation of the attack function. If the achilles is cut damage is reduced by 1/2.
int Barbarian::attack() {
    Die d1(6);
    Die d2(6);
    if (cutAchilles) {
        return (d1.roll() + d2.roll())/2;
    }
    return d1.roll() + d2.roll();
}

//Implementation of the defense function
int Barbarian::defense() {
    Die d1(6);
    Die d2(6);
    return d1.roll() + d2.roll();
}

//Default Goblin constructor
Goblin::Goblin() {
    type = "Goblin";
    armor = 3;
    strength = 8;
    cutAchilles = false;
    alive = true;
}

Goblin::~Goblin() {}

//Implementation of the heal function. If the 6 sided die rolls and positive number then that amount from the roll is added back to the creatures health.
void Goblin::heal() {
    Die d1(6);
    int rollVal;
    rollVal = d1.roll();
    int currentStrength = getStrength();
    if (rollVal % 2 == 0) {
        if (rollVal + currentStrength >= 8) {
            setStrength(8);
        }
        else {
            setStrength(rollVal + currentStrength);
        }
    }
}

//Implementatin of the attack function
int Goblin::attack() {
    Die d1(6);
    Die d2(6);
    return d1.roll() + d2.roll();
}

//Implementation of the defense fucntion
int Goblin::defense() {
    Die d1(6);
    return d1.roll();
}

//Default Reptile constructor
Reptile::Reptile() {
    type = "Reptile";
    armor = 7;
    strength = 18;
    cutAchilles = false;
    alive = true;
}

Reptile::~Reptile() {}

//Implementation of the heal function. If the 6 sided die rolls and positive number then that amount from the roll is added back to the creatures health.
void Reptile::heal() {
    Die d1(6);
    int rollVal;
    rollVal = d1.roll();
    int currentStrength = getStrength();
    if (rollVal % 2 == 0) {
        if (rollVal + currentStrength >= 18) {
            setStrength(18);
        }
        else {
            setStrength(rollVal + currentStrength);
        }
    }
}

//Implementation of the attack function. If the achilles is cut damage is reduced by 1/2.
int Reptile::attack() {
    Die d1(6);
    Die d2(6);
    Die d3(6);
    if (cutAchilles) {
        return (d1.roll() + d2.roll() + d3.roll())/2;
    }
    return d1.roll() + d2.roll() + d3.roll();
}

//Implementation of the defense function
int Reptile::defense() {
    Die d1(6);
    return d1.roll();
}

//Defualt BlueMen function
BlueMen::BlueMen() {
    type = "Blue Men";
    armor = 3;
    strength = 12;
    cutAchilles = false;
    alive = true;
}

BlueMen::~BlueMen() {}

//Implementation of the heal function. If the 6 sided die rolls and positive number then that amount from the roll is added back to the creatures health.
void BlueMen::heal() {
    Die d1(6);
    int rollVal;
    rollVal = d1.roll();
    int currentStrength = getStrength();
    if (rollVal % 2 == 0) {
        if (rollVal + currentStrength >= 12) {
            setStrength(12);
        }
        else {
            setStrength(rollVal + currentStrength);
        }
    }
}

//Implementation of the attack function. If the achilles is cut damage is reduced by 1/2.
int BlueMen::attack() {
    Die d1(10);
    Die d2(10);
    if (cutAchilles) {
        return (d1.roll() + d2.roll())/2;
    }
    return d1.roll() + d2.roll();
}

//Implementation of the defense function.
int BlueMen::defense() {
    Die d1(6);
    Die d2(6);
    Die d3(6);
    return d1.roll() + d2.roll() + d3.roll();
}

//Default constructor for the Shadow class
Shadow::Shadow() {
    type = "Shadow";
    armor = 0;
    strength = 12;
    cutAchilles = false;
    alive = true;
}

Shadow::~Shadow() {}

//Implementation of the heal function. If the 6 sided die rolls and positive number then that amount from the roll is added back to the creatures health.
void Shadow::heal() {
    Die d1(6);
    int rollVal;
    rollVal = d1.roll();
    int currentStrength = getStrength();
    if (rollVal % 2 == 0) {
        if (rollVal + currentStrength >= 12) {
            setStrength(12);
        }
        else {
            setStrength(rollVal + currentStrength);
        }
    }
}

//Implementation of the attack function. If the achilles is cut damage is reduced by 1/2.
int Shadow::attack() {
    Die d1(10);
    Die d2(10);
    if (cutAchilles) {
        return (d1.roll() + d2.roll())/2;
    }
    return d1.roll() + d2.roll();
}

//Implementation of the defense function. For Shadow if the random number is 2 a value of -1 is returned.
//This allows for the shadow object to avoid attack during this turn
int Shadow::defense() {
    Die d1(6);
    int i = rand() % 2 + 1;
    if (i == 2) {
        return -1;
    }
    return d1.roll();
}