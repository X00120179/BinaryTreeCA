// Lee Healy X00120179
#pragma once
#include "CalcDistance.h"
#include "TreeNode.h"
#include "City.h"
#include <queue>


/***************************************************************************************
*    The following code has been extracted, slightly changed and used from the following:
*
*	 Title: <Operator overload or comparison function in C++ priority queue>
*    Author: <Useless>
*    Date: <20/03/17>
*	 Type: <Source Code>
*    Availability: <http://stackoverflow.com/questions/13790276/operator-overload-or-comparison-function-in-c-priority-queue>
*
***************************************************************************************/

// Used to override the comparison method in a priority_queue.
struct DoublePriority
{
	bool operator() (const pair<string, double> &lhs, const pair<string, double> &rhs) const {
		if (lhs.second > rhs.second) {
			return true;
		}
		else
		{
			return false;
		}
	}
};

class BinaryTree {
public:
	BinaryTree();
	void preOrderTraversal();
	void insert(City& cityIn);
	void search(City& cityIn);
	void searchName(string cityNameIn);
	void searchGPS(double firstGPS, double secondGPS);
	City findSmallest(); // Finds smallest node.(city)
	void removeCity(City& cityIn);
	void compareCities(City& cityIn, double limit);
	int maxHeight();


private:
	void preOrderTraversal(TreeNode *node, string indent);
	void insert(City& cityIn, TreeNode *node);
	void search(City& cityIn, TreeNode *node);
	void searchName(string cityNameIn, TreeNode *node);
	void searchGPS(double firstGPS, double secondGPS, TreeNode *node);
	int maxHeight(TreeNode *node);


	// Remove functions.
	City findSmallest(TreeNode *node); // Find smallest node(City) in the right subtree.
	void removeCity(City& cityIn, TreeNode *node);
	void removeRootMatch(); // Removes the root node if it matches the one to be deleted.
	void removeMatch(TreeNode *node, TreeNode *match, bool left); // Removes the node (that isn't the root) if it matches the one to be deleted.


	// Compare distance functions.
	//void displayQueue(priority_queue<pair<string, double>> distances);
	void compareCities(City& c1, double limit, TreeNode *node); // Calls addToQueue() and then displays the queue that was created.
	void addToQueue(City& c1, TreeNode *node, priority_queue<pair<string, double>, vector<pair<string, double>>, DoublePriority>& distances); // Calls calcDistance() which returns a pair and then adds the pair to priority_queue recursively.
	pair<string, double> calcDistance(City& c1, TreeNode *node); // Calculates distance between nodeCity and City and returns a pair.

	TreeNode *root;
};
