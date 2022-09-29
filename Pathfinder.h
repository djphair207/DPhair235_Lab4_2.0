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
	const int ROWS = 5;
	const int COLS = 5;
	const int LVLS = 5;
	const int BACKGROUND = 1;
	const int WALL = 0;
	const int TEMP = 2;
	const int PATH = 3;
	int currentMaze[5][5][5];
	vector<string> path;
	
		//This checks each neighbor for 1(true) or 0(false)
	

public:
	Pathfinder();
	~Pathfinder();
	bool FindMazePath(int tempMaze[5][5][5],int x, int y, int z);
	string toString();
	void createRandomMaze();
	bool importMaze(string file_name);
	vector<string> solveMaze();
};