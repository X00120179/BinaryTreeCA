#pragma once
#include "TreeNode.h"
#include "City.h"

class BinaryTree {
public:
	BinaryTree();
	// Methods to maintain a tree.
	void preOrderTraversal();
	void insert(City& cityIn);
	void search(City& cityIn);
	City findSmallest(); // Finds smallest node.(city)
	void removeCity(City& cityIn);

	void destroyTree();
	int countChildren();
private:
	// This will be used internally by the traversal above.
	void preOrderTraversal(TreeNode *node, string indent);
	void insert(City& cityIn, TreeNode *node);
	void search(City& cityIn, TreeNode *node);
	City findSmallest(TreeNode *node); // Find smallest node(City) in the right subtree.
	void removeCity(City& cityIn, TreeNode *node);
	void removeRootMatch(); // Removes the root node if it matches the one to be deleted.
	
	// Node we want to remove is *match.
	// Parent of the *match node is *node
	// If bool left == true then the *match node is the left child of the parent node
	// if bool left == false then it is the right child.
	void removeMatch(TreeNode *node, TreeNode *match, bool left); // Removes the node (that isn't the root) if it matches the one to be deleted.

	void destroyTree(TreeNode *node);
	int countChildren(TreeNode* node);
	TreeNode *root;
};

