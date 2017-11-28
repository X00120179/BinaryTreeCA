// Lee Healy X00120179
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
		cout << "Binary Tree is empty!" << endl; // Else tree is empty.
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
		if (node->city == cityIn) { // If current node's city is equal to the city we searched for.
			cout << "Found city: " << cityIn.getName() << ": " << cityIn.getLatitude() << "* N " << cityIn.getLongitude() << "* W in the tree!" << endl;
		}
		else {
			if (node->city > cityIn && node->leftChild != NULL) { // If city is less than root/current node check left subtree (if it has a left side.)
				search(cityIn, node->leftChild); // Recursively call search for the left side.
			}
			else if (node->city < cityIn && node->rightChild != NULL) { // If city is greater than root/current node check right subtree (if it has a right side.)
				search(cityIn, node->rightChild); // Recursively call search for the right side.
			}
		}
	}
}



// Search for a city via its name.
void BinaryTree::searchName(string cityNameIn) {
	searchName(cityNameIn, root);
}

void BinaryTree::searchName(string cityNameIn, TreeNode *node) {
	if (node == NULL) { // Nothing in the tree to find.
		cout << "City not found..." << endl;
	}
	else {
		if (node->city.getName() == cityNameIn) { // If current node's city name is equal to the city name we searched for.
			cout << "Matched city with the name: " << cityNameIn << " with: "<< node->city.getName() << ": " << node->city.getLatitude() << "* N " << node->city.getLongitude() << "* W in the tree!" << endl;
		}
		else {
			if (cityNameIn < node->city.getName() && node->leftChild != NULL) { // If city name is less than the root/current nodes name check left subtree (if it has a left side.)
				searchName(cityNameIn, node->leftChild); // Recursively call search for the left side.
			}
			else if (cityNameIn > node->city.getName() && node->rightChild != NULL) { // If city name is greater than the root/current nodes name check right subtree (if it has a right side.)
				searchName(cityNameIn, node->rightChild); // Recursively call search for the right side.
			}
		}
	}
}



// Search for a city via its co-ordinates.
void BinaryTree::searchGPS(double firstGPS, double secondGPS) {
	searchGPS(firstGPS, secondGPS, root);
}



// Can't say if greater go right or if less then go left so we must search every node regardless instead.
void BinaryTree::searchGPS(double firstGPS, double secondGPS, TreeNode *node) {
	if (node != NULL) {
		// If the lat and long match, we've completed the search.
		if (node->city.getLatitude() == firstGPS && node->city.getLongitude() == secondGPS) {
			cout << "Matched city with co-ordinates: " << firstGPS << "* N " << secondGPS << "*W with: " << node->city.getName() << ": " << node->city.getLatitude() << "*N " << node->city.getLongitude() << "* W in the tree!" << endl;
		}
		else {
			searchGPS(firstGPS, secondGPS, node->leftChild); // Else search left side of tree for match.
			searchGPS(firstGPS, secondGPS, node->rightChild); // Else search right side of tree for match.
		}
	}

}



/*****************************************************************************************************
*    The following code has been extracted and changed to fit my project and used from the following:
*
*	 Title: <Binary Search Trees - Remove Node Function - C++>
*    Author: <Paul Programming>
*    Date: <23/02/17>
*	 Type: <Source Code>
*    Availability: <https://www.youtube.com/watch?v=ROtgyI64kGw>
*
******************************************************************************************************/

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
			cout << "The root node with " << rootKey.getName() << " was deleted." << " The new root contains the city: " << root->city << endl;
		}
		// Only has a left child.
		else if (root->leftChild != NULL && root->rightChild == NULL) {
			root = root->leftChild; // Pointing current root to left side.
			delPtr->leftChild = NULL; // 
			delete delPtr;
			cout << "The root node with " << rootKey.getName() << " was deleted." << " The new root contains the city: " << root->city << endl;
		}

		// Case 2 - Root node has 2 children.
		else {
			smallestInRightSubtree = findSmallest(root->rightChild); // Starts the findSmallest() function in the right subtree by passing in root->right as the starting node.
			removeCity(smallestInRightSubtree, root); 
			root->city = smallestInRightSubtree; // Root node is now the smallest node from the right side.
			// ^^ This keeps the greater/less than tree structure intact.
			cout << "The root: " << rootKey.getName() << " was overwritten with the city: " << root->city << endl;
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
			cout << "The node containing the city: " << matchKey.getName() << " was removed.\n" << endl;
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
			cout << "The node containing city: " << matchKey.getName() << " was removed.\n" << endl;
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
			cout << "The node containing city: " << matchKey.getName() << " was removed.\n" << endl;
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
1.) Pass in a city c1 and the limit of which you want to return cities within that limit.
2.) Calculate distance between c1 and first node.
3.) Put the answer(distance) and the nodes name into priority_queue< pair<string cityName, double distance>>.
4.) Move onto next node and do the exact same. (inorder traversal compare from left -> right.)
5.) When all nodes have been visited stop.
6.) Print out the cities in the priority_queue.
7.) We want it display all the nodes from shortest distance to c1 to furthest within the limit.
8.) Ex. C1 Dublin: { N1 Kildare 20Km, N2 Cork 387Km, N3 Los Angeles 7987Km}
*/
void BinaryTree::compareCities(City& cityIn, double limit) {
	compareCities(cityIn, limit, root);
}



