#include "Pathfinder.h"

Pathfinder::Pathfinder(){
	srand(time(NULL));
	for(int i = 0; i < 5; i++){
		for(int j = 0; j < 5; j++){
			for(int k = 0; k < 5; k++){
				currentMaze[i][j][k] = 1;
			}
		}
	}
}

Pathfinder::~Pathfinder(){}

bool Pathfinder::FindMazePath(int tempMaze[5][5][5],int x,int y,int z){
	if(x < 0 || y < 0 || z < 0 || x >= 5 || y >= 5 || z >= 5){
		return false; //not in the maze
	}
	else if(tempMaze[x][y][z] != BACKGROUND){
		return false; //a wall or a dead end
	}
	else if(x == 5 - 1 && y == 5 - 1 && z == 5 - 1){
		tempMaze[x][y][z] = PATH;
		path.push_back( "(" + to_string(x) + "," + to_string(y) + "," + to_string(z) + ")" );
		return true;	//point is on path and is maze exit
	}
	else{
		tempMaze[x][y][z] = PATH;
		if(FindMazePath(tempMaze, x - 1, y, z) ||
				FindMazePath(tempMaze, x + 1, y, z) ||
				FindMazePath(tempMaze, x, y - 1, z) ||
				FindMazePath(tempMaze, x, y + 1, z) ||
				FindMazePath(tempMaze, x, y, z - 1) ||
				FindMazePath(tempMaze, x, y, z + 1) )  {
			path.push_back( "(" + to_string(x) + "," + to_string(y) + "," + to_string(z) + ")" );
			return true;
		}
		else{
			tempMaze[x][y][z] = TEMP;		//dead end
			return false;
		}
	}
}

string Pathfinder::toString() const{
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
	cout << "Importing Maze from " << file_name << endl;
	for(int i = 0; i < 5; i++){
		for(int j = 0; j < 5; j++){
			for(int k = 0; k < 5; k++){
				cout << "("<<i<<","<<j<<","<<k<<") = ";	//DEBUG
				fin >> tempMaze[i][j][k];
				cout << tempMaze[i][j][k] << endl;			//DEBUG
				if(tempMaze[i][j][k] != 1 && tempMaze[i][j][k] != 0 || fin.eof()){
					if(fin.eof() && i < 4){
						cout << "fewer than 125 blocks" << endl;
					}
					else if(tempMaze[i][j][k] != 1 && tempMaze[i][j][k] != 0){
						cout << "not a 1 or 0" << endl;
					}
					else{};
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

vector<string> Pathfinder::solveMaze(){
	FindMazePath(currentMaze, 0, 0, 0);
	
	return path;
}