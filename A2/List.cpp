/*********************************************************************
 ** Author: Rob Navarro
 ** Date: October 25, 2015
 ** Description: This implements the List class
 *********************************************************************/

#include "List.hpp"

List::List(){
    
};


void List::addItem() {
    std::string newName;
    std::string newUnit;
    int newToBuy;
    double newUnitPrice;
    int duplicateItemLoc = 0;
    std::string update;
    unsigned long length = shoppingList.size();
    bool duplicate = false;
    
    //Prompt the user to enter what new item they'd like to ask
    std::cout << "What is the name of the item that you would like to add? ";
    std::cin.ignore();
    std::getline(std::cin, newName);
    std::cout << "What type of unit does the item have? ";
    std::getline(std::cin, newUnit);
    std::cout << "How many " << newName << "s do you want to buy? ";
    std::cin >> newToBuy;
    std::cout << "What is the price of a single " << newName << "? ";
    std::cin >> newUnitPrice;
    
    //Initialize newItem with user info entered above
    Item newItem(newName, newUnit, newToBuy, newUnitPrice);
    
    //Check if item is already in shopping list
    for (int i = 0; i < length; i++) {
        if (shoppingList[i] == newItem) {       //If duplicate item is found
            duplicate = true;                   //Set duplicate to true
            duplicateItemLoc = i;               //Store the location of the duplicate item
        }
    }
    
    //If the item is already found in list ask the user if they'd like to update quantity
    if (duplicate == true) {
        std::cout << "This item is already in your list, would you like to update the quantity?" << std::endl;
        std::cout << "Enter 1 to update (any other value will exit back to main menu): ";
        std::cin >> update;                     //Store users choice for update
    }
    
    //If item is not found in list add it to shopping list vector
    else {
        shoppingList.push_back(newItem);
    }
    
    //If the user decided to update item, prompt them for new value
    if (update == "1") {
        std::cout << "The current to buy of " << shoppingList[duplicateItemLoc].getName() << " is " << shoppingList[duplicateItemLoc].getToBuy() << std::endl;
        std::cout << "what would you like to update it to? ";
        std::cin >> newToBuy;
        //Update the to buy value
        shoppingList[duplicateItemLoc].setToBuy(newToBuy);
        std::cout << "The to buy of " << shoppingList[duplicateItemLoc].getName() << "has been updated to " << shoppingList[duplicateItemLoc].getToBuy();
    }
}

//Delete items from shopping list
void List::deleteItem() {
    unsigned long length = shoppingList.size();                 //store size of shopping list vect
    int numDelete = -1;
    std::string toDelete;
    std::cout << "What item would you like to delete? ";
    std::cin >> toDelete;                                       //Store name of item to be deleted
    
    for (int i = 0; i < length; i++) {
        if (toDelete == shoppingList[i].getName()) {            //If the name of the item is found store the value
            numDelete = i;
        }
    }
    
    if (numDelete > -1) {
        shoppingList.erase (shoppingList.begin() + numDelete);  //Delete item from shopping list based on input above
    }
    
}

void List::printList() {
    unsigned long length = shoppingList.size();
    double totalPriceList;
    double totalPriceItem;
    std::cout << "Name, Unit, To Buy, Single Price, Total Price" << std::endl;
    for (int i = 0; i < length; i++) {
        std::cout << i + 1 << ". ";
        std::cout << shoppingList[i].getName() << ", ";
        std::cout << shoppingList[i].getUnit() << ", ";
        std::cout << shoppingList[i].getToBuy() << ", ";
        printf("$%4.2f", shoppingList[i].getUnitPrice());           //formatting numbers for currency
        std::cout << ", ";
        //Determine total price of item
        totalPriceItem = shoppingList[i].getToBuy() * shoppingList[i].getUnitPrice();
        printf("$%4.2f", totalPriceItem);
        std::cout << std::endl;
        //Add total price of item to the total price of the shopping list
        totalPriceList += totalPriceItem;
    }
    //Display total price of shopping list
    std::cout << "----------------------------------------------" << std::endl;
    std::cout << "The total price of the shopping list is: $";
    printf("%4.2f", totalPriceList);
    std::cout << std::endl;
    std::cout << std::endl;
}