#include "Tree.h"
#include "playGame.h"
#include <iostream>
#include <string>
#include <fstream>
using namespace std;

int main(void) {
	
	string toLoad, fileToSave;
	cout << "***Animal Guessing Game***" << endl;
	cout << "Load file? (yes/no): ";
	cin >> toLoad;

	if (toLoad == "yes") {

	}
	else if (toLoad == "no") {
		//cout << "Save results to: ";
		//cin >> fileToSave;
		Tree gameTree;
		gameTree.buildTree();
		playGame(gameTree);
	}
	else {
		cout << "Please re-enter your answer";
	}

	
	return 0;

}