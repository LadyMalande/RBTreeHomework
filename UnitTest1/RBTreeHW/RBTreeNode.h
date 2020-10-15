#pragma once
class RBTreeNode {
public:
	RBTreeNode(bool r, RBTreeNode* left, RBTreeNode* right, RBTreeNode* par, int k) : red(r), leftSon(left), rightSon(right), parent(par), key(k) {}
	RBTreeNode(int k): red(true), leftSon(nullptr), rightSon(nullptr), parent(nullptr), key(k){}
	bool red;
	RBTreeNode* leftSon;
	RBTreeNode* rightSon;
	RBTreeNode* parent;
	int key;

};