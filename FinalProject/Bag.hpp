/*********************************************************************
 ** Author: Rob Navarro
 ** Date: December 8, 2015
 ** Description: This defines the interface for the Bag class.
 *********************************************************************/

#ifndef Bag_hpp
#define Bag_hpp

#include <stdio.h>
#include <vector>
#include "Item.hpp"

class Bag{
private:
    std::vector<Item*> myBag;
    int limit;
public:
    Bag();
    void add(Item*);
    bool find(std::string);
};

#endif /* Bag_hpp */
