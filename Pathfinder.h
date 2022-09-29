#pragma once
#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <fstream>
#include <cstdlib>
#include "PathfinderInterface.h"

using namespace std;

class Pathfinder : public PathfinderInterface {
protected:
	const int WALL = 0;
	const int BACKGROUND = 1;
	const int TEMP = 2;
	const int PATH = 3;
	int currentMaze[5][5][5];
	vector<string> path;
	
public:
	Pathfinder();
	~Pathfinder();
	bool FindMazePath(int tempMaze[5][5][5],int x, int y, int z);
	string toString() const;
	void createRandomMaze();
	bool importMaze(string file_name);
	vector<string> solveMaze();
};