#include "RBTree.h"

RBTree::RBTree(int k) {
	root = &RBTreeNode(k);
}

RBTree::RBTree() {
	root = nullptr;
}

bool RBTree::insert(int key) {
	// When crating new node, the node is red from its constructor
	RBTreeNode* newOne = &RBTreeNode(key);
	if (root == nullptr) {
		root = &newOne;
		// Newly added root is black
		root->red = false;
		return true;
	} else{
		RBTreeNode* node = root;
		while (node) {
			if (key < node->key) {
				if (node->left) {
					node = node->left;
				}
				else {
					node->left = newOne;
					newOne->parent = node;
				}
			}
			else if(key > node->key) {
				if (node->right) {
					node = node->right;
				}
				else {
					
					node->right = newOne;
					newOne->parent = node;
				}
			}
		}
		// the node is inserted

		// parent is red, we must do some editing
		if (newOne->parent->red) {
			if (isRed(uncle(newOne))) {
				recolor(newOne->parent);
				recolor(uncle(newOne));
				recolor(newOne->parent->parent);
			}
			else {

			}
		}


	}
	return false;
}

bool RBTree::isRed(RBTreeNode* node) {
	if (!node) {
		return false;
	}
	else {
		return node->red;
	}
}

RBTreeNode* RBTree::findKthMIN(int) {

}

bool RBTree::erase(int) {

}

void RBTree::rotateRedEdge(RBTreeNode*) {

}
	
void RBTree::recolor(RBTreeNode* node) {
	if(node){
		if (node->red) {
			node->red = false;
		}
		else {
			node->red = true;
		}
	}	
}

RBTreeNode* RBTree::moveRedLeft(RBTreeNode*) {

}

RBTreeNode* RBTree::moveRedRight(RBTreeNode*) {

}

RBTreeNode* RBTree::eraseMIN(RBTreeNode*) {

}

RBTreeNode* RBTree::eraseMAX(RBTreeNode*) {

}

RBTreeNode* RBTree::find(int key) {
	RBTreeNode* node = root;
	while (node) {
		if (key == node->key) {
			return node;
		}
		else if (key < node->key) {
			node = node->left;
		}
		else {
			node = node->right;
		}
	}

	return nullptr;
}

RBTreeNode* RBTree::uncle(RBTreeNode* x) {
	if (x->parent) {
		if (x->parent->parent) {
			if (x->parent->key < x->parent->parent->key) {
				return x->parent->parent->right;
			}
			else if (x->parent->key > x->parent->parent->key) {
				return x->parent->parent->left;
			}
			else {
				return nullptr;
			}
		}
	}
	else {
		return nullptr;
	}
	 
}

RBTreeNode* RBTree::getRoot() {
	return root;
}

void RBTree::setRoot(RBTreeNode* newRoot) {
	root = newRoot;
}

int RBTree::size() {
	return sizeSubtree(root);
}

int RBTree::sizeSubtree(RBTreeNode* node) {
	if (node) {
		return 1 + sizeSubtree(node->left) + sizeSubtree(node->right);
	}
	else {
		return 0;
	}
}