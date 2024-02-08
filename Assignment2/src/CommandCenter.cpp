//--- 2021-2022 Summer Object Oriented Programing Assignment 2 ---//
//--------------------------//
//---Name & Surname: Adil Mahmudlu
//---Student Number: 150200915
//--------------------------//

//-------------Do Not Add New Libraries-------------//
//-------------All Libraries Needed Were Given-------------//
//-------------Do Not Add Change Header Include Paths-------------//
#include "CommandCenter.h"
#include "Robot.h"
#include <iostream>
using namespace std;

/*
****************
BEGIN: CREW CLASS FUNCTION DECLARATIONS 
****************
*/

Crew::Crew(int maxExp, int maxMnr, int ExpSize, int MnrSize) : maxExplorers((maxExp>0 && maxExp<6)? maxExp : 2), maxMiners((maxMnr>0 && maxMnr<6)? maxMnr : 2) {
    explorerCrewSize = (ExpSize>=0 && ExpSize<=maxExplorers) ? ExpSize : maxExplorers;
    minerCrewSize = (MnrSize>=0 && MnrSize<=maxMiners) ? MnrSize : maxMiners;
    crewMaintenanceCost = 0;
    crewManufactureCost = 0;
    ExplorerCrew = new Explorer*[maxExplorers]();
    MinerCrew = new Miner*[maxMiners]();
    for (int i = 0; i < explorerCrewSize; i++) {
        ExplorerCrew[i] = dynamic_cast<Explorer*>(manufactureRobot("explorer"));
        crewManufactureCost += ExplorerCrew[i]->getManufactureCost();
    }
    for (int i = 0; i < minerCrewSize; i++) {
        MinerCrew[i] = dynamic_cast<Miner*>(manufactureRobot("miner"));
        crewManufactureCost += MinerCrew[i]->getManufactureCost();
    }
    initMovement(); /*Robot constructor sets canMove to false, so before starting
    the first turn, set all to true*/
}

Robot* Crew::manufactureRobot(string type) {
    if (type == "def") { //if no argument is sent, then ask for type
        cout << "Type: ";
        cin >> type; 
    }
    while (type != "explorer" && type != "miner") {
        cout << "Please input correct type: ";
        cin >> type;
    }
    int randDur = 1 + rand() % 5;
    float randSpeed = rand()/(float)RAND_MAX;
    if (type == "explorer") {
        return new Explorer(type, 1.5 + randSpeed, randDur);
    }
    else {
        return new Miner(type, 1 + 0.5*randSpeed, randDur);   
    }
}

void Crew::initMovement() {
    for (int i = 0; i < explorerCrewSize; i++) {
        ExplorerCrew[i]->setCanMove(true);
    }
    for (int i = 0; i < minerCrewSize; i++) {
        MinerCrew[i]->setCanMove(true);
    }
}

void Crew::updateDurability() {
    cout << "\nExplorer durability is begin updated";
    int oldExpSize = explorerCrewSize;
    int oldMnrSize = minerCrewSize;
    for (int i = 0; i < explorerCrewSize; i++) {
        if (ExplorerCrew[i]->getDurability() > 0) {
            ExplorerCrew[i]->setDurability(ExplorerCrew[i]->getDurability()-1);
        }
        else {
            (*this)-=ExplorerCrew[i]->getName();
            if (explorerCrewSize < oldExpSize) {
                i--;
                oldExpSize = explorerCrewSize;
            }
        }
    }
    cout << "\nMiner durability is being updated";
    for (int i = 0; i < minerCrewSize; i++) {

        if (MinerCrew[i]->getDurability() > 0) {
            MinerCrew[i]->setDurability(MinerCrew[i]->getDurability()-1);
        }
        else {
            (*this)-=MinerCrew[i]->getName();
            if (minerCrewSize < oldMnrSize) {
                i--;
                oldMnrSize = minerCrewSize;
            }
        }
    }
}

void Crew::operator+=(Robot* R) {
    if (R->getType() == "explorer") {
        if (explorerCrewSize == maxExplorers) {
            cout << "This robot cannot be added, check maximum size of the crew";
            delete R;
            return;
        }
        ExplorerCrew[explorerCrewSize] = dynamic_cast<Explorer*>(R);
        explorerCrewSize++;
        crewManufactureCost += R->getManufactureCost();
    }
    else if (R->getType() == "miner") {
        if (minerCrewSize == maxMiners) {
            cout << "This robot cannot be added, check maximum size of the crew";
            delete R;
            return;
        }
        MinerCrew[minerCrewSize] = dynamic_cast<Miner*>(R);
        minerCrewSize++;
        crewManufactureCost += R->getManufactureCost();
    }
}