void BinaryTree::compareCities(City& cityIn, double limit, TreeNode *node) {
	priority_queue<pair<string, double>, vector<pair<string, double>>, DoublePriority> distances; // Create queue.
	addToQueue(cityIn, node, distances); // Call recursive function that adds all the cities to the queue.

	// Display queue now.
	cout << "Cities closest to " << cityIn.getName() << " within " << limit << " kilometres is: " << endl;
	while (!distances.empty() && distances.top().second <= limit) { // While not empty and less than or equal to the distance limit.
		cout << "\t" << (distances.top()).first << ":\t" << (distances.top()).second << "Km" << endl;
		distances.pop(); // Pop current city off the queue to get to the next city.
	}
}



/*
1.) Takes in a city, a comparing city node, and queue< pair<string double>>.
2.) In order traversal of the tree it calls the calcDistance() function.
3.) calcDistance() function creates and returns pair<string double>.
4.) This pair<string double> is added/pushed to the queue of type priority_queue< pair <string, double>>.
5.) Does this with every node in the tree in order.
*/
void BinaryTree::addToQueue(City& cityIn, TreeNode *node, priority_queue<pair<string, double>, vector<pair<string, double>>, DoublePriority>& distances) {
	if (node != NULL) {
		if (calcDistance(cityIn, node).second != 0) { // Originally printed out the comparing city with itself (e.g. compared Dublin with Dublin) with the distance of 0 - This eliminates that.
			distances.push(calcDistance(cityIn, node)); // Pushing pair onto queue.
		}
		//cout << "Added " << node->city.getName() << " to queue." << endl; // Print out for testing to see what was added to the queue.

		if (node->leftChild != NULL) { // If city is less than root/current node check left subtree (if it has a left side.)
			addToQueue(cityIn, node->leftChild, distances); // Recursively call addToQueue down left side.
		}

		if (node->rightChild != NULL) { // If city is greater than root/current node check right subtree (if it has a right side.)
			addToQueue(cityIn, node->rightChild, distances); // Recursively call addToQueue down right side.
		}
	}
}



/*
1.) Compares distance between city and a node
2.) Returns type pair<> of nodes city name and distance between the node and the city its being compared.
3.) Called by make queue function.
4.) Queue adds in all the pairs.
*/
pair<string, double> BinaryTree::calcDistance(City& cityIn, TreeNode *node) {
	double long2 = cityIn.getLongitude();
	double long1 = node->city.getLongitude();
	double lat2 = cityIn.getLatitude();
	double lat1 = node->city.getLatitude();

	double distance = distanceEarth(lat1, long1, lat2, long2);

	pair<string, double> pair;

	pair.first = node->city.getName();
	pair.second = distance;

	return pair;
}



// Public maxHeight() function.
int BinaryTree::maxHeight() {
		return (maxHeight(root) - 1); // -1 as private function returns the number of nodes and not the paths inbetween them, this corrects it.
}



// Return the number of nodes along the longest path from
// the root node down to the deepest leaf node.
// Only returns the number of nodes and not the paths in between them.
int BinaryTree::maxHeight(TreeNode* node) {
	if (node == NULL) { 
		return 0; // if node is null it has no height.
	}
	else {
		int leftHeight = maxHeight(node->leftChild); // Go down the left side of the tree, count the nodes, store in leftHeight.
		int rightHeight = maxHeight(node->rightChild); // Go down the right side of the tree, count the nodes, store in rightHeight.

		// We want to return the larger one.
		if (leftHeight > rightHeight)
			return(leftHeight + 1); // +1 here as the function will not increment otherwise and the whole function would be pointless then.
		else 
			return(rightHeight + 1); // +1 here also for incrementing number of nodes on the right side.
	}
}
