//--- 2021-2022 Summer Object Oriented Programing Assignment 2 ---//
//--------------------------//
//---Name & Surname: Adil Mahmudlu
//---Student Number: 150200915
//--------------------------//

#include <iostream>
#include "Robot.h"
using namespace std;
class Crew{
	friend class CommandCenter;
	private:
		const int maxExplorers;
		const int maxMiners;
		int crewManufactureCost;
		float crewMaintenanceCost;
		int explorerCrewSize;
		int minerCrewSize;
		Explorer **ExplorerCrew;
		Miner **MinerCrew;
	public:
		Crew(int, int, int, int);
		Robot* manufactureRobot(string = "def");
		void initMovement();
		void updateDurability();
		void operator+=(Robot*);
		void operator-=(string);
		void showInfo() const;
		int getCrewManufactureCost() const;
		float getCrewMaintenanceCost() const;
		void setCrewMaintenanceCost(float);
		int getExplorerCrewSize() const;
		int getMinerCrewSize() const;
		Explorer** getExplorers() const;
		Miner** getMiners() const;
		~Crew();
};

class CommandCenter{
	private:
		const int neededSelenium;
		const float searchArea;
		const int seleniumWorth;
		int turnCount;
		float profit;
	public:
		CommandCenter(int, float, int);
		bool isGameEnded();
		void calculateProfit(Crew&);
		void operator++();
		void showInfo();
};