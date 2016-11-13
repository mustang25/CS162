/*********************************************************************
 ** Author: Rob Navarro
 ** Date: October 25, 2015
 ** Description: This implements the Item class
 *********************************************************************/
#include "Item.hpp"

Item::Item() {
    toBuy = 0;
    unitPrice = 0;
}

//Construcotr that accepts all parameters needed to set items
Item::Item(std::string newName, std::string newUnit, int newToBuy, double newUnitPrice) {
    setName(newName);
    setUnit(newUnit);
    setToBuy(newToBuy);
    setUnitPrice(newUnitPrice);
}

//Overload = operator to compare the names of two items
bool operator==(Item a, Item b) {
    return a.getName() == b.getName();
}


//Getter and setter methods for item class
void Item::setName(std::string newName) {
    name = newName;
}

std::string Item::getName() {
    return name;
}

void Item::setUnit(std::string newUnit) {
    unit = newUnit;
}

std::string Item::getUnit() {
    return unit;
}

void Item::setToBuy(int newToBuy) {
    toBuy = newToBuy;
}

int Item::getToBuy() {
    return toBuy;
}

void Item::setUnitPrice(double newUnitPrice) {
    unitPrice = newUnitPrice;
}

double Item::getUnitPrice() {
    return unitPrice;
}


