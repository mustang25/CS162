/*********************************************************************
 ** Author: Rob Navarro
 ** Date: December 8, 2015
 ** Description: This defines the interface for the Player class.
 *********************************************************************/

#ifndef Player_hpp
#define Player_hpp

#include <stdio.h>
#include <iostream>
#include "Item.hpp"
#include "Bag.hpp"

class Player {
private:
    std::string name;
    int health;
    int tornado ;
    bool master;
    bool office;
    bool entry;
    bool garage;
    bool bedroom;
    bool dining;
    bool kitchen;
    bool living;
    bool basement;
    
public:
    Player();
    void setName(std::string);
    std::string getName();
    void addHealth(int);
    void subHealth(int);
    int getHealth();
    int getTornado();
    void addTornado(int);
    void subTornado(int);
    //These bools track if a player has entered a room or not
    bool getMaster();
    bool getOffice();
    bool getEntry();
    bool getGarage();
    bool getBedroom();
    bool getKitchen();
    bool getDining();
    bool getLiving();
    bool getBasement();
    //Set functions are used to mark a room as visited
    void setMaster();
    void setOffice();
    void setEntry();
    void setGarage();
    void setBedroom();
    void setDining();
    void setKitchen();
    void setLiving();
    void setBasement();

};

#endif /* Player_hpp */
