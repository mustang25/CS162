//********************************************************************************
//Date: 10/15/2015
//Description: This is the Game program that uses the Die and LoadedDie classes
//             to play the Game of War.
//********************************************************************************
#include <iostream>
#include <ctime>
#include <cstdlib>
#include "LoadedDie.hpp"
using std::cout;
using std::cin;
using std::endl;

int main()
{
    
    int sides;//# of sides
    int *dSides;//Pointer to dieSides
    int p1Wins = 0;
    int p2Wins = 0;
    int p1Roll = 0;
    int p2Roll = 0;
    int currentRound = 0;
    int roundsToPlay;
    int p1Loaded = 0;
    int p2Loaded = 0;
    bool dieSelected = false;
    srand(time(NULL));//Seeds rand with current time
    
    
    //Welcome for game of war, also set the number of sides for the dice.
    cout << "Welcome to the Game of WAR!" << endl;
    cout << "Please enter how many sides each die will have: " << endl;
    cin >> sides;
    dSides = &sides;//Assign the pointer to dieSides' address
    
    //Implement 4 die classes. The die used will depend on user input below.
    Die die1(dSides);           //player 1 normal die
    Die die2(dSides);           //player 2 normal die
    LoadedDie die3(dSides);     //player 1 loaded die
    LoadedDie die4(dSides);     //player 2 loaded die
    
    //Continue through while loop until user chooses valid die options
    while (!dieSelected) {
        
        //Player selects die types
        cout << "Please enter what type of die player one will have (0 = normal, 1 = loaded): ";
        cin >> p1Loaded;
        cout << "Please enter what type of die player two will have (0 = normal, 1 = loaded): ";
        cin >> p2Loaded;
        
        //Check if user inputs are valid
        if ((p1Loaded == 0 || p1Loaded == 1) && (p2Loaded == 0 || p2Loaded == 1)) {
            dieSelected = true;
        }
        
        //If inputs are invalid start loop over
        if ((p1Loaded != 0 && p1Loaded != 1) || (p2Loaded != 0 && p2Loaded != 1)) {
            cout << "You did not enter valid die selections, please try again!" << endl;
        }
        
    }
    
    //Determine rounds to be played
    cout << "How many rounds of War do you wish to play? " << endl;
    cin >> roundsToPlay;
    cin.get();
    
    //Loop through this loop for the number of rounds that the player wants to play
    //The player must press enter to start each round
    //The console displays what each player rolls and who wins the round
    for (int i = 0; i < roundsToPlay; i++) {
        
        cout << "Press enter to play round " << currentRound + 1 << endl;
        cin.get();
        
        if (p1Loaded == 0) {
            
            p1Roll = die1.roll();
            cout << "Player 1 rolled a: " << p1Roll << endl;
            
        }
        
        if (p1Loaded == 1) {
            p1Roll = die3.roll();
            cout << "Player 1 rolled a: " << p1Roll << endl;
        }
        
        if (p2Loaded == 0) {
            p2Roll = die2.roll();
            cout << "Player 2 rolled a: " << p2Roll << endl;
        }
        
        if (p2Loaded == 1) {
            p2Roll = die4.roll();
            cout << "Player 2 rolled a: " << p2Roll << endl;
        }
        
        if (p1Roll > p2Roll) {
            cout << "Player 1 wins round " << currentRound + 1 << endl;
            p1Wins++;
        }
        
        if (p2Roll > p1Roll) {
            cout << "Player 2 wins round " << currentRound + 1 << endl;
            p2Wins++;
        }
        
        if (p1Roll == p2Roll) {
            cout << "This round is a draw!" << endl;;
        }
        
        currentRound++;
        cout << endl;
        
    }
    
    cout << endl;
    
    //Display who wins the game
    if (p1Wins > p2Wins)
        cout << "Player 1 wins the Game of War!" << endl;
    
    if (p2Wins > p1Wins)
        cout << "Player 2 wins the Game of War!" << endl;
    
    if (p1Wins == p2Wins)
        cout << "The Game of War has ended in a draw!" << endl;
 
   return 0;
}

      
           
 
