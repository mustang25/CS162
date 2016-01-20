/*********************************************************************
 ** Author: Rob Navarro
 ** Date: October 25, 2015
 ** Description: This defines the interface for the List class.
 *********************************************************************/

#ifndef List_hpp
#define List_hpp

#include "Item.hpp"
#include <vector>



class List {
private:
    std::vector<Item> shoppingList;
public:
    List();
    void addItem();
    void deleteItem();
    void printList();
};


#endif /* List_hpp */
