/*********************************************************************
 ** Author: Rob Navarro
 ** Date: October 25, 2015
 ** Description: This is the main program for the ShoppingList program
 ** The user can build a shopping list through the main menu that is located here.
 ** The user can also exit the program by selecting 4 from the main menu.
 ** The Shopping List has the ability to add items, remove items, and display the list.
 *********************************************************************/

#include <iostream>
#include <string>
#include "List.hpp"
using std::cout;
using std::cin;
using std::endl;
using std::string;

int main(int argc, const char * argv[]) {
    
    bool endList = false;           //Set to false so that the list cont until user exits
    string userSelection;
    List shopping;                  //Declare a shopping list object
    
    cout << "Welcome to your shopping list, please choose a selection below to get started!" << endl;
    
    //Do loop for shoppin list, the program continues until the user selects 4 to exit
    do {
        //Main menu for shopping list
        cout << "Please select what you would like to do" << endl;
        cout << "1. Add item to list" << endl;
        cout << "2. Delete item from list" << endl;
        cout << "3. Display list" << endl;
        cout << "4. Exit list" << endl;
        cin >> userSelection;
        cout <<endl;
        
        if (userSelection == "1") {
            shopping.addItem();
        }
        
        else if (userSelection == "2") {
            shopping.deleteItem();
        }
        
        else if (userSelection == "3") {
            shopping.printList();
        }
        
        else if (userSelection == "4") {
            endList = true;
        }
        
        else {
            cout << "Invalid selection, please try again." << endl;
        }

        
    } while (!endList);

    return 0;
}
