#pragma once

#include <limits>
#include <iostream>
class RBTree {

	class RBTreeNode;
	class RBTreeNode {

	public: RBTreeNode* left; 
			RBTreeNode* right; 
			RBTreeNode* parent;
			int key; 
			bool red;
			int sizeOfLeftTree;

			//Constructor
			RBTreeNode(int k) : red(true), left(nullptr), right(nullptr), parent(nullptr), key(k), sizeOfLeftTree(0) { }
	};
public:
	// Constructors
	RBTree();
	// Basic functions of the tree.
	//insert node with given key
	bool insert(int);
	int findKthMIN(int);
	bool erase(int);
	bool find(int);
	
	void clean();
	int size();
	void printTree();

	// functions for Testing of Definitions
	bool BSTDefinition();
	bool rootIsBlack();
	bool childrenAreBlack();
	bool sameBlackOnPath();
	bool LLRBT();

private:
	RBTreeNode* root;
	bool inserted;
	void recolor(RBTree::RBTreeNode*);
	// Two balancing operations
	void rotateRedEdge(RBTreeNode*);
	void rotate(RBTree::RBTreeNode* parent, RBTree::RBTreeNode* node);
	// Support function of the tree
	RBTreeNode* moveRedLeft(RBTreeNode*);
	RBTreeNode* moveRedRight(RBTreeNode*);
	RBTreeNode* eraseMIN(RBTreeNode*);
	RBTreeNode* eraseMAX(RBTreeNode*);
	RBTreeNode& recursiveInsert(RBTreeNode&, int);

	bool parentsChildrenCheck();

	int countSizeOfTree(RBTreeNode*);
	int sizeOfLeftTree(RBTreeNode* node);
	// Supporting functions for tests
	bool BSTDefinitionRecursion(RBTreeNode*);
	int getMinFromRight(RBTreeNode* node);
	int getMaxFromLeft(RBTree::RBTreeNode* node);
	bool blackChildrenRecursion(RBTreeNode*);
	bool LLRBTRecursion(RBTreeNode*);
	int sameBlackOnPathRecursion(RBTreeNode*);
	bool parentsChildrenCheckRecursion(RBTreeNode*);
	int findKthMINRecursion(RBTreeNode* node, int k);
};