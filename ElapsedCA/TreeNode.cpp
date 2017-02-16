#include "BinaryTree.h"
#include "TreeNode.h"
#include <iostream>
using namespace std;

TreeNode::TreeNode() {

}

TreeNode::TreeNode(City cityIn) {
	city = cityIn;
}

bool TreeNode::isLeaf() {
	if (leftChild == NULL && rightChild == NULL)
		return true;
	else
		return false;
}