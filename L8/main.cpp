/*********************************************************************
 ** Author: Rob Navarro
 ** Date: November 18, 2015
 ** Description: A driver program for lab 8. This main allows the user
 ** to add values to a queue. Remove the front of the queue, and display
 ** the contents of the queue.
 *********************************************************************/


#include "Queue.hpp"

void displayQueue(Queue);

int main(int argc, const char * argv[]) {
    std::string userInput;
    int userInt;
    Queue q;
    
    std::cout << "Welcome to the Lab 8 Queue!" << std::endl;
    //Menu that allows the user to add, remove and dispaly values of queue
    //*Note for the purpose of this lab the display function will empty the queue
    //The user can enter 4 to exit the program
    do {
        std::cout << "Select the corresponding number for the action you'd like to take" << std::endl;
        std::cout << "1. Add number to queue" << std::endl;
        std::cout << "2. Remove front value from queue" << std::endl;
        std::cout << "3. Display queue *Note: this will also empty the queue" << std:: endl;
        std::cout << "4. Exit" << std::endl;
        std::cout << "Selection: ";
        std::cin >> userInput;
    
        if (userInput == "1") {
            std::cout << "What value would you like to add to the queue? ";
            std::cin >> userInt;
            q.addBack(userInt);
        }
        else if (userInput == "2") {
            q.removeFront();
        }
        else if (userInput == "3") {
            //While loop that dispalys the contents of queue until it is empty (indicated by a -1 return val)
            if (q.getFront() == -1) {
                std::cout << "The queue is currently empty so there is nothing to display!" << std::endl;
            }
            else {
                while (q.getFront() != -1) {
                    std::cout << q.getFront() << std::endl;
                    q.removeFront();
                }
            }
        }
        else if (userInput != "4"){
            std::cout << "Invalid selection, please try again" << std::endl;
        }
    } while (userInput != "4");
    

    return 0;
    
}
