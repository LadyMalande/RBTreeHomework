#pragma once
#include <iostream>
class RBTreeNode {
public:
	// Constructors
	RBTreeNode(bool r, RBTreeNode* left, RBTreeNode* right, RBTreeNode* par, int k) : red(r), left(left), right(right), parent(par), key(k) {}
	RBTreeNode(int k) : red(true), left(nullptr), right(nullptr), parent(nullptr), key(k) { printf("%d", k); printf("%d", key); }
		
	bool red;
	RBTreeNode* left;
	RBTreeNode* right;
	RBTreeNode* parent;
	int key;

};