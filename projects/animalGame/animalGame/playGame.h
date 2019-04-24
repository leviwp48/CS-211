#pragma once
#ifndef PLAYGAME_H
#define PLAYGAME_H

#include <string>
#include <iostream>
#include <fstream>
#include "Tree.h"
#include "QuestionNode.h"

using namespace std;

void playGame(Tree gameTree, string fileName) {

	string response, replay;
	bool isPlaying = true;

	while (isPlaying) {
		// if we are at a leaf node
		if (gameTree.getValue()[0] == '*') {
			cout << "Is it a " << gameTree.getValue() << " (yes/no): ";
			cin >> response;
			if (response == "yes") {
				cout << "You Win!";
				cout << endl << "Would you like to play again? (yes/no): ";
				cin >> replay;
				if (replay == "yes") {
					gameTree.setCurrent(gameTree.getRoot());
					gameTree.saveTree(fileName);
					playGame(gameTree, fileName);
				}
				else if (replay == "no") {
					gameTree.saveTree(fileName);
					isPlaying = false;
					return;
				}
			}
			else if (response == "no") {
				string animal, question, answer;
				cout << "\nDarn, I got it wrong.  What is the correct answer: ";
				cin >> animal;
				animal = "*" + animal;
				cout << "\nWhat is a yes/no question that I can use to differentiate between a " << gameTree.getValue() << " a " << answer << ": ";
				cin.ignore();
				getline(cin, question);
				cout << "\nIs the answer to this question yes or no?: ";
				cin >> answer;

				// then take these results and put them into a tree;
				string oldAnimal = gameTree.getValue();
				gameTree.setCurrent(gameTree.getRoot());
				gameTree.addElement(fileName, animal, question, answer, oldAnimal);
				Tree newGameTree;
				newGameTree.buildTree(fileName);
				
				cout << endl << "Would you like to play again? (yes/no): ";
				cin >> replay;
				cout << endl;

				if (replay == "yes") {
					playGame(newGameTree, fileName);
				}
				else if (replay == "no") {
					isPlaying = false;
					return;
				}
				return;
			}
		}
		else {
			cout << gameTree.getValue() << " (yes/no): ";
			cin >> response;
			gameTree.nextElement(response);
		}
	}
}


#endif
