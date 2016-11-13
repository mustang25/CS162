//
//  main.cpp
//  A1
//
//  Created by Rob Navarro on 10/3/15.
//  workright © 2015 Rob Navarro. All rights reserved.
//

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string>

const char ROWS = 24;
const char COLS = 44;

//This function allows for arrays to easily be copied from one to another
void copy(char array1[ROWS][COLS], char array2[ROWS][COLS]) {
    for (int i = 0; i < ROWS; i++)
        for (int j = 0; j < COLS; j++) {
            array2[i][j] = array1[i][j];
        }
}


void blinker(char array1[ROWS][COLS], int r, int c) {
    
    //Set the first generation for the blinker
    
    array1[r][c] = 'x';
    array1[r - 1][c] = 'x';
    array1[r + 1][c] = 'x';
    
}

void glider(char array1[ROWS][COLS], int r, int c) {
    
    //Create the first generation of the glider
    
    array1[r][c] = 'x';
    array1[r][c - 1] = 'x';
    array1[r][c - 2] = 'x';
    array1[r - 1][c] = 'x';
    array1[r - 2][c - 1] = 'x';
    
}

void glidergun(char array1[ROWS][COLS], int radj, int cadj) {
    
    //Set the first genration for the glider gun
    
    //set left box
    array1[5 + radj][1 + cadj] = 'x'; array1[5 + radj][2 + cadj] = 'x';
    array1[6 + radj][1 + cadj] = 'x'; array1[6 + radj][2 + cadj] = 'x';
    //set right box
    array1[3 + radj][35 + cadj] = 'x'; array1[4 + radj][35 + cadj] = 'x';
    array1[3 + radj][36 + cadj] = 'x'; array1[4 + radj][36 + cadj] = 'x';
    //set left middle shape
    array1[5 + radj][11 + cadj] = 'x'; array1[6 + radj][11 + cadj] = 'x'; array1[7 + radj][11 + cadj] = 'x';
    array1[4 + radj][12 + cadj] = 'x'; array1[8 + radj][12 + cadj] = 'x';
    array1[3 + radj][13 + cadj] = 'x'; array1[9 + radj][13 + cadj] = 'x';
    array1[3 + radj][14 + cadj] = 'x'; array1[9 + radj][14 + cadj] = 'x'; array1[6 + radj][15 + cadj] = 'x';
    array1[4 + radj][16 + cadj] = 'x'; array1[8 + radj][16 + cadj] = 'x';
    array1[5 + radj][17 + cadj] = 'x'; array1[6 + radj][17 + cadj] = 'x'; array1[7 + radj][17 + cadj] = 'x';
    array1[6 + radj][18 + cadj] = 'x';
    //set right middle shape
    array1[3 + radj][21 + cadj] = 'x'; array1[4 + radj][21 + cadj] = 'x'; array1[5 + radj][21 + cadj] = 'x';
    array1[3 + radj][22 + cadj] = 'x'; array1[4 + radj][22 + cadj] = 'x'; array1[5 + radj][22 + cadj] = 'x';
    array1[2 + radj][23 + cadj] = 'x'; array1[6 + radj][23 + cadj] = 'x';
    array1[1 + radj][25 + cadj] = 'x'; array1[2 + radj][25 + cadj] = 'x';
    array1[6 + radj][25 + cadj] = 'x'; array1[7 + radj][25 + cadj] = 'x';
    
}

void checkCells(char active[ROWS][COLS]) {
    
    //Declare work array
    char work[ROWS][COLS];
    //Copy the active array to the work array
    copy(active, work);

    //This nested for loop checks the surrounding cells for there value
    //The count variable keeps track of how many 'x's are found
    //At the end of the nested loop the work cell is set based on the rules of GOL.
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            int count = 0;
            
            if (i == ROWS || j == COLS) {
                
            }
            
                if (active[i - 1][j - 1] == 'x') {
                    count++;
                }
                if (active[i - 1][j] == 'x') {
                    count++;
                }
                if (active[i - 1][j + 1] == 'x') {
                    count++;
                }
                if (active[i][j - 1] == 'x') {
                    count++;
                }
                if (active[i][j + 1] == 'x') {
                    count++;
                }
                if (active[i + 1][j - 1] == 'x') {
                    count++;
                }
                if (active[i + 1][j] == 'x') {
                    count++;
                }
                if (active[i + 1][j + 1] == 'x') {
                    count++;
                }
            
                if (i == (ROWS - 1)|| j == (COLS - 1)) {
                    work[i][j] = active[i][j];
                    count = 0;
                }
            
                //Set work cell based on GOL rules
                if (count > 3 || count < 2) {
                    work[i][j] = '-';
                }
                if (count == 3) {
                    work[i][j] = 'x';
                }
                if (count == 2) {
                    work[i][j] = active[i][j];
                }
        }
    }
    //Copy the results of work back to the active array
    copy (work, active);
    
};

