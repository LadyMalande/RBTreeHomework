#include "RBTree.h"

using namespace std;

RBTree::RBTree() {
	root = nullptr;
	inserted = false;
}

int RBTree::size() {
	return countSizeOfTree(root);
}

int RBTree::countSizeOfTree(RBTreeNode* node) {
	int size = 0;
	if (node) {
		size = 1;
		size = node->left ? size + countSizeOfTree(node->left) : size;
		size = node->right ? size + countSizeOfTree(node->right) : size;
	}	
	return size;
}

int RBTree::sizeOfLeftTree(RBTreeNode* node) {
	int size;
	if (node->left) {
		size = countSizeOfTree(node->left);
	}
	else {
		size = 0;
	}

	return size;
}

int RBTree::findKthMIN(int k) {
	return findKthMINRecursion(root, k);
}



int RBTree::findKthMINRecursion(RBTreeNode* node, int k) {
		if (k < 1 || k > countSizeOfTree(node)) {
			// the number was not found - the place is out of bounds
			return INT_MIN;
		}
		while (node) {
			// kth node lies in the left subtree 
			if (k <= sizeOfLeftTree(node)) {
				node = node->left;
			}
			// kth node is this node
			else if (k == sizeOfLeftTree(node) + 1) {
				return node->key;
			}
			// kth node lies in right subtree
			else {
				// Make the k smaller by the size of left subtree + this node
				k = k - (sizeOfLeftTree(node) + 1);
				node = node->right;
			}
		}
}

void RBTree::printTree() {
	//TODO
}

bool RBTree::erase(int) {
	// TODO
	return false;
}

void RBTree::rotateRedEdge(RBTreeNode*) {
	// TODO
}
	

RBTree::RBTreeNode* RBTree::moveRedLeft(RBTreeNode*) {
	// TODO
	return nullptr;
}

RBTree::RBTreeNode* RBTree::moveRedRight(RBTreeNode*) {
	// TODO
	return nullptr;
}

RBTree::RBTreeNode* RBTree::eraseMIN(RBTreeNode*) {
	// TODO
	return nullptr;
}

RBTree::RBTreeNode* RBTree::eraseMAX(RBTreeNode*) {
	// TODO
	return nullptr;
}

bool RBTree::find(int key) {
	// TODO
	return false;
}

void RBTree::clean() {
	root = nullptr;
}

void RBTree::recolor(RBTreeNode* x) {
	bool sth = x->red ? x->red = false : x->red = true;
}

void RBTree::rotate(RBTree::RBTreeNode* parent, RBTree::RBTreeNode* son) {
	son->red = parent->red;
	parent->red = true;
	recolor(son);
	if (parent->key > son->key) {
		parent->left = son->right;
		son->right = parent;
	}
	else if (parent->key < son->key) {
		parent->right = son->left;
		son->left = parent;
	}
	// the parent is not root
	if(parent->parent){
		if (parent->parent->left == parent) {
			parent->parent->left = son;
		}
		else {
			parent->parent->right = son;
		}
		son->parent = parent->parent;		
	}
	// the parent is root
	else {
		root = son;
		son->parent = nullptr;
	}
	parent->parent = son;
}

bool RBTree::insert(int x) {
	inserted = false;
	cout << "inserting " << x << endl;
 	root = &recursiveInsert(*root, x); 
	root->red = false;
	return inserted;
}

RBTree::RBTreeNode& RBTree::recursiveInsert(RBTree::RBTreeNode &v, int x) {

	// The v is null, insert a node
	if (v != nullptr) {
		RBTreeNode node(x);
		v = *&node;
		inserted = true; 
		return v;
	}
	else {
		// the key is already there
		if (x == v->key) {
			return nullptr;
		}
		// WE have to recolor nodes
		if (v->left != nullptr && v->right != nullptr) {
			if (v->left->red && v->right->red) {
				recolor(v->left);
				recolor(v->right);
				recolor(v);
			}
			}
			// x is smaller than the current key, go left
			if (x < v->key) {
				v->left = recursiveInsert(v->left, x);
			}
			if (x > v->key) {
				v->right = recursiveInsert(v->right, x);
			}
			// rotate if neccessary
			if (v->right && ((!v->left->red && v->right->red) || (!v->left && v->right->red))) {
				RBTreeNode* pom = v->right;
				rotate(v, v->right);
				v = pom;
			}
			if (v->left && v->left->left && (v->left->red && v->left->left->red)) {
				RBTreeNode* pom = v->left;
				rotate(v, v->left);
				v = pom;
			}
		}

	return v;
}



