/*********************************************************************
 ** Author: Rob Navarro
 ** Date: October 25, 2015
 ** Description: This defines the interface for the Item class.
 *********************************************************************/

#ifndef Item_hpp
#define Item_hpp

#include <iostream>
#include <cstdio>
#include <string>

class Item {
private:
    std::string name;
    std::string unit;
    int toBuy;
    double unitPrice;
public:
    Item();
    Item(std::string, std::string, int, double);
    void setName(std::string);
    std::string getName();
    void setUnit(std::string);
    std::string getUnit();
    void setToBuy(int);
    int getToBuy();
    void setUnitPrice(double);
    double getUnitPrice();
    friend bool operator== (Item a, Item b);
};

#endif /* Item_hpp */