void Crew::operator-=(string name) {
    cout << "\n" << name << ": Goodbye";
    if (name[0] == 'e') {
        if (explorerCrewSize <= 1) {
            return;
        }
        for (int i = 0; i < explorerCrewSize; i++) {
            if (ExplorerCrew[i]->getName() == name) {
                delete ExplorerCrew[i];
                explorerCrewSize--;
                for (int j = i; j < explorerCrewSize; j++) {
                    ExplorerCrew[j] = ExplorerCrew[j+1];
                }
                return;
            }
        }
    }
    else if (name[0] == 'm') {
        if (minerCrewSize <= 1) {
            return;
        }
        for (int i = 0; i < minerCrewSize; i++) {
            if (MinerCrew[i]->getName() == name) {
                delete MinerCrew[i];
                minerCrewSize--;
                for (int j = i; j < minerCrewSize; j++) {
                    MinerCrew[j] = MinerCrew[j+1];
                }
                return;
            }
        }
    }
    return;
}

void Crew::showInfo() const {
    cout << "\nexplorerCrew Size:" << explorerCrewSize;
    cout << "\nminerCrew Size:" << minerCrewSize;
    for (int i = 0; i < explorerCrewSize; i++) {
        ExplorerCrew[i]->showInfo();
    }
    for (int i = 0; i < minerCrewSize; i++) {
        MinerCrew[i]->showInfo();
    }
    cout << "\nTotal manufacture cost: " << crewManufactureCost;
    cout << "\nTotal maintenance cost: " << crewMaintenanceCost << "\n";
}

int Crew::getCrewManufactureCost() const {
    return crewManufactureCost;
}

float Crew::getCrewMaintenanceCost() const {
    return crewMaintenanceCost;
}

void Crew::setCrewMaintenanceCost(float c) {
    crewMaintenanceCost = c;
}

int Crew::getExplorerCrewSize() const {
    return explorerCrewSize;
}

int Crew::getMinerCrewSize() const {
    return minerCrewSize;
}

Explorer** Crew::getExplorers() const {
    return ExplorerCrew;
}

Miner** Crew::getMiners() const {
    return MinerCrew;
}

Crew::~Crew() {
    for (int i = 0; i < explorerCrewSize; i++) {
		delete ExplorerCrew[i];
	}
	for (int i = 0; i < minerCrewSize; i++) {
		delete MinerCrew[i];
	}
	delete ExplorerCrew;
	delete MinerCrew;
}

/*
****************
END: CREW CLASS FUNCTION DECLARATIONS 
****************
*/

/*
****************
BEGIN: COMMANDCENTER CLASS FUNCTION DECLARATIONS 
****************
*/

CommandCenter::CommandCenter(int needed, float area, int worth) : neededSelenium(needed), searchArea(area), seleniumWorth(worth) {
    turnCount = 1;
    profit = 0;
}

bool CommandCenter::isGameEnded() {
    if (Explorer::totalExploredArea >= searchArea) {
        Miner::totalGatheredSelenium >= neededSelenium ? cout << "\nCongrats!\n" : cout << "\nMission Failed!\n";
    }
    return (Explorer::totalExploredArea >= searchArea);
}

void CommandCenter::calculateProfit(Crew& c) {
    float expenses = c.getCrewMaintenanceCost() + c.getCrewManufactureCost();
    int revenue = Miner::totalGatheredSelenium * seleniumWorth;
    cout << "\nProfit:" << revenue-expenses;
    cout << "\nExpenses:" << expenses;
    cout << "\nSelenium Revenue:" << revenue << "\n";
}

void CommandCenter::operator++() {
    turnCount++;
}

void CommandCenter::showInfo() {
    cout << "\nCurrent turn: " << turnCount;
    cout << "\nAim: " << neededSelenium << " selenium.";
    cout << "\nCollected: " << Miner::totalGatheredSelenium;
    cout << "\nTotal Search Area: " << searchArea;
    cout << "\nExplored Area: " << Explorer::totalExploredArea;
    cout << "\nCurrently, there are " << Explorer::totalNumberOfSeleniumArea << " area/s that include selenium.\n"; 
}

/*
****************
END: COMMANDCENTER CLASS FUNCTION DECLARATIONS 
****************
*/