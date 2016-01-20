/*********************************************************************
 ** Author: Rob Navarro
 ** Date: October 25, 2015
 ** Description: This is the implementation of the filter classes
 *********************************************************************/


#include "Filter.hpp"

//Do filter function that will be used in all other classes
void AbstractFilter::doFilter(std::ifstream &in, std::ofstream &out) {
    char c;
    
    while (in.get(c)) {
        c = transform(c);
        out.put(c);
    }
}

//Copy Filter Constructor
CopyFilter::CopyFilter() {
    
};

char CopyFilter::transform(char ch) {
    
    return ch;                      //Since we are just copying we will just return ch
}

//Upper Case Constructor
UpperCaseFilter::UpperCaseFilter() {
    
}

char UpperCaseFilter::transform(char ch) {
    
    if (ch > 96 && ch < 123) {      //Checking if the char is a lower case letter
        ch -= 32;                   //If it is we subtract 32 to get the upper case
    }
    return ch;                      //Return upper case letter or other char
}

//Default encryption filter, encryption is set to 0 by default
EncryptionFilter::EncryptionFilter() {
    setEncryption(0);
}

//encryption filter constructor that takes an encryption value
EncryptionFilter::EncryptionFilter(int newEncryption) {
    setEncryption(newEncryption);
}

char EncryptionFilter::transform(char ch) {
    
    if (ch > 96 && ch < 123) {      //Check if char is lower case letter
        ch -= 97;                   //If so subtract 97 to make a = 0 etc...
        ch += this->encryption;     //Add the users encryption value
        ch %=  26;                  //Take mod 26 to get new letter val
        ch += 97;                   //Add 97 back to char to get actual letter val
    }
    
    else if (ch > 64 && ch < 91) {  //Check if char is upper case letter
        ch -= 65;                   //If so subtract 65 to make A = 0 etc...
        ch += this->encryption;     //Add user encryption value
        ch = ch % 26;               //Take mod 26 to get new letter val
        ch += 65;                   //Add 65 back to char to get actual letter val
    }

    return ch;
}

//Encryption setter/getter methods
int EncryptionFilter::getEncryption() {
    return this->encryption;
}

void EncryptionFilter::setEncryption(int newEncryption) {
    this->encryption = newEncryption;
}