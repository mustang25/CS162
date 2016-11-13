/*********************************************************************
 ** Author: Rob Navarro
 ** Date: November 22, 2015
 ** Description: This program implements a tournament game between 
 ** different teams of creatures. The players are asked to set their
 ** lineups with a certain amount of creatures that they choose. Once
 ** the lineups are set the tournament takes place and the first 3 places
 ** are displayed. The user has an option to display the losers as well
 ** as the reuslts between each round of the tournament.
 *********************************************************************/


#include <iostream>
#include <string>
#include <time.h>
#include <stdlib.h>
#include "Creature.hpp"
#include "Queue.hpp"
#include "Stack.hpp"
#include "Battle.hpp"

//This function will be used to set player lineups
Creature* addCreature(std::string);


int main(int argc, const char * argv[]) {
    Queue player1;
    Queue player2;
    Stack losers;
    Creature* c1;
    Creature* c2;
    Creature* firstPlace;
    Creature* secondPlace;
    Creature* thirdPlace;
    Battle b1;
    int numCharacters;
    int round = 1;
    int team1Score = 0;
    int team2Score = 0;
    int place = 4;
    std::string team1Name;
    std::string team2Name;
    std::string displayScores;
    std::string displayLosers;
    srand(time(NULL));
    
    //Prompt player for number of creatures
    std::cout << "How many creatures will each player have? ";
    std::cin >> numCharacters;
    
    //Prompt if score and winner should be displayed after each round
    std::cout << "Enter 1 if you would like the winner and current score to be displayed between rounds (0 for no display): ";
    std::cin >> displayScores;
    
    //Set player 1 lineup
    std::cout << "Player 1 please enter a team name: ";
    std::cin.ignore();
    std::getline (std::cin, team1Name);
    for (unsigned long i = 0; i < numCharacters; i++) {
        std::cout << "Player 1 what would you like Creature " << i + 1 << " to be?" << std::endl;
        player1.add(addCreature(team1Name));
    }
    
    //Set player 2 lineup
    std::cout << "Player 2 please enter a team name: ";
    std::getline (std::cin, team2Name);
    for (unsigned long i = 0; i < numCharacters; i++) {
        std::cout << "Player 2 what would you like Creature " << i + 1 << " to be?" << std::endl;
        player2.add(addCreature(team2Name));
    }
    
    //This loop will start the tournament
    do {
        if (displayScores == "1") {
            std::cout << "Press enter to play round " << round << " of the tournament" << std::endl;
            std::cin.ignore();
        }
        //Set creatures 1 and 2 from the player 1 and player 2 queue
        c1 = player1.remove();
        c2 = player2.remove();
        
        //Set the creatures that will be fighting inside the battle class
        b1.setP1(c1);
        b1.setP2(c2);
        
        //Call for the creatures to fight
        b1.fight();
        
        //Check if player 1 is alive
        //If so have player 1 call the healing function and add the creature back to the player 1 queue.
        //Also, add player 2 to the losers stack and give team 1 a point for the win.
        if (c1->getAlive()) {
            c1->heal();
            if (displayScores == "1") {
                std::cout << c1->getName() << " the " << c1->getType() << " wins round " << round << std::endl;
            }
            player1.add(c1);
            losers.add(c2);
            team1Score += 1;
        }
        
        //If player1 isn't alive then player 2 is alive. We will call the creature 2 healing fucntion and add creature 2 back to the player 2 queue. Creature 1 will be added to the losers stack and team 2 will be awarded a point for the win.
        else {
            c2->heal();
            if (displayScores == "1") {
                std::cout << c2->getName() << " the " << c2->getType() << " wins round " << round << std::endl;
            }
            player2.add(c2);
            losers.add(c1);
            team2Score += 1;
        }
        round++;
        if (displayScores == "1") {
            std::cout << "The current score is:" << std::endl;
            std::cout << "Team " << team1Name << ": " << team1Score << std::endl;
            std::cout << "Team " << team2Name << ": " << team2Score << std::endl;
            std::cout << std::endl;
        }
    }
    //Continue tournament until one queue is empty
    while (!player1.isEmpty() && ! player2.isEmpty());
    
    //After the tournament ends we will move any remaining creatures to the loser pile. These if statements check if each queue is empty
    if (!player1.isEmpty()) {
        do {
            losers.add(player1.remove());
        } while (!player1.isEmpty());
    }
    
    if (!player2.isEmpty()) {
        do {
            losers.add(player2.remove());
        } while (!player2.isEmpty());
    }
    
    //The last creature placed into the stack will be the winner. This is the creature that won the last battle in the tournament. We also place the 2nd and 3rd place creatures into a new variable as well.
    //Points will be rewarded to each team depending on what place the creature was.
    firstPlace = losers.remove();
    if (firstPlace->getTeam() == team1Name) {
        team1Score += 10;
    }
    else
        team2Score += 10;
    
    secondPlace = losers.remove();
    if (secondPlace->getTeam() == team1Name) {
        team1Score += 7;
    }
    else
        team2Score += 7;
    
    if (!losers.isEmpty()) {
        thirdPlace = losers.remove();
        if (thirdPlace->getTeam() == team1Name) {
            team1Score += 6;
        }
        else
            team2Score += 6;
    }
    
    //Display the 1st, 2nd and 3rd place finshers and the overall team winner.
    std::cout << "The 1st place finisher in the tournament is " << firstPlace->getName() << " the " << firstPlace->getType() << " playing for team " << firstPlace->getTeam() << std::endl;
    std::cout << std::endl;
    std::cout << "The 2nd place finisher in the tournament is " << secondPlace->getName() << " the " << secondPlace->getType() << " playing for team " << secondPlace->getTeam() << std::endl;
    std::cout << std::endl;
    std::cout << "The 3rd place finisher in the tournament is " << thirdPlace->getName() << " the " << thirdPlace->getType() << " playing for team " << thirdPlace->getTeam() << std::endl;
    std::cout << std::endl;
    
    if (team1Score > team2Score) {
        std::cout << "Team " << team1Name << " won with a score of " << team1Score << std::endl;
    }
    else if (team2Score > team1Score) {
        std::cout << "Team " << team2Name << " won with a score of " << team2Score << std::endl;;
    }
    else {
        std::cout << "The match ended in a draw for the team score" << std::endl;
    }
    std::cout << std::endl;
    
    //Ask user if they would like the loser stack dispalyed.
    std::cout << "Would you like to display the losers of the tourney? (0 for no, 1 for yes) ";
    std::cin >> displayLosers;
    if (displayLosers == "1") {
        while (!losers.isEmpty()) {
            c1 = losers.remove();
            std::cout << place << ". " << c1->getName() << " the " << c1->getType() << " playing for " << c1->getTeam() << std::endl;
            place++;
        }
    }

    return 0;
}

