#pragma once


#include "QuestionNode.h"
#include <string>
#include <iostream>
#include <fstream>

using namespace std;
//TODO: need to fix making the tree. It keeps adding tot he right of centipede.
class Tree {

private:
	QuestionNode* _current = nullptr;
	QuestionNode* _root = nullptr;
	string treeName;

protected: 
	
	// In order traversal of adding nodes
	virtual QuestionNode* treeAddNode(QuestionNode* node, string value)
	{
		// so the nodes are going to return at least once to create themselves. 
		// I need to make it so it always checks to see where it is.

		if (node == nullptr)
		{
			node = new QuestionNode{ value };

			if (node->getValue()[0] == '*') {
				node->setLeaf(true);
			}
			return node;
		}
		
		// after node is created and we go back up a level
		// this will move us to the left as long as the node isn't full
		if (node->getLeft() != nullptr) {
			
			if (node->getRight() != nullptr && (isFull(node->getLeft()) && isFull(node->getRight()))) {
				node->setLeaf(true);
				return node;
			}
			else if (!isFull(node->getLeft())) {
				node->setLeft(treeAddNode(node->getLeft(), value));
			}
			else {
				node->setRight(treeAddNode(node->getRight(), value));
			}
		}
		else {
			node->setLeft(treeAddNode(node->getLeft(), value));
		}

		//before we return each node check if their fullness has changed
		node->setLeaf(evaluateFullness(node));
		//to maintian recursive correctness, always return a BinaryNode<T>*
		return node;
		
	}
	
	bool evaluateFullness(QuestionNode* node) {
		if (node == nullptr || node->getValue()[0] == '*') {
			return true;
		}
		else if (node->getLeft() != nullptr && node->getRight() == nullptr) {
			return false;
		}
		else if (node->getLeft() == nullptr && node->getRight() != nullptr) {
			return false;
		}
		else if (node->getLeft() == nullptr && node->getRight() == nullptr && node->getValue()[0] != '*'){
			return false;
		}

		return (evaluateFullness(node->getLeft()) && evaluateFullness(node->getRight()));
	}

	virtual QuestionNode* treeAddSet(QuestionNode* node, string newAnimal, string description = "", string answer = "")
	{
		if (answer == "yes") {
		}
		return node;
	}

	virtual QuestionNode* buildTreeFromFile(QuestionNode* root, string value) {
		if (root == nullptr) {
			root = new QuestionNode{ value };
			return root;
		}

		root->setLeft(buildTreeFromFile(root->getLeft(), value));
		root->setRight(buildTreeFromFile(root->getRight(), value));

		return root;
	}

public: 

	virtual QuestionNode* getRoot() {
		return _root;
	}
	
	virtual QuestionNode* getCurrent() {
		return _current;
	}

	virtual void setCurrent(QuestionNode* root) {
		_current = root;
	}

	virtual string getValue() {
		return _current->getValue();
	}

	virtual void addNode(string value) {
			_root = treeAddNode(_root, value);	
			_current = treeAddNode(_current, value);
		
	}

	virtual void addElement(string fileName, string newAnimal, string description, string answer, string oldAnimal)
	{
		saveTree(fileName, answer, oldAnimal, newAnimal, description);

	}

	virtual void nextElement(string answer) {
		if (answer == "yes") {
			_current = _current->getRight();
		}
		else if (answer == "no") {
			_current = _current->getLeft();
		}
	}
	
	bool isFull(QuestionNode* node) {
		if (node->getLeaf()) {
			return true;
		}
		return false;
	}

	virtual void buildTree(string buildFile = "") {

		//Look at this later
		if (buildFile == "") {
			addNode("Does it walk on 4 legs?");
			addNode("*bird");
			addNode("*dog");
		}
		else {	
			buildFile = "E:\\Users\\Levi Pole\\Documents\\Projects\\C++\\CS-211\\projects\\animalGame\\gameFiles\\" + buildFile;
			ifstream treeFile{ buildFile };
			if (treeFile.is_open()) {
				while (treeFile.good()) {
					string lineFromFile;
					getline(treeFile, lineFromFile);
					addNode(lineFromFile);
				}
			}
			treeFile.close();
		}
	}

	void preorder(QuestionNode* root, ofstream& file, string answer = "", string oldAnimal = "", string newAnimal = "", string description = "") {
		if (root != nullptr) {
			if (root->getValue() == oldAnimal) {
				if (answer == "yes") {
					file << description << endl << oldAnimal << endl << newAnimal << endl;
				}
				else if (answer == "no") {
					file << description << endl << newAnimal << endl << oldAnimal << endl;
				}

			}
			else {
				file << root->getValue() << endl;
			}
			preorder(root->getLeft(), file, answer, oldAnimal, newAnimal, description);
			preorder(root->getRight(), file, answer, oldAnimal, newAnimal, description);
		}
	}
	virtual void saveTree(string fileName, string answer = "", string oldAnimal = "", string newAnimal = "", string description = "") {
		ofstream myFile;
		myFile.open(fileName);
		preorder(_root, myFile, answer, oldAnimal, newAnimal, description);
		myFile.close();
	}

	virtual bool isLeafNode(QuestionNode* nodeCheck) {
		return nodeCheck->getLeaf();
	}
};

