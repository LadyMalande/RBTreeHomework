#include "RBTree.h"
#include "RBTreeNode.h"

RBTree::RBTree() {
	root = nullptr;
}


int RBTree::findKthMIN(int k) {
	if (root) {
		return root->findKthMin(k);
	}
	return INT_MIN;
}

bool RBTree::erase(int) {
	// TODO
	return false;
}

void RBTree::rotateRedEdge(RBTreeNode*) {
	// TODO
}
	

RBTreeNode* RBTree::moveRedLeft(RBTreeNode*) {
	// TODO
	return nullptr;
}

RBTreeNode* RBTree::moveRedRight(RBTreeNode*) {
	// TODO
	return nullptr;
}

RBTreeNode* RBTree::eraseMIN(RBTreeNode*) {
	// TODO
	return nullptr;
}

RBTreeNode* RBTree::eraseMAX(RBTreeNode*) {
	// TODO
	return nullptr;
}

bool RBTree::find(int key) {
	return root->find(key);
}

RBTreeNode* RBTree::getRoot() {
	return root;
}

void RBTree::insertRoot(RBTreeNode* newRoot) {
	if (!root) {
		root = newRoot;
	}
	else {
		// You cant change root if the root still exists, this is public method only for root insertion!
	}
}

void RBTree::setRoot(RBTreeNode* newroot) {
	root = newroot;
}

int RBTree::size() {
	return root->countSizeOfTree();
}
