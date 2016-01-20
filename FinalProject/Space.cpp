/*********************************************************************
 ** Author: Rob Navarro
 ** Date: December 8, 2015
 ** Description: This implements the interface for the Space class.
 *********************************************************************/


#include "Space.hpp"

//This function will allow the pointers to be set for each object
void Space::setPointers(Space* newLeft, Space* newUp, Space* newRight, Space* newDown) {
    left = newLeft;
    up = newUp;
    right = newRight;
    down = newDown;
}

//Declare getter/setter functions for the space class
void Space::setName(std::string newName) {
    name = newName;
}

std::string Space::getName() {
    return name;
}

Space* Space::getUp() {
    return up;
}

Space* Space::getDown() {
    return down;
}

Space* Space::getLeft() {
    return left;
}

Space* Space::getRight() {
    return right;
}

void Space::addItem(Item* newItem) {
    roomItem = newItem;
}

Item* Space::getItem() {
    return roomItem;
}

//This function will be used to delete an item from a room if it is found
void Space::deleteItem() {
    roomItem = NULL;
}

//Constructor for the MasterBedrrom class... the name will be used to identify it.
MasterBedroom::MasterBedroom(std::string newName) {
    setName(newName);
    setPointers(NULL, NULL, NULL, NULL);
    addItem(NULL);
}

//Special function for the master bedroom. This function presents a simple addition challenge to the user
void MasterBedroom::special(Player* player1) {
    int x = rand() % 10 + 1;
    int y = rand() % 10 + 1;
    int random = rand() % 3 + 1;
    int sum = x + y;
    int userInput;
    
    std::cout << "Solve the following problem: " << x << " + " << y << " = ";
    std::cin >> userInput;
    
    //If the user answers the problem check if they have already been in the room, else allow for room special
    if (userInput == sum) {
        if (player1->getMaster()) {
            std::cout << "You've already been in here... it doesn't seem like there is anything else to do... keep moving!" << std::endl;
        }
        else {
            std::cout << "You were able to shut the shutters to half the house... increase the amount of turns until the tornado arrives by 2!" << std::endl;
            player1->addTornado(2);
            player1->setMaster();
        }
        
    }
    else {
        std::cout << "Incorrect! You tripped over the carpet, you lost " << random << " turns until the tornado arrives" << std::endl;
        player1->subTornado(random);
    }
    
}

//Constructor for the Bedroom class... the name will be used to identify it.
Bedroom::Bedroom(std::string newName) {
    setName(newName);
    setPointers(NULL, NULL, NULL, NULL);
    addItem(NULL);
}

//Bedroom special function that presents a easy subtraction problem
void Bedroom::special(Player* player1) {
    int x = rand() % 11 + 10;
    int y = rand() % 10 + 1;
    int random = rand() % 3 + 1;
    int sum = x - y;
    int userInput;
    
    std::cout << "Solve the following problem: " << x << " - " << y << " = ";
    std::cin >> userInput;
    
    //If the user answers the problem check if they have already been in the room, else allow for room special
    if (userInput == sum) {
        if (player1->getBedroom()) {
            std::cout << "You've already been in here... it doesn't seem like there is anything else to do... keep moving!" << std::endl;
        }
        else {
            std::cout << "You were able to shut the shutters to half the house... increase the amount of turns until the tornado arrives by 2!" << std::endl;
            player1->addTornado(2);
            player1->setBedroom();
        }

    }
    else {
        std::cout << "Incorrect! You tripped over the carpet, you lost " << random << " turns until the tornado arrives" << std::endl;
        player1->subTornado(random);
    }
    
}

//Constructor for the Living class... the name will be used to identify it.
Living::Living(std::string newName) {
    setName(newName);
    setPointers(NULL, NULL, NULL, NULL);
    addItem(NULL);
}

