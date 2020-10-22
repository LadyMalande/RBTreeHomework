#pragma once
#include "RBTreeNode.h"

class RBTree {
public:
	// Constructors
	RBTree(RBTreeNode* r): root(r){}
	RBTree(int k);
	RBTree();
	// Basic functions of the tree
	bool insert(int);
	RBTreeNode* findKthMIN(int);
	bool erase(int);
	RBTreeNode* find(int);
	RBTreeNode* getRoot();
	void setRoot(RBTreeNode*);
	int size();

private:
	RBTreeNode* root;

	// Two balancing operations
	void rotateRedEdge(RBTreeNode*);
	void recolor(RBTreeNode*);

	// Support function of the tree
	RBTreeNode* moveRedLeft(RBTreeNode*);
	RBTreeNode* moveRedRight(RBTreeNode*);
	RBTreeNode* eraseMIN(RBTreeNode*);
	RBTreeNode* eraseMAX(RBTreeNode*);
	RBTreeNode* uncle(RBTreeNode*);
	bool isRed(RBTreeNode*);
	int sizeSubtree(RBTreeNode*);
};