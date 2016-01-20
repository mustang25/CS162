/*********************************************************************
 ** Author: Rob Navarro
 ** Date: November 25, 2015
 ** Description: This program displays two queues that are randomly filled
 ** with people for 5 clicks. Click 3 is the highest point and then the 
 ** values decrease to 0. Once no more people are being added we see how 
 ** quickly the queues are emptied.
 *********************************************************************/


#include <iostream>
#include <queue>
#include <stdlib.h>
#include <stdio.h>
#include <ctime>
#include <vector>

using std::queue;
using std::cout;
using std::cin;
using std::endl;
using std::vector;


void fillQueue(queue<int> &, int);
void emptyQueue(queue<int> &, int);
void processRound (queue<int>&, vector<queue<int> >&, int, int);
int smallestQueue (vector<queue<int> >&);
int largestQueue (vector<queue<int> >&);
void fillQueueVec(vector<queue<int> >&, int);
void emptyQueueVec(vector<queue<int> >&, int);
void processRoundVec(vector<queue<int> >&);
void printQueueTot(queue<int>, vector<queue<int > >, int);

int main(void) {
    srand(time(NULL));
    int tellers;
    int randomPeople;
    int waitTime;
    int singleQueueWait;
    int multiQueueWait;
    cout << "How many tellers should be accounted for? ";
    cin >> tellers;
    cin.ignore();
    
    //Declaring single queue and vector of queues
    queue<int> simulation1;
    vector<queue<int> > multipleQueues;
    
    //Fill vector with a queue for each teller
    for (int i = 0; i < tellers; i++) {
        multipleQueues.push_back(queue<int>());
    }
    
    //Click 1
    randomPeople = (tellers + rand()%tellers+1);
    cout << "There were " << randomPeople << " people added to the queues." << endl;
    processRound(simulation1, multipleQueues, randomPeople, tellers);
    printQueueTot(simulation1, multipleQueues, waitTime);
    waitTime++;
    
    //Click 2
    randomPeople = (2*tellers + (rand()%tellers+1));
    cout << "There were " << randomPeople << " people added to the queues." << endl;
    processRound(simulation1, multipleQueues, randomPeople, tellers);
    printQueueTot(simulation1, multipleQueues, waitTime);
    waitTime++;
    
    //Click 3
    randomPeople = (3*tellers + (rand()%tellers+1));
    cout << "There were " << randomPeople << " people added to the queues." << endl;
    processRound(simulation1, multipleQueues, randomPeople, tellers);
    printQueueTot(simulation1, multipleQueues, waitTime);
    waitTime++;
    
    //Click 4
    randomPeople = (2*tellers + (rand()%tellers+1));
    cout << "There were " << randomPeople << " people added to the queues." << endl;
    processRound(simulation1, multipleQueues, randomPeople, tellers);
    printQueueTot(simulation1, multipleQueues, waitTime);
    waitTime++;
    
    //Click 5
    randomPeople = (tellers + rand()%tellers+1);
    cout << "There were " << randomPeople << " people added to the queues." << endl;
    processRound(simulation1, multipleQueues, randomPeople, tellers);
    printQueueTot(simulation1, multipleQueues, waitTime);
    waitTime++;
    
    //After we have gone through 5 clicks will just want to empty the queues and see how many rounds/clicks it takes
    //We will now count the amount of clicks individually for the single and multi queue
    singleQueueWait = waitTime;
    multiQueueWait = waitTime;
    
    do {
        //Popping values for the multi queue
        if (!multipleQueues[0].empty()) {
            emptyQueueVec(multipleQueues, tellers);
            multiQueueWait++;
        }
        //Popping values for the single queue
        if (!simulation1.empty()) {
            emptyQueue(simulation1, tellers);
            singleQueueWait++;
        }
        
        //If both queues are empty we will not display the current totals
        if (!simulation1.empty() && !multipleQueues[0].empty()) {
            printQueueTot(simulation1, multipleQueues, waitTime);
        }
        //Instead we will tell the user that all queues are empty
        else {
            cout << "All queues are empty" << endl;
        }
        waitTime++;
    }
    while (!simulation1.empty() && !multipleQueues[0].empty());

    cout << "It took " << singleQueueWait << " rounds to empty the single queue" << std::endl;
    cout << "It took " << multiQueueWait << " rounds to empty the multi queue" << std::endl;

    return 0;
}

//This function fills the single queue
void fillQueue(queue<int> &fill, int people) {
    for (int i = 0; i < people; i++) {
        fill.push(0);
    }
}

//This function empties the single queue for 1 click
void emptyQueue(queue<int> &empty, int tellers) {
    for (int i = 0; i < tellers; i++) {
        empty.pop();
        if (empty.empty()) {
            i = tellers;
        }
    }
}

//This function proccesses the queue functions for each round
void processRound(queue <int> &q1, vector<queue<int> > &q2, int randomPeople, int tellers) {
    fillQueue(q1, randomPeople);
    emptyQueue(q1, tellers);
    fillQueueVec(q2, randomPeople);
    emptyQueueVec(q2, tellers);
}

//This function finds the smallest queue and returns its location in the vector
int smallestQueue (vector<queue<int> > &checkQueue) {
    int returnVal = 0;
    int smallest = 99;
    
    //We will scan the vector checking the size of each queue and storing the smallest location
    for (int i = 0; i < checkQueue.size(); i++) {
        if (checkQueue[i].size() < smallest) {
            smallest = checkQueue[i].size();
            returnVal = i;
        }
    }
    return returnVal;
}

//This function finds the largest queue and returns location of it in the vector
int largestQueue (vector<queue<int> > &checkQueue) {
    int returnVal = 0;
    int largest = 0;
    
    //We will scan the vector checking the size of each queue and storing the largest location
    for (int i = 0; i < checkQueue.size(); i++) {
        if (checkQueue[i].size() > largest) {
            largest = checkQueue[i].size();
            returnVal = i;
        }
    }
    return returnVal;
}

//This function adds values to the vector of queues
void fillQueueVec(vector<queue<int> > &fill, int people) {
    int smallestQ = smallestQueue(fill);
    int qSize = fill.size();
    
    //This do loop will fill the vector of queues with the amount of people that are entering
    do {
        fill[smallestQ].push(0);
        smallestQ++;
        if (smallestQ > qSize - 1) {
            smallestQ = 0;
        }
        people--;
    }
    while (people > 0);
}

//This function empties values from the vector of queues
void emptyQueueVec(vector<queue<int> > &empty, int tellers) {
    int largestQ = largestQueue(empty);
    int qSize = empty.size();
    
    //This do/while loop will empty the queue for the total number of tellers
    do {
        empty[largestQ].pop();
        largestQ++;
        if (largestQ > qSize - 1) {
            largestQ = 0;
        }
        tellers--;
    }
    while (tellers > 0);
    
}

//This function display the total amoount of people in line following 1 click
//It also prompts the user to press enter in order to continue to the next round
void printQueueTot(queue<int> single, vector<queue<int > > multi, int waitTime) {
    int qTot = 0;

    
    cout << "After round "<< waitTime + 1 << " here are the current line totals: " << endl;
    cout << "Single Queue: " << single.size() << " people" << endl;
    
    for (int i = 0; i < multi.size(); i++) {
        qTot += multi[i].size();
    }

    cout << "Multi Queue: " << qTot << " people." << endl;
    cout << "Press ENTER to continue";
    cin.ignore();
    cout << endl;
    cout << endl;
    
}

