#pragma once
#include "TreeNode.h"
#include "City.h"

class BinaryTree {
public:
	BinaryTree();
	// Methods to maintain a tree.
	void preOrderTraversal();
	void insert(City cityIn);
	void destroyTree();
private:
	// This will be used internally by the traversal above.
	void preOrderTraversal(TreeNode *node);
	void insert(City cityIn, TreeNode *node);
	void destroyTree(TreeNode *node);
	TreeNode *root;
};

