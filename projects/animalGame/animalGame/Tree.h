#pragma once


#include "QuestionNode.h"
#include <string>
#include <fstream>

using namespace std;

class Tree {

private:
	QuestionNode* _root = nullptr;
	string treeName;

protected: 
	
	virtual QuestionNode* treeAdd(QuestionNode* node, string value, string answer = "")
	{
		//null node indicates time to create a new item in our tree
		if (node == nullptr)
		{
			node = new QuestionNode{ value };
			return node;
		}

		if (answer == "yes")
		{
			node->setRight(treeAdd(node->getRight(), value));
		}
		else
		{
			node->setLeft(treeAdd(node->getLeft(), value));
		}

		//to maintian recursive correctness, always return a BinaryNode<T>*
		return node;
	}

public: 

	virtual QuestionNode* getRoot() {
		return _root;
	}
	
	virtual string getValue() {
		return _root->getValue();
	}

	virtual void addElement(string value,  string answer)
	{
		_root = treeAdd(_root, value, answer);
	}

	virtual void nextElement(string answer) {
		if (answer == "yes") {
			_root = _root->getRight();
		}
		else if (answer == "no") {
			_root = _root->getLeft();
		}
	}
	
	virtual void buildTree(string buildFile = "") {

		if (buildFile == "") {
			_root = new QuestionNode("*Dog?");
		}
		else {	
			ifstream treeFile{ buildFile };
			while (treeFile.is_open()) {
			}
		}
	}

	virtual bool isLeafNode() {
		if (_root->getLeft() == nullptr && _root->getRight() == nullptr) {
			return true;
		}
		return false;
	}
};

