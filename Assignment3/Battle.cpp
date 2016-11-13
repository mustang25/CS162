/*********************************************************************
 ** Author: Rob Navarro
 ** Date: November 8, 2015
 ** Description: This implements the Battle class.
 *********************************************************************/

#include "Battle.hpp"

Battle::Battle (Creature* c1, Creature* c2) {
    p1 = c1;
    p2 = c2;
}

void Battle::fight(){
    round = 1;
    //This loop will have player 1 and player 2 face off until one player looses
    do {
        damage = 0;
        std::cout << "Press ENTER to play round " << round << std::endl;
        std::cin.ignore();
        //If the round is even then player 1 attacks
        if (round % 2 != 0) {
            std::cout << "Player 1 is attacking" << std::endl;
            //Store the value from the player 1 attack rolls
            p1Attack = p1->attack();
            std::cout << "For attacking, player 1 rolled a total of: " << p1Attack << std::endl;
            //Check and see if the player is a Goblin and rolled a 12
            if (p1Attack == 12 && p1->getType() == "Goblin") {
                //If the previous check passes, confirm that the achilles hasn't already been cut and that the other player isn't a Goblin
                if (p2->getType() != "Goblin" && p2->getAchilles() == false) {
                    std::cout << "The goblin rolled a 12 and sliced the Achilles of player 2." << std::endl;
                    std::cout << "All future player 2 attacks will only produced half the damage." << std::endl;
                    //If all previous checks pass set cutAchilles to true, this will cut attack damage in half.
                    p2->setAchilles(true);
                }
            }
            
            p2Defense = p2->defense();
            //Check if the player 2 defense roll was the sentinal for the Shadow class
            if (p2Defense == -1 && p2->getType() == "Shadow") {
                std::cout << "The elusive shadow could not be found and the attack missed" << std::endl;
                //If so Player 2 health will not change
                p2Health = p2->getStrength();
            }
            else {
                //Calculate total damage done for this turn
                std::cout << "For defending, player 2 rolled a total of: " << p2Defense << std::endl;
                damage = p1Attack - p2Defense - p2->getArmor();
                p2Health = p2->getStrength();
            }
            
            if (damage > 0) {
                //If the total damage done was greater than 0 display the total amount of damage done and save the new health value for player 2
                std::cout << "Including the effects of armor, the total damage done was: " << damage << std::endl;
                p2Health = p2->getStrength() - damage;
            }
            
            else {
                std::cout << "No damage was done this round" << std::endl;
            }
            
            //If player 2 health is less than 0 set the player alive to false and set strength to 0.
            //If player 2 health is greater than 0 update the player health value
            if (p2Health <= 0) {
                p2->setAlive(false);
                p2->setStrength(0);
            }
            else {
                p2->setStrength(p2Health);
                
            }
        }
        else {
            std::cout << "Player 2 is attacking" << std::endl;
            
            p2Attack = p2->attack();
            std::cout << "For attacking, player 2 rolled a total of: " << p2Attack << std::endl;
            
            //Check and see if the player is a Goblin and rolled a 12
            if (p2Attack == 12 && p2->getType() == "Goblin") {
                //If the previous check passes, confirm that the achilles hasn't already been cut and that the other player isn't a Goblin
                if (p1->getType() != "Goblin" && p1->getAchilles() == false) {
                    std::cout << "The goblin rolled a 12 and sliced the Achilles of player 2." << std::endl;
                    std::cout << "All future player 2 attacks will only produced half the damage." << std::endl;
                    //If all previous checks pass set cutAchilles to true, this will cut attack damage in half.
                    p1->setAchilles(true);
                }
            }
            
            //Store the defense roll value for player 1
            p1Defense = p1->defense();
            
            //Check for the Shadow class sentinal value
            if (p1Defense == -1 && p1->getType() == "Shadow") {
                std::cout << "The elusive shadow could not be found and the attack missed!" << std::endl;
                p1Health = p1->getStrength();
            }
            
            //If the player is not of Shadow class calculate total damage and get player 1 health
            else {
                std::cout << "For defending, player 1 rolled a total of: " << p1Defense << std::endl;
                damage = p2Attack - p1Defense - p1->getArmor();
                p1Health = p1->getStrength();
            }
            
            //If the damage caused is greater than 0, calculate new player 1 health and display total damage
            if (damage > 0) {
                std::cout << "Including the effects of armor, the total damage done was: " << damage << std::endl;
                p1Health = p1->getStrength() - damage;
            }
            
            else {
                std::cout << "No damage was done this round" << std::endl;
            }
            
            //If player 1 health is less than 0 setAlive = false and set strength to 0 or update player 1 health
            if (p1Health <= 0) {
                p1->setAlive(false);
                p1->setStrength(0);
            }
            else {
                p1->setStrength(p1Health);
            }
        }
        //Display current health stats for both players following round
        std::cout << "After round " << round << std::endl;
        std::cout << "The player 1 " << p1->getType() << " has " << p1->getStrength() << " strength." <<std::endl;
        std::cout << "The player 2 " << p2->getType() << " has " << p2->getStrength() << " strength." <<std::endl;
        round++;

    }
    //Continue through this loop until player 1 or player 2 is no longer alive. 
    while (p1->getAlive() && p2->getAlive());
    
    if (p1->getAlive()) {
        std::cout << "Player 1 wins!!!!" << std::endl;
    }
    else if (p2->getAlive()) {
        std::cout << "Player 2 wins!!!!" << std::endl;
 
    }


}