/*********************************************************************
 ** Author: Rob Navarro
 ** Date: December 8, 2015
 ** Description: This game uses math and a scavenger hunt to have the 
 ** player search for a way to enter the basement. A tornado is quickly
 ** approaching the house and the user must get in the basement before 
 ** it hits. Find the key and the basement will unlock, which will allow
 ** the user to win.
 *********************************************************************/

#include <iostream>
#include <vector>
#include <stdlib.h>
#include "Space.hpp"
#include "Item.hpp"
#include "Player.hpp"
#include "Bag.hpp"

int main(int argc, const char * argv[]) {
    Space* currentLocation;
    std::string userName;
    std::string userSelection;
    bool win = false;
    bool validInput = false;
    std::vector<Space*> spaces;
    std::vector<Item*> items;
    Bag* userBag = new Bag;
    Player* p1 = new Player;
    srand(time(NULL));
    
    
    //We will declare all of the spaces and place them in a vector for easy storage
    //We will then update the pointers for each space so that it points to the correct place
    spaces.push_back(new MasterBedroom("Master Bedroom"));    //0
    spaces.push_back(new Office("Office"));     //1
    spaces.push_back(new Entry("Entry"));      //2
    spaces.push_back(new Garage("Garage"));     //3
    spaces.push_back(new Bedroom("Small Bedroom"));    //4
    spaces.push_back(new Dining("Dining Room"));     //5
    spaces.push_back(new Kitchen("Kitchen"));    //6
    spaces.push_back(new Living("Living Room"));     //7
    spaces.push_back(new Basement("Basement"));   //8
    spaces.push_back(new Outside("Outside - Don't go out here!"));
    
    spaces[0]->setPointers(spaces[8], spaces[9], spaces[1], spaces[7]);     //Master
    spaces[1]->setPointers(spaces[0], spaces[9], spaces[9], spaces[2]);     //Office
    spaces[2]->setPointers(spaces[7], spaces[1], spaces[9], spaces[3]);     //Entry
    spaces[3]->setPointers(spaces[4], spaces[2], spaces[9], spaces[9]);     //Garage
    spaces[4]->setPointers(spaces[5], spaces[7], spaces[3], spaces[9]);     //Bedroom
    spaces[5]->setPointers(spaces[9], spaces[6], spaces[4], spaces[9]);     //Dining
    spaces[6]->setPointers(spaces[9], spaces[8], spaces[7], spaces[5]);     //Kitchen
    spaces[7]->setPointers(spaces[6], spaces[0], spaces[2], spaces[4]);     //Living
    spaces[8]->setPointers(spaces[9], spaces[9], spaces[0], spaces[6]);     //Basement
    
    items.push_back(new Item("Flashlight"));
    items.push_back(new Item("Key"));
    items.push_back(new Item("Tools"));
    items.push_back(new Item("Food"));
    int randomNum = 0;
    
    //Place items randomly throughout the house
    for (int i = 0; i < items.size(); i++) {
        randomNum = rand() % 7 + 0;
        if (spaces[randomNum]->getItem() != NULL) {
            i--;
        }
        else {
            spaces[randomNum]->addItem(items[i]);
        }
    }
    
    std::cout << "Welcome to tornado survival!" << std::endl;
    //Get player name to have add a little personality to the game. Store the name in the player class.
    std::cout << "What is your first name? ";
    std::cin >> userName;
    p1->setName(userName);
    currentLocation = spaces[0];
    
    //Intro explaining what it going on
    std::cout << "Hello " << p1->getName() << ", you have awoken to the sounds of your emergency radio going off warning you of an approaching torando. You must make it to the basement before the tornado hits your house! Move around the house and solve puzzles in each room to see if there is anything useful in the room. Be careful though... if you answer incorrectly it could cost you dearly!" << std::endl;
    
    std::cout << std::endl;
    
    //Introduce player to first puzzle... this one should be easy.
    std::cout << "You jump out of bed and are ready to start searching the house, first solve this simple puzzle to see if anything valuable is in here!" << std::endl;
    currentLocation->special(p1);
    if (currentLocation->getItem() != NULL) {
        std::cout << "You added a " << (currentLocation->getItem())->getName() << " to your bag." <<std::endl;
        userBag->add(currentLocation->getItem());
        currentLocation->deleteItem();
    }
    std::cout << std::endl;
    
    //This loop will keep the player moving until they win, until the tornado arrives, or until they die.
    do {
        //Display how many turns until the tornado arrives and the current player health
        std::cout << "You have " << p1->getTornado() << " turns until the tornado arrives!" << std::endl;
        std::cout << "Your current health is: " << p1->getHealth() << std::endl;
        std::cout << std::endl;

        //This do loop prompts the user to move around the house. If the chooose to go outside the player
        //will lose turns and health. They will remain in the same room that they were in before.
        //Any valid option will move the player into the new room. If an incorrect choice is selected the
        //user will be notified and asked to reenter their selection.
        do {
            validInput = false;
            std::cout << "You are currently in the " << currentLocation->getName() << " where would you like to move next? " << std::endl;
            std::cout << "1. Left: " << (currentLocation->getLeft())->getName() << std::endl;
            std::cout << "2. Up: " << (currentLocation->getUp())->getName() << std::endl;
            std::cout << "3. Right: " << (currentLocation->getRight())->getName() << std::endl;
            std::cout << "4. Down: " << (currentLocation->getDown())->getName() << std::endl;
            std::cout << "Selection (enter the corresponding number): ";
            std::cin >> userSelection;
            
            if (userSelection == "1") {
                if (currentLocation->getLeft()->getName() == "Outside - Don't go out here!") {
                    currentLocation->getLeft()->special(p1);
                    if (p1->getTornado() <= 0 || p1->getHealth() <= 0) {
                        validInput = true;
                    }
                    else {
                        std::cout << "You have " << p1->getTornado() << " turns until the tornado hits!" << std::endl;
                        std::cout << "Your current health is: " << p1->getHealth() << std::endl;
                        std::cout << std::endl;
                    }
                }
                else {
                    currentLocation = currentLocation->getLeft();
                    p1->subTornado(1);
                    validInput = true;
                }
            }
            
            else if (userSelection == "2") {
                if (currentLocation->getUp()->getName() == "Outside - Don't go out here!") {
                    currentLocation->getUp()->special(p1);
                    if (p1->getTornado() <= 0 || p1->getHealth() <= 0) {
                        validInput = true;
                    }
                    else {
                        std::cout << "You have " << p1->getTornado() << " turns until the tornado hits!" << std::endl;
                        std::cout << "Your current health is: " << p1->getHealth() << std::endl;
                        std::cout << std::endl;
                    }
                }
                else {
                    currentLocation = currentLocation->getUp();
                    p1->subTornado(1);
                    validInput = true;
                }
            }
            
            else if (userSelection == "3") {
                if (currentLocation->getRight()->getName() == "Outside - Don't go out here!") {
                    currentLocation->getRight()->special(p1);
                    if (p1->getTornado() <= 0 || p1->getHealth() <= 0) {
                        validInput = true;
                    }
                    else {
                        std::cout << "You have " << p1->getTornado() << " turns until the tornado hits!" << std::endl;
                        std::cout << "Your current health is: " << p1->getHealth() << std::endl;
                        std::cout << std::endl;
                    }
                }
                else {
                    currentLocation = currentLocation->getRight();
                    p1->subTornado(1);
                    validInput = true;
                    if (p1->getTornado() <= 0) {
                        validInput = true;
                    }
                }
                
            }
            
            else if (userSelection == "4") {
                if (currentLocation->getDown()->getName() == "Outside - Don't go out here!") {
                    currentLocation->getDown()->special(p1);
                    if (p1->getTornado() <= 0 || p1->getHealth() <= 0) {
                        validInput = true;
                    }
                    else {
                        std::cout << "You have " << p1->getTornado() << " turns until the tornado hits!" << std::endl;
                        std::cout << "Your current health is: " << p1->getHealth() << std::endl;
                        std::cout << std::endl;
                    }
                }
                else {
                    currentLocation = currentLocation->getDown();
                    p1->subTornado(1);
                    validInput = true;
                    if (p1->getTornado() <= 0) {
                        validInput = true;
                    }
                }
                
            }
            
            else {
                std::cout << "You didn't enter a valid selection... please try again." << std::endl;
                std::cout << std::endl;
            }
        } while (!validInput);
        
        std::cout << std::endl;
        
        //Check if the user is in the basement... if they are check if they have the key. If they have the
        //key set win = true, else tell the user that the door is locked and they need a key.
        if (currentLocation->getName() == "Basement") {
            if (userBag->find("Key")) {
                win = true;
            }
            else {
                std::cout << "Hmmm the door to the basement is locked... it looks like you need a key." << std::endl;
            }
        }
        
        //Check for items in room if the player is alive, haven't won, and the tornado hasn't arrived.
        if (p1->getTornado() > 0 && !win && p1->getHealth() > 0) {
            currentLocation->special(p1);
            
            if (currentLocation->getItem() != NULL) {
                std::cout << "You added a " << (currentLocation->getItem())->getName() << " to your bag." <<std::endl;
                userBag->add(currentLocation->getItem());
                currentLocation->deleteItem();
            }
            std::cout << std::endl;
            
        }
    }
    //Continue as long as the player is alive, the tornado hasn't hit, or they haven't won
    while (p1->getTornado() > 0 && !win && p1->getHealth() > 0);
    
    //Display game result based on user stats. If the player makes it to the basement at the same time as the tornado hits they still win.
    if (win) {
        std::cout << p1->getName() << " you made it to the basement with the key and unlocked the door. You survived the storm!" << std::endl;
    }
    else if (p1->getTornado() <= 0) {
        std::cout << p1->getName() << " you didn't make it to the basement before the tornado hit... better luck next time!" << std::endl;
    }
    
    else if (p1->getHealth() <= 0) {
        std::cout << p1->getName() << " you took to much damage while moving around the house and you didn't survive the storm... better luck next time!" << std::endl;
    }
    

    
    
    return 0;
}
