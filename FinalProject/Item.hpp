/*********************************************************************
 ** Author: Rob Navarro
 ** Date: December 8, 2015
 ** Description: This defines the interface for the Item class.
 *********************************************************************/

#ifndef Item_hpp
#define Item_hpp

#include <iostream>
#include <stdio.h>


class Item {
private:
    std::string name;
public:
    Item(std::string);
    std::string getName();
    
    
};

#endif /* Item_hpp */
