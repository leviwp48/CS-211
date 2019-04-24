#include "Tree.h"
#include "playGame.h"
#include <iostream>
#include <string>
#include <fstream>
using namespace std;


/*
	Overall this program works. But will sometimes skip some cin's
*/
int main(void) {
	
	string toLoad, fileToSave;
	cout << "***Animal Guessing Game***" << endl;
	cout << "Load file? (yes/no): ";
	cin >> toLoad;

	if (toLoad == "yes") {
		string file;
		cout << "Name of file: ";
		cin >> file;
		string fileName;
		cout << "File name to save to (Example:: game1.txt): ";
		cin >> fileName;
		Tree gameTree;
		gameTree.buildTree(file);
		playGame(gameTree, fileName);
	}
	else if (toLoad == "no") {
		string fileName;
		cout << "File name to save to (Example:: game1.txt): ";
		cin >> fileName;
		Tree gameTree;
		gameTree.buildTree();
		playGame(gameTree, fileName);
	}
	else {
		cout << "Please re-enter your answer";
	}

	
	return 0;

}