bool RBTree::BSTDefinition() {
	return BSTDefinitionRecursion(root);
}

bool RBTree::BSTDefinitionRecursion(RBTreeNode* node) {
	// if the node doesnt have children, it holds
	bool isGreatedThanMaxInLeft = true;
	bool isSmallerThanMinInRight = true;
	bool leftSubtreeHolds = true;
	bool rightSubtreeHolds = true;
	if (node->left) {
		if (node->key < getMaxFromLeft(node->left)) {
			isGreatedThanMaxInLeft = false;
		}
		leftSubtreeHolds = BSTDefinitionRecursion(node->left);
	}
	if (node->right) {
		if (node->key > getMinFromRight(node->right)) {
			isSmallerThanMinInRight = false;
		}
		rightSubtreeHolds = BSTDefinitionRecursion(node->right);
	}
	return isGreatedThanMaxInLeft && isSmallerThanMinInRight && leftSubtreeHolds && rightSubtreeHolds;
}

// this function should always be used only on the root
bool RBTree::rootIsBlack() {

	return !root->red;
}


bool RBTree::childrenAreBlack() {
	return blackChildrenRecursion(root);
}

bool RBTree::blackChildrenRecursion(RBTreeNode* node) {
	if (node) {
		if (node->red) {
			if (node->left) {
				if (node->left->red) {
					return false;
				}
			}
			if (node->right) {
				if (node->right->red) {
					return false;
				}
			}
		}
		return blackChildrenRecursion(node->left) && blackChildrenRecursion(node->right);
	}
	else {
		return true;
	}
}

bool RBTree::sameBlackOnPath() {
	return sameBlackOnPathRecursion(root->left) == sameBlackOnPathRecursion(root->right);
}

int RBTree::sameBlackOnPathRecursion(RBTreeNode* node) {
	if (node) {
		int leftSize = sameBlackOnPathRecursion(node->left);
		if (leftSize == sameBlackOnPathRecursion(node->right)) {
			int thisBlackToo = node->red ? 0 : 1;
			return leftSize + thisBlackToo;
		}
		else {
			// The subtrees dont have the same numbers of black nodes on their path to leaves so it cant hold up the tree either
			return INT_MIN;
		}
	}
	else {
		// the null leaves are black = +1 to the path black number
		return 1;
	}
}

bool RBTree::LLRBT() {
	return LLRBTRecursion(root);
}

bool RBTree::LLRBTRecursion(RBTreeNode* node) {
	if (node) {
		// Both children exist - if only the right is red -= WRONG
		if (node->left && node->right) {
			if ((!node->left->red && node->right->red)) {
				return false;
			}
		}
		// the left one is black and the right one is red = WRONG
		if (!node->left && node->right->red) {
			return false;
		}
		return LLRBTRecursion(node->left) && LLRBTRecursion(node->right);
	}
	else {
		// the node is null so the definition holds
		return true;
	}

}
int RBTree::getMinFromRight(RBTreeNode* node) {
	// if there is no node in right, the definition will hold because key is most probably < INT_MAX
	int minimum = INT_MAX;
	while (node) {
		minimum = node->key;
		node = node->left;
	}
	return minimum;
}

int RBTree::getMaxFromLeft(RBTreeNode* node) {
	// if there is no node in left, the definition will hold because key is most probably > INT_MIN
	int maximum = INT_MIN;
	while (node) {
		maximum = node->key;
		node = node->right;
	}
	return maximum;

}

bool RBTree::parentsChildrenCheck() {
	if (root->parent) {
		// We start from root and root should not have parent
		return false;
	}
	return parentsChildrenCheckRecursion(root->left) && parentsChildrenCheckRecursion(root->right);
}

bool RBTree::parentsChildrenCheckRecursion(RBTreeNode* node) {
	if (node) {
		if (node->key < node->parent->key) {
			//This is left child
			if (node != node->parent->left) {
				return false;
			}
		}
		else {
			//this is right child
			if (node != node->parent->right) {
				return false;
			}
		}
		return parentsChildrenCheckRecursion(node->left) && parentsChildrenCheckRecursion(node->right);
	}
	else {
		// node does not have parent so parent cant be checked
		return true;
	}
}
