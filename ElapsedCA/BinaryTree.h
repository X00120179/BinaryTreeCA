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
	int countChildren();
private:
	// This will be used internally by the traversal above.
	void preOrderTraversal(TreeNode *node, string indent);
	void insert(City cityIn, TreeNode *node);
	void destroyTree(TreeNode *node);
	int countChildren(TreeNode* node);
	TreeNode *root;
};

