#include "Tree.h"
#include "playGame.h"
#include <iostream>
#include <string>
#include <fstream>
#include <filesystem>

namespace fs = std::filesystem;
using namespace std;


/*
	Overall this program works. But will sometimes skip some cin's
*/
int main(void) {
	
	string toLoad, fileToSave;
	cout << "***Animal Guessing Game***" << endl;
	cout << "========================================================================================\n";
	cout << "Rules: Think of an Animaland this game will guess it!If it doesn't, teach it and try again!";
	cout << "\n========================================================================================\n" << endl;
	cout << "Load file? (yes/no): ";
	cin >> toLoad;

	if (toLoad == "yes") {
		cout << endl;
		string path = "E:\\Users\\Levi Pole\\Documents\\Projects\\C++\\CS-211\\projects\\animalGame\\gameFiles";
		for (const auto& entry : fs::directory_iterator(path)) {
			string name = entry.path().u8string();
			name = name.substr(name.find_last_of("\\")+1, name.length());
			cout << name<< endl;
		}
		string loadFile;
		cout << "\nName of file to load";
		cin >> loadFile;
		string saveFile;
		cout << "File name to save to ";
		cin >> saveFile;
		Tree gameTree;
		gameTree.buildTree(loadFile);
		playGame(gameTree, saveFile);
	}
	else if (toLoad == "no") {
		string saveFile;
		cout << "File name to save to (Example:: game1.txt): ";
		cin >> saveFile;
		Tree gameTree;
		gameTree.buildTree();
		playGame(gameTree, saveFile);
	}
	else {
		cout << "Please re-enter your answer";
	}

	
	return 0;

}