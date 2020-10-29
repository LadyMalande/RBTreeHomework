#pragma once

#include <limits>
class RBTreeNode;
class RBTree {
public:
	// Constructors
	RBTree();
	// Basic functions of the tree

	int findKthMIN(int);
	bool erase(int);
	bool find(int);
	RBTreeNode* getRoot();
	
	void insertRoot(RBTreeNode*);
	int size();

private:
	RBTreeNode* root;

	// Two balancing operations
	void rotateRedEdge(RBTreeNode*);

	// Support function of the tree
	RBTreeNode* moveRedLeft(RBTreeNode*);
	RBTreeNode* moveRedRight(RBTreeNode*);
	RBTreeNode* eraseMIN(RBTreeNode*);
	RBTreeNode* eraseMAX(RBTreeNode*);

	// setRoot is only for balancing operations, its not visible to other classes
	void setRoot(RBTreeNode* newroot);
	
};