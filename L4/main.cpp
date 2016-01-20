/*********************************************************************
 ** Author: Rob Navarro
 ** Date: October 22, 2015
 ** Description: A program that goes through the 3 recursive problems
                 presented in lab 4. 
 *********************************************************************/

#include <iostream>
#include <string>
using std::string;
using std::cout;
using std::cin;
using std::endl;
using std::getline;

void reverseString(string);
int arraySum(int, int[]);
int triNum(int);

int main() {
    string input;
    int aSize;
    int tNums;
    string userSelection;
    bool cont = true;
    
    //This do/while loop will continue until the user wants to exit
    do {
        cout << "Please choose the recursion function that you'd wish to try: " << endl;
        cout << "1. Reverse String" << endl;
        cout << "2. Sum of Array" << endl;
        cout << "3. Triangle Number" << endl;
        cout << "4. Exit" << endl;
        cin >> userSelection;
                
        if (userSelection == "1") {
            //Reverse user entered string
            cout << "Enter a string to reverse: ";
            //Grab the whole line, including spaces
            cin.ignore();
            getline(cin, input);
            cout << "The reversed string is: ";
            reverseString(input);
            cout << endl;
        }
        
        else if (userSelection == "2") {
            //Set the size of the array based on how many elements the user wants
            cout << "How many values will your array have: ";
            cin >> aSize;
            int uArray[aSize];
            
            //Prompt the user for the value of each element in the array
            for (int i = 0; i < aSize; i++) {
                cout << "Enter array value " << (i + 1) << ": ";
                cin >> uArray[i];
            }
            
            //Call the arraySum function and return the sum of the array
            cout << "The sum of the array is: ";
            cout << arraySum(aSize, uArray) << endl;
            cout << endl;

        }
        
        else if (userSelection == "3") {
            //Find out how many rows the user wants in for the triangle
            cout << "How many rows would you like the triangle to have? ";
            cin >> tNums;
            cout << "The sum of the elements in the triangle is: " << triNum(tNums) << endl;
            cout << endl;
        }
        
        //This if statment changes cont to false so that the loop exits
        else if (userSelection == "4") {
            cont = false;
        }
        
        //If the user enters an invalid selection ask them to re-enter value
        else {
            cout << "Invalid selection, please try again" << endl;
            cout << endl;
        }
            
    } while (cont);
    
    return 0;
}

void reverseString(string userInput) {
    
    //Once the string length is 0 return a new line (base case)
    if (userInput.length() == 0) {
        cout << "\n";
    }
    
    else {
        //Output the last value of the string
        cout << userInput.substr(userInput.length() - 1, userInput.length());
        //resize the string so that the last value is dropped
        userInput.resize(userInput.length() - 1);
        //re-enter the reversestring function (recursion)
        reverseString(userInput);
    }
}

int arraySum(int arraySize, int userArray[]) {
    //This is the base case for arraySum
    //If the array doesn't have any values return a sum of 0
    if (arraySize < 1 ) {
        return 0;
    }
    //This is the recursive case for arraySum
    else {
        return userArray[arraySize - 1] + arraySum((arraySize - 1), userArray);
    }
}

int triNum(int rows) {
    //This is the base case for triNum
    //If the rows are set to 0, 0 is returned
    if (rows == 0) {
        return 0;
    }
    //This is the recursive case for triNum
    else {
        return rows + triNum(rows - 1);
    }
}