//Living special function that presents a difficult addition problem
void Living::special(Player* player1) {
    int x = rand() % 1000 + 1;
    int y = rand() % 500 + 1;
    int random = rand() % 30 + 1;
    int sum = x + y;
    int userInput;
    
    std::cout << "Solve the following problem: " << x << " + " << y << " = ";
    std::cin >> userInput;
    
    //If the user answers the problem check if they have already been in the room, else allow for room special
    if (userInput == sum) {
        if (player1->getLiving()) {
            std::cout << "You've already been in here... it doesn't seem like there is anything else to do... keep moving!" << std::endl;
        }
        else {
            std::cout << "You found some leftover pizza and ate it... gain 5 health!" << std::endl;
            player1->addHealth(5);
            player1->setLiving();
        }
    }
    else {
        std::cout << "Incorrect! While thinking the TV became unmounted and hit you... lose " << random << " health." << std::endl;
        player1->subHealth(random);
    }
    
}

//Constructor for the Office class... the name will be used to identify it.
Office::Office(std::string newName) {
    setName(newName);
    setPointers(NULL, NULL, NULL, NULL);
    addItem(NULL);
}

//Office special function that present a moderate subtraction problem
void Office::special(Player* player1) {
    int x = rand() % 50 + 100;
    int y = rand() % 49 + 1;
    int diff = x - y;
    int random = rand() % 10 + 10;
    int userInput;
    
    std::cout << "Solve the following problem: " << x << " - " << y << " = ";
    std::cin >> userInput;
    
    //If the user answers the problem check if they have already been in the room, else allow for room special
    if (userInput == diff) {
        if (player1->getOffice()) {
            std::cout << "You've already been in here... it doesn't seem like there is anything else to do... keep moving!" << std::endl;
        }
        else {
            std::cout << "You found your shoes and you can move a bit quicker. Add 1 turn until the tornado hits" << std::endl;
            player1->addTornado(1);
            player1->setOffice();
        }
    }
    else {
        std::cout << "Incorrect! A laptop flew through the room and hit you, lose " << random << " health." << std::endl;
        player1->subHealth(random);
    }
    
}

//Constructor for the Entry class... the name will be used to identify it.
Entry::Entry(std::string newName) {
    setName(newName);
    setPointers(NULL, NULL, NULL, NULL);
    addItem(NULL);
}

//Entry special function that presents a medium-hard addition problem
void Entry::special(Player* player1) {
    int x = rand() % 300 + 200;
    int y = rand() % 199 + 1;
    int random = rand() % 5 + 1;
    int diff = x - y;
    int userInput;
    
    std::cout << "Solve the following problem: " << x << " - " << y << " = ";
    std::cin >> userInput;
    
    //If the user answers the problem check if they have already been in the room, else allow for room special
    if (userInput == diff) {
        if (player1->getEntry()) {
            std::cout << "You've already been in here... it doesn't seem like there is anything else to do... keep moving!" << std::endl;
        }
        else {
            std::cout << "You shut the front door making it a bit easier to walk in the house. Add 1 turn until the tornado hits" << std::endl;
            player1->addTornado(1);
            player1->setEntry();
        }
    }
    else {
        std::cout << "Incorrect! The door hit you as you were passing through the room. Lose " << random  << " until the tornado hits." << std::endl;
        player1->subTornado(random);
    }
}

//Constructor for the Basement class... the name will be used to identify it.
Basement::Basement(std::string newName) {
    setName(newName);
    setPointers(NULL, NULL, NULL, NULL);
    addItem(NULL);
}

//Basement special function that present a moderate subtraction problem
void Basement::special(Player* player1) {
    int x = rand() % 100 + 50;
    int y = rand() % 49 + 1;
    int random = rand() % 5 + 1;
    int diff = x - y;
    int userInput;
    
    std::cout << "Solve the following problem: " << x << " - " << y << " = ";
    std::cin >> userInput;
    
    //If the user answers the problem check if they have already been in the room, else allow for room special
    if (userInput == diff) {
        if (player1->getBasement()) {
            std::cout << "You've already been in here... it doesn't seem like there is anything else to do... keep moving!" << std::endl;
        }
        else {
            std::cout << "You couldn't open the basement door but you found a helmet, gain 5 health." << std::endl;
            player1->addHealth(5);
            player1->setBasement();
        }
    }
    else {
        std::cout << "Incorrect! You slipped on the wet floor, lose " << random << " until the tornado arrives."<< std::endl;
        player1->subTornado(random);
        
    }
    
}