Creature* addCreature(std::string newTeam) {
    Creature* returnCreature;
    std::string userSelection;
    std::string creatureName;
    bool validSelection = false;
    
    //Simple menu function used for creature selection
    do {
        std::cout << "1. Barbarian" << std::endl;
        std::cout << "2. Goblin" << std::endl;
        std::cout << "3. Reptile People" << std::endl;
        std::cout << "4. Blue Men" << std::endl;
        std::cout << "5. The Shadow" << std::endl;
        std::cout << "Please enter corresponding number to selection: ";
        std::cin >> userSelection;
        
        if (userSelection == "1") {
            returnCreature = new Barbarian;
            validSelection  = true;
            std::cout << "Please enter a name for the Barbarian: ";
            std::cin.ignore();
            std::getline (std::cin, creatureName);
            returnCreature->setName(creatureName);
            returnCreature->setTeam(newTeam);
        }
        else if (userSelection == "2") {
            returnCreature = new Goblin;
            validSelection  = true;
            std::cout << "Please enter a name for the Goblin: ";
            std::cin.ignore();
            std::getline (std::cin, creatureName);
            returnCreature->setName(creatureName);
            returnCreature->setTeam(newTeam);
        }
        else if (userSelection == "3") {
            returnCreature = new Reptile;
            validSelection  = true;
            std::cout << "Please enter a name for the Reptile: ";
            std::cin.ignore();
            std::getline (std::cin, creatureName);
            returnCreature->setName(creatureName);
            returnCreature->setTeam(newTeam);
        }
        
        else if (userSelection == "4") {
            returnCreature = new BlueMen;
            validSelection  = true;
            std::cout << "Please enter a name for the Blue Men: ";
            std::cin.ignore();
            std::getline (std::cin, creatureName);
            returnCreature->setName(creatureName);
            returnCreature->setTeam(newTeam);
        }
        
        else if (userSelection == "5") {
            returnCreature = new Shadow;
            validSelection  = true;
            std::cout << "Please enter a name for the Shadow: ";
            std::cin.ignore();
            std::getline (std::cin, creatureName);
            returnCreature->setName(creatureName);
            returnCreature->setTeam(newTeam);
        }
        
        else {
            std::cout << "Invalid Selection... please enter a valid number" << std::endl;
        }
    } while (!validSelection);
    
    std::cout << std::endl;
    return returnCreature;
}
