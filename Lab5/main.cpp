/*********************************************************************
 ** Author: Rob Navarro
 ** Date: October 29, 2015
 ** Description: A program that has 3 different text filter options
 presented in lab 4.
 *********************************************************************/

#include <stdio.h>
#include <iostream>
#include <fstream>
#include <string>
#include "Filter.hpp"


int main(int argc, const char * argv[]) {
    
    std::ifstream* inFile = new std::ifstream;
    std::ofstream* outFile = new std::ofstream;
    std::string input;
    std::string output;
    std::string userInput;
    
    //Declare filter classes to be used in program... encryption listed below
    CopyFilter* c1 = new CopyFilter;
    UpperCaseFilter* u1 = new UpperCaseFilter();
    int encryption;
    
    //Prompt user for filter type
    std::cout << "Please select a number for the filter that you'd like to run " << std::endl;
    std::cout << "1. Copy Filter" << std::endl;
    std::cout << "2. Upper Case Filter" << std::endl;
    std::cout << "3. Encryption Filter" << std::endl;
    std::cin >> userInput;
    
    //Prompt user for input/output file names
    std::cout << "Please enter the name of the input file: ";
    std::cin.ignore();
    getline(std::cin, input);
    std::cout << input << std::endl;
    std::cout << "Please enter the name of the output file: ";
    getline(std::cin, output);
    std::cout << output << std::endl;
    
    //Open input and output files
    inFile->open(input.c_str(), std::ifstream::in);
    outFile->open(output.c_str());
    
    //If the file fails to open, exit
    if (inFile->fail()) {
        std::cout << "The input file was not found" << std::endl;
        return 1;
    }
    
    //Copy filter option
    if (userInput == "1") {
        c1->doFilter(*inFile, *outFile);
    }
    
    //Upper case filter option
    else if (userInput == "2") {
        u1->doFilter(*inFile, *outFile);
    }
    
    //Encryption filter option
    else if (userInput == "3") {
        std::cout << "What encryption value would you like to use? ";
        std::cin >> encryption;
        
        EncryptionFilter* e1 = new EncryptionFilter(encryption);    //set encryption based on user
        e1->doFilter(*inFile, *outFile);
    }

    //Close input/output files
    inFile->close();
    outFile->close();

    
    return 0;
}