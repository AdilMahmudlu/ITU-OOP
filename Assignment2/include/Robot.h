//--- 2021-2022 Summer Object Oriented Programing Assignment 2 ---//
//--------------------------//
//---Name & Surname: Adil Mahmudlu
//---Student Number: 150200915
//--------------------------//
#include <iostream>
#ifndef _H
#define _H
using namespace std;
class Robot {
	private:
		static int unqID;
		string RobotName;
		const string RobotType;
		float speed;
		int durability;
		const int manufactureCost;
		float maintenanceCost;
	protected:
		bool canMove;
	public:
		// Robot(string, int);
		Robot(string, float, int, int, float);
		void operator=(const Robot&);
		virtual void showInfo() const;
		void setCanMove(bool);
		string getName() const;
		string getType() const;
		int getDurability() const;
		void setDurability(int);
		float getSpeed() const;
		int getManufactureCost() const;
		float getMaintenanceCost() const;
		virtual ~Robot(){};
}; 

class Explorer : public Robot {
	friend class Miner;
	friend class CommandCenter;
	private:
		static float totalExploredArea;
		static int totalNumberOfSeleniumArea;
		float exploredArea;
		bool detectedSelenium;
	public:
		// Explorer();
		Explorer(string, float, int);
		bool move();
		void explore();
		void operator=(const Explorer&);
		void showInfo() const;
		~Explorer(){};
};

class Miner : public Robot {
	friend class CommandCenter;
	private:
		static int totalGatheredSelenium;
		int gatheredSelenium;
	public:
		// Miner();
		Miner(string, float, int);
		void mine();
		bool move();
		void operator=(const Miner&);
		void showInfo() const;
		~Miner(){};
};

#endif