#pragma once
#include <iostream>
#include "RBTree.h"
class RBTreeNode {
public:
	// Constructors	
	RBTreeNode(int k) : red(true), left(nullptr), right(nullptr), parent(nullptr), key(k), sizeOfLeftTree(0) { }
	bool insert(RBTree* tree);

	//size of left subtree strating from this node excluding this node
	int countSizeOfLeftTree(void);
	int countSizeOfTree(void);
	int findKthMin(int);
	bool find(int);

	// functions for Testing of Definitions
	bool BSTDefinition();
	bool rootIsBlack();
	bool childrenAreBlack();
	bool sameBlackOnPath();
	bool LLRBT();

	bool parentsChildrenCheck();

	void print();
	
	
private:
	bool red;
	
	//size of left subtree strating from this node excluding this node
	int sizeOfLeftTree;
	RBTreeNode* left;
	RBTreeNode* right;
	RBTreeNode* parent;
	int key;

	RBTreeNode* uncle();
	void recolor(RBTreeNode*);
	void recolor4vertex(RBTreeNode*);
	void rotateRedEdge(RBTreeNode*);
	bool is4vertex();
	bool isRed(RBTreeNode*);
	bool insertRecursion(RBTreeNode* node);

	// Supporting functions for tests
	int getMinFromRight();
	int getMaxFromLeft();
	bool blackChildrenRecursion(RBTreeNode*);
	bool LLRBTRecursion(RBTreeNode*);
	int sameBlackOnPathRecursion(RBTreeNode*);
	bool parentsChildrenCheckRecursion(RBTreeNode*);
};