/*********************************************************************
 ** Author: Rob Navarro
 ** Date: December 8, 2015
 ** Description: This implements the interface for the Item class.
 *********************************************************************/

#include "Item.hpp"



Item::Item(std::string newName) {
    name = newName;
}

std::string Item::getName() {
    return name;
}