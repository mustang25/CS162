/*********************************************************************
 ** Author: Rob Navarro
 ** Date: October 29, 2015
 ** Description: This defines the interface for the Filter classes.
 *********************************************************************/


#ifndef Filter_hpp
#define Filter_hpp

#include <stdio.h>
#include <iostream>
#include <fstream>
#include <string>

class AbstractFilter {
private:
    
public:
    void doFilter(std::ifstream &in, std::ofstream &out);
    virtual char transform(char ch) = 0;
};

class CopyFilter: public AbstractFilter {
private:
    
public:
    CopyFilter();
    char transform(char ch);
};

class UpperCaseFilter: public AbstractFilter {
private:
    
public:
    UpperCaseFilter();
    char transform(char ch);
};

class EncryptionFilter: public AbstractFilter {
private:
    int encryption;
    
public:
    EncryptionFilter();
    EncryptionFilter(int newEncryption);
    void setEncryption(int newEncryption);
    int getEncryption();
    char transform(char ch);
};

#endif /* Filter_hpp */