//Constructor for the Garage class... the name will be used to identify it.
Garage::Garage(std::string newName) {
    setName(newName);
    setPointers(NULL, NULL, NULL, NULL);
    addItem(NULL);
}

//Garage special function that has a med-hard additon prob
void Garage::special(Player* player1) {
    int x = rand() % 300 + 500;
    int y = rand() % 100 + 1;
    int random = rand() % 5 + 1;
    int sum = x + y;
    int userInput;
    
    std::cout << "Solve the following problem: " << x << " + " << y << " = ";
    std::cin >> userInput;
    
    //If the user answers the problem check if they have already been in the room, else allow for room special
    if (userInput == sum) {
        if (player1->getGarage()) {
            std::cout << "You've already been in here... it doesn't seem like there is anything else to do... keep moving!" << std::endl;
        }
        else {
            std::cout << "You found some body armor... gain 10 health" << std::endl;
            player1->addHealth(10);
            player1->setGarage();
        }
    }
    else {
        std::cout << "Incorrect! The garage door blew open and you lost your balance... you lost " << random << " turns." << std::endl;
        player1->subTornado(random);
    }
    
}

//Constructor for the Dining class... the name will be used to identify it.
Dining::Dining(std::string newName) {
    setName(newName);
    setPointers(NULL, NULL, NULL, NULL);
    addItem(NULL);
}

//Dining special function that presents a hard addition problem
void Dining::special(Player* player1) {
    int x = rand() % 100 + 500;
    int y = rand() % 20 + 1;
    int random = rand() % 15 + 5;
    int diff = x - y;
    int userInput;
    
    std::cout << "Solve the following problem: " << x << " - " << y << " = ";
    std::cin >> userInput;
    
    //If the user answers the problem check if they have already been in the room, else allow for room special
    if (userInput == diff) {
        if (player1->getDining()) {
            std::cout << "You've already been in here... it doesn't seem like there is anything else to do... keep moving!" << std::endl;
        }
        else {
            std::cout << "You drank some water and gained 5 health!" << std::endl;
            player1->addHealth(5);
            player1->setDining();
        }
 
    }
    else {
        std::cout << "Incorrect! Plates from the china cabinet flew and hit you in the head... lose " << random << " health." << std::endl;
        player1->subHealth(random);
    }
    
}

//Constructor for the Kitchen class... the name will be used to identify it.
Kitchen::Kitchen(std::string newName) {
    setName(newName);
    setPointers(NULL, NULL, NULL, NULL);
    addItem(NULL);
}

//Kitchen special function that presents a hard sub problem
void Kitchen::special(Player* player1) {
    int x = rand() % 50 + 100;
    int y = rand() % 15 + 1;
    int random = rand() % 30 + 10;
    int diff = x - y;
    int userInput;
    
    std::cout << "Solve the following problem: " << x << " - " << y << " = ";
    std::cin >> userInput;
    
    //If the user answers the problem check if they have already been in the room, else allow for room special
    if (userInput == diff) {
        if (player1->getKitchen()) {
            std::cout << "You've already been in here... it doesn't seem like there is anything else to do... keep moving!" << std::endl;
        }
        else {
            std::cout << "You ate some left overs and gained 5 health." << std::endl;
            player1->addHealth(5);
            player1->setKitchen();
        }

    }
    else {
        std::cout << "Incorrect! While thinking you were stabbed by several knives, you lost " << random << " health." << std::endl;
        player1->subHealth(random);
    }
    
}

//Constructor for the Outside class... the name will be used to identify it.
Outside::Outside(std::string newName) {
    setName(newName);
    setPointers(NULL, NULL, NULL, NULL);
    addItem(NULL);
}

//This function will only cause the player to lose health and turns
void Outside::special(Player* player1) {
    int random = rand() % 7 + 1;
    int random1 = rand() % 25 + 25;
    std::cout << std::endl;
    std::cout << "You wander outside but you are just blown back into the room you tried to leave. " << std::endl;
    
    std::cout << "You lose " << random << " turns until the tornado hits!" << std::endl;
    std::cout << "You also lost " << random1 << " health!" <<std::endl;
    player1->subTornado(random);
    player1->subHealth(random1);

}