/*********************************************************************
 ** Author: Rob Navarro
 ** Date: December 8, 2015
 ** Description: This implements the interface for the Bag class.
 *********************************************************************/


#include "Bag.hpp"

//Constructor for Bag, limit is set to 4
Bag::Bag() {
    limit = 4;
}

//Function to add item to bag, also checks if bag is full
void Bag::add(Item* newItem) {
    if (myBag.size() == limit) {
        std::cout << "Your bag is full and the item could not be added" << std::endl;
    }
    else {
        myBag.push_back(newItem);
    }
}

//Returns t/f if item is in bag
bool Bag::find(std::string findItem) {
    bool returnBool = false;
    for (int i = 0; i < myBag.size(); i++) {
        if (myBag[i]->getName() == findItem) {
            returnBool = true;
        }
    }
    return returnBool;
}


