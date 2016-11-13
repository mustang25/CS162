/*********************************************************************
 ** Author: Rob Navarro
 ** Date: November 12, 2015
 ** Description: A program that can search, sort, and binary search a file.
 ** In order for the binary search to work a sorted file must be created.
 *********************************************************************/

#include <iostream>
#include <vector>
#include <fstream>

int search(std::vector<int>, int);
std::vector<int> sort(std::vector<int>);
int binarySearch(std::vector<int>, int);


int main(int argc, const char * argv[]) {
    std::ifstream* inFile = new std::ifstream;
    std::ofstream* outFile = new std::ofstream;
    std::string input;
    std::string output;
    std::string userInput;
    std::string validInput;
    int fileInt;
    int numPos;
    std::vector<int> workingVector;
    
    //Prompt user for function
    std::cout << "This program will perform various operations on an input file." << std::endl;
    std::cout << "Please not the binary search option only works if a file has been sorted." << std::endl;
    std::cout << "If you wish to use this option, please select option 2 first and then use the created file to perform a binary search" << std::endl;
    std::cout << "Please select the search/sort function that you wish to run: " << std::endl;
    std::cout << "1. Search for target value" << std::endl;
    std::cout << "2. Sort a set of values" << std::endl;
    std::cout << "3. Search for a target value via binary search" << std::endl;
    std::cin >> userInput;
    
    //Prompt user for input file name
    std::cout << "Please enter the name of the input file: ";
    std::cin.ignore();
    getline(std::cin, input);

    //Open input file
    inFile->open(input.c_str(), std::ifstream::in);
    
    //If the file fails to open, exit
    if (inFile->fail()) {
        std::cout << "The input file was not found" << std::endl;
        return 1;
    }
    
    //Load vector
    while (*inFile >> fileInt) {
        workingVector.push_back(fileInt);
    }
    
    //Close input file
    inFile->close();
    
    //If user wants to find a value without sorting
    if (userInput == "1") {
        std::cout << "What number would you like to find in the file? ";
        std::cin >> fileInt;
        numPos = search(workingVector, fileInt);
        //If number is not found inform user and exit
        if (numPos == -1) {
            std::cout << "Sorry that number was not found in the file." << std::endl;
        }
        else {
            std::cout << fileInt << " is number " << numPos + 1 << " in the file." << std::endl;
        }
    }
    
    else if (userInput == "2") {
        //Prompt user for the name of output file and open it
        std::cout << "This function will sort the input file that you entered and create an output file." << std::endl;
        std::cout << "Please enter the name of the output file: ";
        getline(std::cin, output);
        //Open output file
        outFile->open(output.c_str());
        
        //Call sort function for the vector
        workingVector = sort(workingVector);
        
        //Write vector to output file
        
        for (int i = 0; i < workingVector.size(); i++) {
            *outFile << workingVector[i];
            *outFile << std::endl;
        }
        
    //Close output file
    outFile->close();
    }
    
    //If the user wishes to use binary sorting alert them that only a sorted file will work correctly
    else if (userInput == "3") {
        std::cout <<"Please enter 1 if you are using a sorted file, if any other value is entered the program will end. Also, if the file is not sorted this fucntion will not work correctly." << std::endl;
        std::cin >> validInput;
        
        if (validInput == "1") {
            std::cout << "What number would you like to find in the file? ";
            std::cin >> fileInt;
            numPos = binarySearch(workingVector, fileInt);
            //If number is not found inform user
            if (numPos == -1) {
                std::cout << "Sorry that number was not found in the file." << std::endl;
            }
            else {
                std::cout << fileInt << " is number " << numPos + 1 << " in the file." << std::endl;
            }
            
        }

    }
    
    else {
        std::cout << "Invalid option selected... exiting program." << std::endl;
    }

    return 0;
}

//Standard search function, accepts a vector and value being searched for
int search(std::vector<int> test, int value) {
    int index = 0;
    int position = -1;
    bool found = false;
    
    //Continue through vector until a value is found. If no value is found return -1.
    while (index < test.size() && !found) {
        if (test[index] == value) {
            found = true;
            position = index;
        }
        index++;
    }
    return position;
}

//Sort function
std::vector<int> sort(std::vector<int> test) {
    int temp;
    bool swap;
    
    do {
        swap = false;
        //The for loop must stop 1 short of the last value in order to not compare an empty value
        //If the current value is greater than the next value in the vector... the vals are swapped
        for (int i = 0; i < test.size() - 1; i++) {
            if (test[i] > test[i + 1]) {
                temp = test[i];
                test[i] = test[i + 1];
                test[i + 1] = temp;
                swap = true;
            }
        }
        //The loop restarts if a value was swapped
    } while (swap);
    
    return test;
}

//This function uses the binary search method to find a value in a sorted vector
int binarySearch(std::vector<int> test, int value) {
    //Default values for first and last
    int first = 0;
    int last = test.size() - 1;
    int middle;
    int position = -1;
    bool found = false;
    
    while (!found && first <= last) {
        //set the middle value for the search
        middle = (first + last) / 2;
        if (test[middle] == value) {
            found = true;
            position = middle;
        }
        //If middle value is greater we will decrease the last
        //If middle value is less we will increase the first
        else if (test[middle] > value) {
            last = middle - 1;
        }
        else {
            first = middle + 1;
        }
        
    }
    return position;
}


