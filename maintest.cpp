#include <iostream>
#include <fstream>
#include "Pathfinder.h"

using namespace std;

int main(){
	ifstream fin;
	ofstream fout;
	const string FILE_NAME = "Mazes/Solvable1.txt";
	Pathfinder PF;

	fin.open("Mazes/Solvable1.txt");
	if(fin.is_open()){
		cout << "File opened" << endl;
	}
	PF.importMaze(FILE_NAME);

	cout << PF.toString() << endl;
	
	return 0;
}