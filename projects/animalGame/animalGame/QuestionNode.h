#pragma once


#include <string>
using namespace std;

class QuestionNode
{
private:
	string _value;
	bool isLeaf = false;
	QuestionNode* _left = nullptr;
	QuestionNode* _right = nullptr;
public:

	//constructor
	QuestionNode(string value)
	{
		_value = value;
	}

	//empty constructor
	QuestionNode()
	{
		//no clue what _value will be
	}

	void setLeaf(bool checkLeaf) {
		isLeaf = checkLeaf;
	}

	bool getLeaf() {
		return isLeaf;
	}

	QuestionNode* getLeft()
	{
		return _left;
	}

	void setLeft(QuestionNode* left)
	{
		_left = left;
	}

	QuestionNode* getRight()
	{
		return _right;
	}

	void setRight(QuestionNode* right)
	{
		_right = right;
	}

	string getValue()
	{
		return _value;
	}

	void setValue(string value)
	{
		_value = value;
	}

	virtual bool isLeafNode(QuestionNode* nodeCheck = nullptr) {

		if (nodeCheck->getValue()[0] == '*') {
			return true;
		}
		else if (nodeCheck == nullptr) {
			return false;
		}
		//if (_root->getLeft() == nullptr && _root->getRight() == nullptr) {
			//return true;
		//}


		return false;
	}

};
