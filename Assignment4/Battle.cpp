/*********************************************************************
 ** Author: Rob Navarro
 ** Date: November 22, 2015
 ** Description: This implements the Battle class.
 *********************************************************************/

#include "Battle.hpp"

Battle::Battle () {
    p1 = NULL;
    p2 = NULL;
}

Battle::Battle (Creature* c1, Creature* c2) {
    p1 = c1;
    p2 = c2;
}

void Battle::setP1(Creature* newP1) {
    p1 = newP1;
}

void Battle::setP2(Creature* newP2) {
    p2 = newP2;
}

void Battle::fight(){
    round = 1;
    //This loop will have player 1 and player 2 face off until one player looses
    do {
        //If the round is odd then player 1 attacks
        if (round % 2 != 0) {
            //Store the value from the player 1 attack rolls
            p1Attack = p1->attack();
            //Check and see if the player is a Goblin and rolled a 12
            if (p1Attack == 12 && p1->getType() == "Goblin") {
                //If the previous check passes, confirm that the achilles hasn't already been cut and that the other player isn't a Goblin
                if (p2->getType() != "Goblin" && p2->getAchilles() == false) {
                    //If all previous checks pass set cutAchilles to true, this will cut attack damage in half.
                    p2->setAchilles(true);
                }
            }
            
            p2Defense = p2->defense();
            //Check if the player 2 defense roll was the sentinal for the Shadow class
            if (p2Defense == -1 && p2->getType() == "Shadow") {
                //If so Player 2 health will not change
                p2Health = p2->getStrength();
            }
            else {
                //Calculate total damage done for this turn
                damage = p1Attack - p2Defense - p2->getArmor();
                p2Health = p2->getStrength();
            }
            
            if (damage > 0) {
                //If the total damage done was greater than 0 display the total amount of damage done and save the new health value for player 2
                p2Health = p2->getStrength() - damage;
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
        //If the round is even player 2 will attack
        else {
            p2Attack = p2->attack();
            
            //Check and see if the player is a Goblin and rolled a 12
            if (p2Attack == 12 && p2->getType() == "Goblin") {
                //If the previous check passes, confirm that the achilles hasn't already been cut and that the other player isn't a Goblin
                if (p1->getType() != "Goblin" && p1->getAchilles() == false) {
                    p1->setAchilles(true);
                }
            }
            
            //Store the defense roll value for player 1
            p1Defense = p1->defense();
            
            //Check for the Shadow class sentinal value
            if (p1Defense == -1 && p1->getType() == "Shadow") {
                p1Health = p1->getStrength();
            }
            
            //If the player is not of Shadow class calculate total damage and get player 1 health
            else {
                damage = p2Attack - p1Defense - p1->getArmor();
                p1Health = p1->getStrength();
            }
            
            //If the damage caused is greater than 0, calculate new player 1 health and display total damage
            if (damage > 0) {
                p1Health = p1->getStrength() - damage;
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
        round++;

    }
    //Continue through this loop until player 1 or player 2 is no longer alive. 
    while (p1->getAlive() && p2->getAlive());

}