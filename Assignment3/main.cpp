//
//  main.cpp
//  Assignment3
//
//  Created by Rob Navarro on 11/8/15.
//  Copyright © 2015 Rob Navarro. All rights reserved.
//

#include <iostream>
#include <time.h>
#include <stdlib.h>
#include "Creature.hpp"
#include "Battle.hpp"

int main() {
    int selection;
    srand(time(NULL));
    Creature* userCreatures[2];
    
    //For loop that fills the userCreatures array with user selected values.
    //If an invalid value is entered, the user is asked try again.
    for (int i = 0; i < 2; i++) {
        std::cout << "What type of creature would you like to user for player " << i + 1 << "?" << std::endl;
        std::cout << "1. Goblin" << std::endl;
        std::cout << "2. Barbarian" << std::endl;
        std::cout << "3. Reptile People" << std::endl;
        std::cout << "4. Blue Men" << std::endl;
        std::cout << "5. The Shadow" << std::endl;
        std::cout << "Please enter corresponding number to selection: ";
        std::cin >> selection;
        
        if (selection == 1) {
            userCreatures[i] = new Goblin;
        }

        else if (selection == 2) {
            userCreatures[i] = new Barbarian;
        }
        
        else if (selection == 3) {
            userCreatures[i] = new Reptile;
        }
        
        else if (selection == 4) {
            userCreatures[i] = new BlueMen;
        }
        
        else if (selection == 5) {
            userCreatures[i] = new Shadow;
        }
        
        else {
            std::cout << "Invalid selection, please try again" << std::endl;
            i--;
        }

    }
    
    std::cin.ignore();
    //Create a battle object with the values enetered by the user above
    Battle bat(userCreatures[0], userCreatures[1]);
    //Start fight between two creatures
    bat.fight();
    return 0;
}
