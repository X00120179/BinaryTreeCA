#include "BinaryTree.h"
#include "TreeNode.h"
#include <iostream>
#include <vector>
#include <math.h>
#include <queue>
using namespace std;

// Constructor
BinaryTree::BinaryTree() {
	root = NULL;
}


// Public version of the destroy tree function.
void BinaryTree::preOrderTraversal() {
	preOrderTraversal(root, "");
}

// Private version of the destroy tree function.
// Pretty prints similar to the 'tree' command on command prompt.
// Visually see the structure of the Binary Search Tree this way.
void BinaryTree::preOrderTraversal(TreeNode *node, string indent) {
	if (node != NULL) { // If the tree is not empty.
		// 'visit' the subtree root, then... print or add or subtract etc..
		cout << indent << "|____" << node->city;
		indent += "|\t"; // Adds a tab before city name to show tree structure in print. Also adds a line downwards showing left and right nodes alignment.
		
		if (node->leftChild != NULL) { // If left child is not equal to NULL call the function.
			preOrderTraversal(node->leftChild, indent); // Recursive call.
		}
		else if (node->leftChild == NULL) { // If left child IS NULL print out NULL.
			cout << indent << "|____Null" << endl;
		}

		if (node->rightChild != NULL) { // If right child is not equal to NULL call the function.
			preOrderTraversal(node->rightChild, indent); // Recursive call.
		}
		else if (node->rightChild == NULL) { // If right child IS NULL print out NULL.
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
*	 Type: <Source Code>
*    Availability: <http://www.cprogramming.com/tutorial/lesson18.html>
*
***************************************************************************************/

//	Public version of the insert function.
void BinaryTree::insert(City& cityIn) {
	if (root != NULL) {
		// If the root node already exists, insert is called with the root node as the initial node of the function, and the recursive insert takes over.
		insert(cityIn, root); 
	}
	else {
		root = new TreeNode; // Takes care of the case where the root has not been initialised by allocating the memory space for it.
		root->city = cityIn; // Sets the city of the node to the value (city) to be inserted
		root->leftChild = NULL; // Set left child of root to NULL.
		root->rightChild = NULL; // Set right child of root to NULL.
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
	else if (cityIn > node->city) {
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



// Public search function.
// Calls private version.
void BinaryTree::search(City& cityIn) {
	 search(cityIn, root);
}


// Private search function.
// Search the tree to see if a node(city) exists.
void BinaryTree::search(City& cityIn, TreeNode *node) {
	if (node == NULL) { // Nothing in the tree to find.
		cout << "City not found..." << endl;
	}
	else {
		if (node->city == cityIn) { // If current node's city is equal to the city we want.
			cout << "Found city: " << cityIn << endl;
		}
		else {
			if (node->city < cityIn && node->leftChild != NULL) { // If city is less than root/current node check left subtree (if it has a left side.)
				search(cityIn, node->rightChild); // Recursively call search for the right side.
			}
			else if (node->city > cityIn && node->rightChild != NULL){ // If city is greater than root/current node check right subtree (if it has a right side.)
				search(cityIn, node->leftChild); // Recursively call search for the left side.
			}
		}
	}

}


/***************************************************************************************
*    The following code has been extracted and changed to fit my project and used from the following:
*
*	 Title: <Binary Search Trees - Remove Node Function - C++>
*    Author: <Paul Programming>
*    Date: <23/02/17>
*	 Type: <Source Code>
*    Availability: <https://www.youtube.com/watch?v=ROtgyI64kGw>
*
***************************************************************************************/

// Public findSmallest() function.
// Calls the private version of this function.
// Finds smallest node in the right subtree. (Used for removal of a node later.)
City BinaryTree::findSmallest() {
	return findSmallest(root); // Starts the private function at the root node.
}

// Private findSmallest() function.
// Used for removal of a node later.
City BinaryTree::findSmallest(TreeNode *node) {
	City temp("temp", 1.0, 2.0); // Needed to create this to return a value in this control statement.
	if (root == NULL) { // Tree is empty.
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



// Public removeCity() function.
// Calls the private version of this function.
void BinaryTree::removeCity(City& city) {
	removeCity(city, root);
}

// Private removeCity() function.
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
			else if (cityIn > node->city && node->rightChild != NULL) { // Checking right side of root.
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


// Function to delete the root of the tree and replace it with the smallest value from the right subtree.
 /*
  * Node we want to remove is *match.
  * Parent of the *match node is *node
  * If bool left == true then the *match node is the left child of the parent node
  * if bool left == false then it is the right child.
  */
void BinaryTree::removeRootMatch() {
	if (root != NULL) { // Tree is not empty and contains nodes.
		TreeNode *delPtr = root; // Temp pointer for swapping values in node before deletion.
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


/*
1.) Pass in a city c1.
2.) Calculate distance between c1 and first node.
3.) Put the answer(distance) and the nodes name into priority_queue< pair<string cityName, double distance>>.
4.) Move onto next node and do the exact same. (inorder traversal compare from left -> right.)
5.) When all nodes have been visited stop.
6.) Print out priority_queue.
7.) We want it display all the nodes from shortest distance to c1 to furthest.
8.) Ex. C1 Dublin: { N1 Kildare 20Km, N2 Cork 387Km, N3 Los Angeles 7987Km}
*/

void BinaryTree::compareCities(City& cityIn) {
	compareCities(cityIn, root);
}

void BinaryTree::compareCities(City& c1, TreeNode *node) {
	priority_queue<pair<string, double>> distances;

	addToQueue(c1, node, distances);

	/*while(!pq.empty()){
        int temp=pq.top();
        pq.pop();
        cout<<temp<<endl;
    }*/

	// Display queue now.
	while (!distances.empty()) {
		distances.pop();
	}
}


/*
1.) Takes in a city, a comparing city node, and queue< pair<string double>>.
2.) In order of the tree it calls the calcDistance() function.
3.) calcDistance() function creates and returns creates a pair<string double>.
4.) This pair<string double> is added/pushed to the queue of type pair.
5.) Does this with every node in the tree in order.
*/
void BinaryTree::addToQueue(City& c1, TreeNode *node, priority_queue<pair<string, double>> distances) {
	if (node != NULL) {
		// Traverses in order.
		addToQueue(c1, node, distances); // Recursive call.

		distances.push(calcDistance(c1, node));
		cout << "Added " << node->city.getName() << " to queue." << endl;

		addToQueue(c1, node, distances); // Recursive call.
	}
}


/*
1.) Compares distance between city and a node
2.) Returns type pair<> of nodes city name and distance between the node and the city its being compared.
3.) Called by make queue function.
4.) Queue adds in all the pairs.
*/
pair<string, double> BinaryTree::calcDistance(City& c1, TreeNode *node) {
	double long2 = c1.getLongitude();
	double long1 = node->city.getLongitude();
	double lat2 = c1.getLatitude();
	double lat1 = node->city.getLatitude();

	double distance = distanceEarth(lat1, long1, lat2, long2);

	pair<string, double> pair;

	pair.first = node->city.getName();
	pair.second = distance;

	return pair;
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
		// Deleting the r0oot node will then delete everything as it is hierarchical
		delete node;
	}
}

int BinaryTree::countChildren() {
	return countChildren(root);
}

int BinaryTree::countChildren(TreeNode* node) {
	if (node == NULL)
		return 0;
	return 1 + countChildren(node->leftChild) + countChildren(node->rightChild);

}
