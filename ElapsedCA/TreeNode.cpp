// Lee Healy X00120179
#include "BinaryTree.h"
#include "TreeNode.h"
#include <iostream>
using namespace std;



// Default Constructor.
TreeNode::TreeNode() {

}



// Constructor
TreeNode::TreeNode(City cityIn) {
	city = cityIn;
}



// If both chrildren are NULL, node is a leaf.
bool TreeNode::isLeaf() {

	if (leftChild == NULL && rightChild == NULL) {
		return true;
	}
	else
		return false;
}

