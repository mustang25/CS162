/*********************************************************************
 ** Author: Rob Navarro
 ** Date: December 8, 2015
 ** Description: This defines the interface for the Space class.
 *********************************************************************/


#ifndef Space_hpp
#define Space_hpp

#include <stdio.h>
#include <stdlib.h>
#include "Player.hpp"
#include "Item.hpp"


class Space {
private:
    Space* left;
    Space* up;
    Space* right;
    Space* down;
    std::string name;
    Item* roomItem;
public:
    virtual void special(Player*) = 0;
    void setPointers(Space*, Space*, Space*, Space*);
    void setName(std::string);
    std::string getName();
    Space* getUp();
    Space* getDown();
    Space* getLeft();
    Space* getRight();
    void addItem(Item*);
    Item* getItem();
    void deleteItem();
};

class MasterBedroom: public Space {
private:
public:
    MasterBedroom(std::string);
    void special(Player*);
};

class Bedroom: public Space {
private:
public:
    Bedroom(std::string);
    void special(Player*);
};

class Living: public Space {
private:
public:
    Living(std::string);
    void special(Player*);
};

class Basement: public Space {
private:
public:
    Basement(std::string);
    void special(Player*);
};

class Garage: public Space {
private:
public:
    Garage(std::string);
    void special(Player*);
};

class Office: public Space {
private:
public:
    Office(std::string);
    void special(Player*);
};

class Entry: public Space {
private:
public:
    Entry(std::string);
    void special(Player*);
};

class Outside: public Space {
private:
public:
    Outside(std::string);
    void special(Player*);
};

class Dining: public Space {
private:
public:
    Dining(std::string);
    void special(Player*);
};

class Kitchen: public Space {
private:
public:
    Kitchen(std::string);
    void special(Player*);
};





#endif /* Space_hpp */
