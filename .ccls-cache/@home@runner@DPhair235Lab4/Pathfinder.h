#pragma once
#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <fstream>
#include <cstdlib>
#include "PathfinderInterface.h"

//NEED TO CALL srand(), look into it

using namespace std;

class Pathfinder : public PathfinderInterface {
protected:
	int currentMaze[5][5][5];
	bool FindMazePath(int x, int y, int z);
		//This checks each neighbor for 1(true) or 0(false)

public:
	Pathfinder();
	~Pathfinder() {};
	string toString();
	void createRandomMaze();
	bool importMaze(string file_name);
	vector<string> solveMaze();
};