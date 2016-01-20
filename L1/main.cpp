/*********************************************************************
 ** Author: Rob Navarro
 ** Date: September 30, 2015
 ** Description: A program that asks the user to choose how many sides a die
 has and how many times it will be rolled.
 *********************************************************************/

#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include "Die.hpp"
#include "LoadedDie.hpp"

int main() {
    
    int userInput;
    int rolls;
    int die = 0;
    int ldie = 0;
    srand(time (0));
    bool tf = true;
    
    //Prompt user for number of sides that the dice will have
    std::cout << "How many sides do the dice have?" << std::endl;
    std::cin >> userInput;
    
    if (tf == true) {
        Die p1(userInput);
    }
    else
        LoadedDie p1(userInput);
    
    //Create a Die and LoadedDie
    Die d1(userInput);
    LoadedDie d2(userInput);
    
    //Ask the user how many times the die will be rolled
    std::cout << "How many times will you roll the dice?" << std::endl;
    std::cin >> rolls;
    
    //A for loop that rolls the dice with the value the user entered above
    for (int i = 1; i <= rolls; i++) {
        die = die + d1.roll();
        ldie = ldie + d2.roll(i, userInput);
    };
    
    //Provide totals for all of the rolls
    std::cout << "The die had a total of: " << die << std::endl;
    std::cout << "The loaded die had a total of: " << ldie << std::endl;
    
    return 0;
}

