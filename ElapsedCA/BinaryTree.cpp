#include "BinaryTree.h"
#include "TreeNode.h"
#include <iostream>
#include <vector>
using namespace std;

BinaryTree::BinaryTree() {
	root = NULL;
}




// Public version of the destroy tree function.
void BinaryTree::preOrderTraversal() {
	preOrderTraversal(root, "");
}

// Private version of the destroy tree function.
void BinaryTree::preOrderTraversal(TreeNode *node, string indent) {
	if (node != NULL) { // If the tree is not empty.
		// 'visit' the subtree root, then... print or add or subtract etc..
		cout << indent << "|____" << node->city;
		indent += "|\t"; // Adds a tab before city name to show tree structure in print. Also adds a line downwards showing left and right nodes alignment.
		
		if (node->leftChild != NULL) { // If left child is not equal to NULL call the function.
			preOrderTraversal(node->leftChild, indent);
		}
		else if (node->leftChild == NULL) { // If left child IS NULL print out null
			cout << indent << "|____Null" << endl;
		}

		if (node->rightChild != NULL) { // If right child is not equal to NULL call the function.
			preOrderTraversal(node->rightChild, indent);
		}
		else if (node->rightChild == NULL) { // If right child IS NULL print out null
			cout << indent << "|____Null" << endl;
		}
	}
	else {
		cout << "Binary Tree is empty!" << endl;
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
void BinaryTree::insert(City& cityIn) {
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
void BinaryTree::insert(City& cityIn, TreeNode *node) {
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





// SEARCH THE TREE FOR A NODE
void BinaryTree::search(City& cityIn) {
	 search(cityIn, root);
}

void BinaryTree::search(City& cityIn, TreeNode *node) {

	if (node == NULL) {
		cout << "City not found..." << endl;
		//return false; // No cities exist so return false.
	}
	else {
		if (node->city == cityIn) {
			cout << "Found city: " << cityIn << endl;
			//return true; // If city is same as the one in the root then city is found.
		}
		else {
			if (node->city < cityIn) {
				search(cityIn, node->rightChild); // Recursively call search for the right side.
			}
			else {
				search(cityIn, node->leftChild); // Recursively call search for the left side.
			}
		}
	}

}

// Remove function help from Youtube "Pauls Programming".
// https://www.youtube.com/watch?v=ROtgyI64kGw
// Accessed 23.02.17.


// Public findSmallest() function.
// Calls the private version of this function.
// Finds smallest node in the right subtree. (Used for removal of a node later.)
City BinaryTree::findSmallest() {
	return findSmallest(root); // Starts the private function at the root node.
}

// Private findSmallest() function.
// Used for removal of a node later.
City BinaryTree::findSmallest(TreeNode *node) {
	City temp("temp", 1.0, 2.0);
	if (root == NULL) { // Tree is empty
		cout << "The tree is empty" << endl;
		return temp;
	
	}
	// Else go down the left side because left side is ALWAYS smaller than the root hence, we won't need to look at the right side in this function.
	else { // Tree has nodes and is not empty.
		if (node->leftChild != NULL) { // Left side has nodes.
			return findSmallest(node->leftChild); // Recursive call.
		}
		else { // Else we've made it to the smallest node in the subtree, return it.
			return node->city; 
		}
	}
}




// public removeCity() function.
// Calls the private version of this function.
void BinaryTree::removeCity(City& city) {
	removeCity(city, root);
}

// private removeCity() function.
void BinaryTree::removeCity(City& cityIn, TreeNode *node) {
	if (root != NULL) { // Tree is not empty and contains nodes.
		if (node->city == cityIn) { // If the root matches the city we want to remove.
			removeRootMatch();
		} else {
			if (cityIn < node->city && node->leftChild != NULL) { // Checking left side of root.
				// Check the roots left side node value (city) for a match.
				if (node->leftChild->city == cityIn) {
					removeMatch(node, node->leftChild, true);
				}
				else {
					removeCity(cityIn, node->leftChild); // Else, Recursively check the next node to the left (Going left-wards down the tree).
				}
				}
			else if (cityIn >= node->city && node->rightChild != NULL) { // Checking right side of root.
				// Check the roots right side node value (city) for a match.
				if (node->rightChild->city == cityIn) {
					removeMatch(node, node->rightChild, false);
				}
				else {
					removeCity(cityIn, node->rightChild); // Else, Recursively check the next node to the right (Going rights-wards down the tree).
				}
				}
			else {
				cout << "The city " << cityIn << "was not found in the tree...\n" << endl;
			}
		}
	}
	else { // Tree is empty.
		cout << "The tree is empty...\n" << endl;
	}
}




// Function to delete the root of the tree and replace it with next value to the right.
void BinaryTree::removeRootMatch() {
	if (root != NULL) { // Tree is not empty and contains nodes.
		TreeNode *delPtr = root; // Temp ptr for swapping values in node before deletion.
		City rootKey = root->city;

		// Need a variable to replace the current root in the tree.
		// We replace current root with the smallest node in the right subtree of the root.
		// Left subtree will be left alone because of this right subtree change.
		City smallestInRightSubtree; 

		// Case 0 : Root node has 0 Children. (is a leaf node.)
		if (root->isLeaf()) {
			root = NULL;
			delete delPtr;
		}

		// Case 1 - Root node has only 1 child.
		// Only has a right child.
		else if (root->leftChild == NULL && root->rightChild != NULL) {
			root = root->rightChild; // Pointing current root to right side.
			delPtr->rightChild = NULL; // Disconnects old rood from the tree.
			delete delPtr; // Deletes the old root.
			cout << "The root node with " << rootKey << "was deleted." << " The new root contains the city: " << root->city << endl;
		}
		// Only has a left child.
		else if (root->leftChild != NULL && root->rightChild == NULL) {
			root = root->leftChild; // Pointing current root to left side.
			delPtr->leftChild = NULL; // 
			delete delPtr;
			cout << "The root node with " << rootKey << "was deleted." << " The new root contains the city: " << root->city << endl;
		}

		// Case 2 - Root node has 2 children.
		else {
			smallestInRightSubtree = findSmallest(root->rightChild); // Starts the findSmallest() function in the right subtree by passing in root->right as the starting node.
			removeCity(smallestInRightSubtree, root); 
			root->city = smallestInRightSubtree; // Root node is now the smallest node from the right side.
			// ^^ This keeps the greater/less than tree structure intact.
			cout << "The root: " << rootKey << "was overwritten with the city: " << root->city << endl;
		}
	}
	else { // Tree is empty
		cout << "Cannot remove root. The tree is empty\n" << endl;
	}
}


// Removes the node matching the node specified to be deleted.
void BinaryTree::removeMatch(TreeNode *node, TreeNode *match, bool left) {
	if (root != NULL) { // Tree is not empty.
		TreeNode *delPtr; // Temp ptr.
		City matchKey = match->city;
		City smallestInRightSubtree; // Explained in function above.

		// Case 0 - 0 Children. If the matching node we want to delete is a leaf node.
		if (match->isLeaf()) {
			delPtr = match;
			if (left == true) { // If node we want to delete is left or right child of its parent node.
				node->leftChild = NULL;
			}
			else {
				node->rightChild = NULL;
			}
			delete delPtr;
			cout << "The node containing the city: " << matchKey << "was removed.\n" << endl;
		}

		// Case 1 - Node we want to delete has 1 child.
		// and that 1 child is on the right side.
		else if (match->leftChild == NULL && match->rightChild != NULL) {
			if (left == true) { // If node we want to delete is left or right child of its parent node.
				node->leftChild = match->rightChild;
			}
			else {
				node->rightChild = match->rightChild;
			}
			match->rightChild = NULL;
			delPtr = match;
			delete delPtr;
			cout << "The node containing city: " << matchKey << "was removed.\n" << endl;
		}

		// If the node we want to delete has 1 child and it's on the left side.
		else if (match->leftChild != NULL && match->rightChild == NULL) {
			if (left == true) {
				node->leftChild = match->leftChild;
			}
			else {
				node->rightChild = match->leftChild;
			}
			match->leftChild = NULL;
			delPtr = match;
			delete delPtr;
			cout << "The node containing city: " << matchKey << "was removed.\n" << endl;
		}

		// Matching node has 2 children.
		// If thats the case we find the smallest node in matches right subtree.
		else {
			smallestInRightSubtree = findSmallest(match->rightChild);
			removeCity(smallestInRightSubtree, match); // Starts searching for smallest city at the match node we passed in.
			match->city = smallestInRightSubtree; // Match node is now the smallest value from the right subtree.
			// ^^ This keeps the greater/less than tree structure intact.

		}
	}
	else {
		cout << "Cannot remove match. The tree is empty...\n" << endl;
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




int BinaryTree::countChildren()
{
	return countChildren(root);
}

int BinaryTree::countChildren(TreeNode* node)
{
	if (node == NULL)
		return 0;
	return 1 + countChildren(node->leftChild) + countChildren(node->rightChild);

}
