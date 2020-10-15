#pragma once
#include "RBTreeNode.h"

class RBTree {
public:
	RBTree(RBTreeNode* r): root(r){}
	RBTree(int k) : root(&RBTreeNode(k)){}
	RBTreeNode* root;

	// Two balancing operations
	void rotateRedEdge(RBTreeNode*);
	void recolor(RBTreeNode*);

	// Basic functions of the tree
	bool insert(int);
	RBTreeNode* findKthMIN(int);
	bool erase(int);

	// Support function of the tree
	RBTreeNode* moveRedLeft(RBTreeNode*);
	RBTreeNode* moveRedRight(RBTreeNode*);
	RBTreeNode* eraseMIN(RBTreeNode*);
	RBTreeNode* eraseMAX(RBTreeNode*);
};