int main() {
    
    int userInput;
    int c1 = 1;
    int c2 = 2;
    int c3 = 3;
    int gen;
    int yn;
    char active[ROWS][COLS];
    bool cont = true;
    bool valid = true;
    
    
    std::cout << "Welcome to the game of life! This version of the game is limited to a 20 x 40 grid. You will have the opportunity to choose from three shapes: blinker, glider, and glider gun." <<std::endl;
    
    //Initialize the active with '-'
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++){
            active[i][j] = '-';
        }
    }
    
    //Allow the player to choose which shape they would like to use.
    std::cout << "Please choose the corresponding number for your shape selection" << std::endl;
    std::cout << "1: blinker" << std::endl;
    std::cout << "2: glider" << std::endl;
    std::cout << "3: glider gun" << std::endl;
    std::cin >> userInput;
    
    //If the blinker is selected, this if statement is used.
    if (userInput == c1) {
        int r;
        int c;
        
        std::cout << "You have selected the blinker, where would you like the center of the blinker to be placed? Please note, the blinker requires a space above, below, left, and right of the center. Because of this the row and column selections for the center of the blinker are limited. The prompts that follow will reflect those ranges. " << std::endl;
        std::cout << "First, please enter the row selection (2 - 19): " << std::endl;
        std::cin >> r;
        std::cout << "Now, please enter the column selection (2 - 39): " << std::endl;
        std::cin >> c;
        
        if ((r < 1 || r > 39) || (c < 2 || c > 39)) {
            valid = false;
            std::cout << "You entered an invalid row or column value... exiting program" << std::endl;
        }
        
        if (valid) {
            blinker(active, r, c);
        }
    }
    
    if (userInput == c2) {
        int r;
        int c;
        
        std::cout << "You have selected the glider, where would you like the bottom right corner of the glider to be place? Due to the shape of the glider there are certain restrictions to where the glider can be placed. The row must have 2 rows above from the row you select, and the column must have 2 columns available to the left from the column you select." << std::endl;
        std:: cout << "First, please enter the row selection (3 - 20): " << std::endl;
        std::cin >> r;
        std::cout << "Now, please enter the column selection (3 - 40): " << std::endl;
        std::cin >> c;
        
        if ((r < 3 || r > 40) || (c < 3 || c > 40)) {
            valid = false;
            std::cout << "You entered an invalid row or column value... exiting program" << std::endl;
        }
        
        if (valid) {
            glider(active, r, c);
        }
    }
    
    if (userInput == c3) {
        
        int radj, cadj;
        
        std::cout << "You have selected the glider gun, due to the size restrictions of the glider gun you are only able to shift the gun to the right or down. The default location has the gun located as far up as it can go and as far left as it can go. You can adjust the gun right by a max of 4 and it can be adjusted down by a max of 11." << std::endl;
        
        std::cout << "First, please select how far down you would like to adjust the gun (0 - 11)" << std::endl;
        std::cin >> radj;
        std::cout << "Please select how far right you would like to adjust the gun. (0 - 4)" <<std::endl;
        std::cin >> cadj;
        
        if ((radj < 0 || radj > 11) || (cadj < 0 || cadj > 4)) {
            valid = false;
            std::cout << "You entered an invalid row adjust or column adjust... exiting program" << std::endl;
        }
        
        if (valid) {
            glidergun(active, radj, cadj);
        }
    }

    if (valid) {
        std::cout << "How many generations would you like to run intially?" << std::endl;
        std::cin >> gen;
        
        system("clear");
        for (int i = 1; i < (ROWS - 3); i++) {
            for (int j = 1; j < (COLS - 3); j++){
                std::cout << active[i][j];
            }
            std::cout << std::endl;
        }
        usleep(250000);
        
        
        
        do {
            
            for (int i = 0; i < gen; i++) {
                system("clear");
                checkCells(active);
                
                for (int i = 1; i < (ROWS - 3); i++) {
                    for (int j = 1; j < (COLS - 3); j++){
                        std::cout << active[i][j];
                    }
                    std::cout << std::endl;
                }
                usleep(250000);
            }
            std::cout << "Would you like to continue? (0 = no, 1 = yes)" << std::endl;
            std::cin >> yn;
            if (yn == 0) {
                cont = false;
            }
            if (yn == 1) {
                cont = true;
                std::cout << "How many generations would you like to run?" << std::endl;
                std::cin >> gen;
            }
            if (yn > 1 || yn < 0) {
                std::cout << "Invalid response... ending program" << std::endl;
                cont = false;
            }
        }
        while(cont);

    }
    
    std::cout << "Thanks for playing the Game of Life!!" << std::endl;
    return 0;
}
