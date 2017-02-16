#include "BinaryTree.h"
#include "TreeNode.h"
#include <iostream>
#include <vector>
using namespace std;

BinaryTree::BinaryTree() : root(NULL) {

}

// Public version of the destroy tree function.
void BinaryTree::preOrderTraversal() {
	preOrderTraversal(root);
}

// Private version of the destroy tree function.
void BinaryTree::preOrderTraversal(TreeNode *node) {
	if (node != NULL) { // If the tree is not empty.
		// 'visit' the subtree root, then... print or add or subtract etc..
		cout << node->city.getName() << " ";
		cout << node->city.getLatitude() << "* N";
		cout << node->city.getLongitude() << "* W" << endl;
		cout << "\t\t<---  "; preOrderTraversal(node->leftChild);
		cout << "\t\t--->  "; preOrderTraversal(node->rightChild); 
	}

	else if (node == NULL) {
		cout << "";
		cout << "null" << endl;
	}

	else {
		cout << "Binary Tree does not exist!" << endl;
	}
}


/***************************************************************************************
*    The following code has been extracted and used from the following:
*
*	 Title: <Binary Trees in C++: Part 1>
*    Author: <Alex Allain>
*    Date: <15/02/17>
*    Code version: <1.0>
*	 Type: <Source Code>
*    Availability: <http://www.cprogramming.com/tutorial/lesson18.html>
*
***************************************************************************************/


/*	Public version of the insert function.

1). Takes care of the case where the root has not been initialised
by allocating the memory for it.
2). Sets the city of the node to the value (city) to be inserted.
3).	Sets both child nodes of the root to NULL for future use.
4). If the root node already exists, insert is called with the root node
	as the initial node of the function, and the recursive insert takes over. */
void BinaryTree::insert(City cityIn) {
	if (root != NULL) {
		insert(cityIn, root);
	}
	else {
		root = new TreeNode;
		root->city = cityIn;
		root->leftChild = NULL;
		root->rightChild = NULL;
	}
}


// Private version of the insert function.
void BinaryTree::insert(City cityIn, TreeNode *node) {
	// If city to be insterted is less than root
	// Insert the city to the left of the root.
	if (cityIn < node->city) {
		// Checking if left side is NULL.
		// If NOT NULL then insert city into the node on the left side.
		if (node->leftChild != NULL) {
			insert(cityIn, node->leftChild);
		}
		// Else, IF IS NULL then create a left side node.
		// Insert the city into said node.
		// Give said node left and right children.
		else {
			node->leftChild = new TreeNode;
			node->leftChild->city = cityIn;
			node->leftChild->leftChild = NULL; // Sets the left child of the child node to NULL.
			node->leftChild->rightChild = NULL; // Sets the right child of the child node to NULL.
		}
	}
	// If city to be insterted is greater than root
	// Insert the city to the right of the root.
	else if (cityIn >= node->city) {
		// Checking if left side is NULL.
		// If NOT NULL the insert city into the node on the left side.
		if (node->rightChild != NULL) {
			insert(cityIn, node->rightChild);
		}
		// Else, IF IS NULL then create a left side node.
		// Insert the city into said node.
		// Give said node left and right children.
		else {
			node->rightChild = new TreeNode;
			node->rightChild->city = cityIn;
			node->rightChild->leftChild = NULL; // Sets the left child of the child node to NULL.
			node->rightChild->rightChild = NULL; // Sets the right child of the child node to NULL.
		}
	}
}


// Public version of the destroy tree function.
void BinaryTree::destroyTree() {
	destroyTree(root);
}

// Private version of the destory tree function.
void BinaryTree::destroyTree(TreeNode *node) {
	if (node != NULL) {
		// Point the node to both sides of the root.
		destroyTree(node->leftChild);
		destroyTree(node->rightChild);
		// Node now points at both sides of the root node.
		// Deleting the root node will then delete everything as it is hierarchical
		delete node;
	}
}
