#include "Pathfinder.h"

Pathfinder::Pathfinder(){
	for(int i = 0; i < 5; i++){
		for(int j = 0; j < 5; j++){
			for(int k = 0; k < 5; k++){
				currentMaze[i][j][k] = 1;
			}
		}
	}
}

bool Pathfinder::FindMazePath(int x,int y,int z){
	//func for checking neighbors
	if(currentMaze[x][y][z] == 1){
		return true;
	}
	else{
		return false;
	}
}

string Pathfinder::toString() {
	stringstream ss;
	string contents;
	for(int i = 0; i < 5; i++){
		for(int j = 0; j < 5; j++){
			for(int k = 0; k < 5; k++){
				ss << currentMaze[i][j][k] << " ";
			}
			ss << endl;
		}
		if(i < 4){
			ss << endl;
		}
	}
	contents = ss.str();
	return contents;
}

void Pathfinder::createRandomMaze() {
	for(int i = 0; i < 5; i++){
		for(int j = 0; j < 5; j++){
			for(int k = 0; k < 5; k++){
				currentMaze[i][j][k] = rand() % 2;
			}
		}
	}
	currentMaze[0][0][0] = 1;
	currentMaze[4][4][4] = 1;
}

bool Pathfinder::importMaze(string file_name) {
	ifstream fin;
	int tempMaze[5][5][5];

	fin.open(file_name);
	if(!fin.is_open()){
		return false;
	}
	for(int i = 0; i < 5; i++){
		for(int j = 0; j < 5; j++){
			for(int k = 0; k < 5; k++){
				fin >> tempMaze[i][j][k];
				if(tempMaze[i][j][k] != 1 || tempMaze[i][j][k] != 0 || fin.eof()){
					if(fin.eof()){
						cout << "fewer than 125 blocks" << endl;
					}
					else{
						cout << "not a 1 or 0" << endl;
					}
					return false;
				}
			}
		}
	}
	for(int i = 0; i < 5; i++){
		for(int j = 0; j < 5; j++){
			for(int k = 0; k < 5; k++){
				currentMaze[i][j][k] = tempMaze[i][j][k];
			}
		}
	}
	return true;
}

vector<string> solveMaze(){
	vector<string> path;
	
	
	/* 
	*	start at (0,0,0), check each of the adjacent blocks to see if 
	*	they contain a 1. If none of them do, change the number at that 
	* spot to the "visited" number and return to the previous spot. Then 
	*/
	
}


