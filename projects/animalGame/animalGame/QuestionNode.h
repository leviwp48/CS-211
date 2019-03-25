#pragma once


#include <string>
using namespace std;

class QuestionNode
{
private:
	string _value;
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
};
