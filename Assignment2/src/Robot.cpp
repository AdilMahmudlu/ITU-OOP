//--- 2021-2022 Summer Object Oriented Programing Assignment 2 ---//
//--------------------------//
//---Name & Surname: Adil Mahmudlu
//---Student Number: 150200915
//--------------------------//

//-------------Do Not Add New Libraries-------------//
//-------------All Libraries Needed Were Given-------------//
//-------------Do Not Add Change Header Include Paths-------------/

#include <iostream>
using namespace std;
#include "Robot.h"

/*
****************
BEGIN: STATIC MEMBER INITIALIZATIONS
****************
*/

int Robot::unqID = 1;
int Explorer::totalNumberOfSeleniumArea = 0;
float Explorer::totalExploredArea = 0;
int Miner::totalGatheredSelenium = 0;

/*
****************
END: STATIC MEMBER INITIALIZATIONS
****************
*/

/*
****************
BEGIN: ROBOT CLASS FUNCTION DECLARATIONS 
****************
*/

// Robot::Robot(string type, int manufactureCost) : RobotType(type), manufactureCost(manufactureCost) {
// }

Robot::Robot(string type, float speed, int durability, int manufactureCost, float maintenanceCost) : RobotType(type), manufactureCost(manufactureCost) {
    if (type == "explorer") {
        RobotName = "exp-" + to_string(unqID);
        unqID++;
    }
    else if (type == "miner") {
        RobotName = "mnr-" + to_string(unqID);
        unqID++;
    }
    this->speed = speed;
    this->durability = durability;
    this->maintenanceCost = maintenanceCost;
    canMove = false;
}

void Robot::operator=(const Robot& R) {
    RobotName = R.RobotName;
    speed = R.speed;
    durability = R.durability;
    maintenanceCost = R.maintenanceCost;
    canMove = R.canMove;
}

void Robot::showInfo() const {
    cout << "\nName: " << RobotName;
    cout << "\nType: " << RobotType;
    cout << "\nSpeed: " << speed;
    cout << "\nDurability: " << durability;
    cout << "\nManufactureCost: " << manufactureCost;
    cout << "\nMaintenanceCost: " << maintenanceCost;
    cout << "\nCan Move: " << canMove;
}

void Robot::setCanMove(bool b) {
    canMove = b;
}

string Robot::getName() const {
    return RobotName;
}

string Robot::getType() const {
    return RobotType;
}

int Robot::getDurability() const {
    return durability;
}

void Robot::setDurability(int d) {
    durability = d;
}

float Robot::getSpeed() const {
    return speed;
}

int Robot::getManufactureCost() const {
    return manufactureCost;
}

float Robot::getMaintenanceCost() const {
    return maintenanceCost;
}

/*
****************
END: ROBOT CLASS FUNCTION DECLARATIONS 
****************
*/

/*
****************
BEGIN: EXPLORER CLASS FUNCTION DECLARATIONS 
****************
*/

// Explorer::Explorer() : Robot("explorer", 3000) {
//     detectedSelenium = false;
//     exploredArea = 0;
// }

Explorer::Explorer(string type, float speed, int durability) : Robot(type, speed, durability, 3000, 450/speed) {
    detectedSelenium = false;
    exploredArea = 0; 
}

bool Explorer::move() {
    if (getDurability() > 0) {
        return canMove;
    }
    else {
        return false;
    }
}

void Explorer::explore() {
    float randNum = rand() % 101;
    if (randNum >= 40) {
        detectedSelenium = true;
        totalNumberOfSeleniumArea++;
    }
    else {
        detectedSelenium = false;
    }
    totalExploredArea += 1500;
    exploredArea = 1500;
}

void Explorer::operator=(const Explorer& E) {
    Robot::operator=(E);
    exploredArea = E.exploredArea;
    detectedSelenium = E.detectedSelenium;
}

void Explorer::showInfo() const {
    Robot::showInfo();
    cout << "\nexplored area: " << exploredArea;
}

/*
****************
END: EXPLORER CLASS FUNCTION DECLARATIONS 
****************
*/

/*
****************
BEGIN: MINER CLASS FUNCTION DECLARATIONS 
****************
*/

// Miner::Miner() : Robot("miner", 5000) {
//     gatheredSelenium = 0;
// }

Miner::Miner(string type, float speed, int durability) : Robot(type, speed, durability, 5000, 750/speed) {
    gatheredSelenium = 0;
}

void Miner::mine() {
    int randNum = 5*(10 + (rand() % 91));
    gatheredSelenium = randNum;
    totalGatheredSelenium += randNum;
    Explorer::totalNumberOfSeleniumArea--;
}

bool Miner::move() {
    if (getDurability() > 0 && canMove && Explorer::totalNumberOfSeleniumArea > 0) {
        return true;
    }  
    else {
        return false;
    }
}

void Miner::operator=(const Miner& M) {
    Robot::operator=(M);
    gatheredSelenium = M.gatheredSelenium;
}

void Miner::showInfo() const {
    Robot::showInfo();
    cout << "\n# of gathered selenium: " << gatheredSelenium;
}

/*
****************
END: MINER CLASS FUNCTION DECLARATIONS 
****************
*/