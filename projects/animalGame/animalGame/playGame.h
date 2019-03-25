#pragma once
#ifndef PLAYGAME_H
#define PLAYGAME_H

#include <string>
#include <iostream>
#include <fstream>
#include "Tree.h"
#include "QuestionNode.h"

using namespace std;

void playGame(Tree gameTree) {

	string response;
	cout << "Is it a dog? (yes/no): ";
	cin >> response;

	if (response == "yes" && gameTree.isLeafNode) {
		cout << "You Win!";
		return;
	}
	else if (response == "no" && gameTree.isLeafNode) {
		string animal, question, answer;
		cout << "Darn, I got it wrong.  What is the correct answer: ";
		cin >> animal;
		cout << "What is a yes/no question that I can use to differentiate between a " << gameTree.getValue() <<" a " << answer << ": ";
		cin >> question;
		cout << "Is the answer to this question yes or no?: ";
		cin >> answer;

		// then take these results and put them into a tree;
		return;
	}
	else {
		gameTree.nextElement;
	}
	

	
	
}

#endif
