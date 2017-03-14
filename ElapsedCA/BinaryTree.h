#pragma once
#include "CalcDistance.h"
#include "TreeNode.h"
#include "City.h"
#include <queue>


class BinaryTree {
public:
	BinaryTree();
	// Methods to maintain a tree.
	void preOrderTraversal();
	void insert(City& cityIn);
	void search(City& cityIn);
	City findSmallest(); // Finds smallest node.(city)
	void removeCity(City& cityIn);
	void compareCities(City& cityIn);

	void destroyTree();
	int countChildren();

private:
	void preOrderTraversal(TreeNode *node, string indent);
	void insert(City& cityIn, TreeNode *node);
	void search(City& cityIn, TreeNode *node);

	// Remove functions.
	City findSmallest(TreeNode *node); // Find smallest node(City) in the right subtree.
	void removeCity(City& cityIn, TreeNode *node);
	void removeRootMatch(); // Removes the root node if it matches the one to be deleted.
	void removeMatch(TreeNode *node, TreeNode *match, bool left); // Removes the node (that isn't the root) if it matches the one to be deleted.

	// Compare distance functions.
	//void displayQueue(priority_queue<pair<string, double>> distances);
	void compareCities(City& c1, TreeNode *node); // Calls addToQueue() and then displays the queue that was created.
	void addToQueue(City& c1, TreeNode *node, priority_queue<pair<string, double>> distances); // Calls calcDistance() which returns a pair and then adds the pair to priority_queue recursively.
	pair<string, double> calcDistance(City& c1, TreeNode *node); // Calculates distance between nodeCity and City and returns a pair.

	// Other testing functions.
	void destroyTree(TreeNode *node);
	int countChildren(TreeNode* node);
	TreeNode *root;
};

