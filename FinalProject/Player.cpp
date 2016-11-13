/*********************************************************************
 ** Author: Rob Navarro
 ** Date: December 8, 2015
 ** Description: This implements the interface for the Player class.
 *********************************************************************/

#include "Player.hpp"

Player::Player() {
    
}

//Constructor that sets name as well as health and turns until tornado strikes
//Also sets all rooms to false to indicate they haven't been visited.
void Player::setName(std::string newName) {
    name = newName;
    health = 100;
    tornado = 15;
    master = false;
    office = false;
    entry = false;
    garage = false;
    bedroom = false;
    dining = false;
    kitchen = false;
    living = false;
}

//set player name
std::string Player::getName() {
    return name;
}

//adjust health or tornado stats
void Player::addHealth(int add) {
    health += add;
}

void Player::subHealth(int sub) {
    health -= sub;
}

int Player::getHealth() {
    return health;
}

int Player::getTornado() {
    return tornado;
}

void Player::addTornado(int adjust) {
    tornado += adjust;
}

void Player::subTornado(int adjust) {
    tornado -= adjust;
}

//Getter functions for all room bools
bool Player::getMaster() {
    return master;
}

bool Player::getOffice() {
    return office;
}

bool Player::getEntry() {
    return entry;
}

bool Player::getGarage() {
    return garage;
}

bool Player::getBedroom() {
    return bedroom;
}

bool Player::getDining() {
    return dining;
}

bool Player::getKitchen() {
    return kitchen;
}

bool Player::getLiving() {
    return living;
}

bool Player::getBasement() {
    return basement;
}

//set functions for all rooms
void Player::setMaster() {
    master = true;
}

void Player::setOffice() {
    office = true;
}

void Player::setEntry() {
    entry = true;
}

void Player::setGarage() {
    garage = true;
}

void Player::setBedroom() {
    bedroom = true;
}

void Player::setDining() {
    dining = true;
}

void Player::setKitchen() {
    kitchen = true;
}

void Player::setLiving() {
    living = true;
}

void Player::setBasement() {
    basement = true;
}