// Lee Healy X00120179
#pragma once
#include "City.h"
#include <deque>

class TreeNode {
	friend class BinaryTree;
public:
	TreeNode();
	TreeNode(City cityIn);
	bool isLeaf();
private:
	TreeNode *leftChild;
	City city;
	TreeNode *rightChild;
};