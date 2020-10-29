
#include "RBTreeNode.h"

using namespace std;

bool RBTreeNode::insert(RBTree* tree) {
	RBTreeNode* root = tree->getRoot();
	if (root == nullptr) {
		red = false;
		tree->insertRoot(this);
		cout << "Root inserted" << key << endl;
		// Newly added root is black
		return true;
		
	}
	else {
		cout << "Trying to insert " << key << endl;
		return insertRecursion(root);
	}
	
}

bool RBTreeNode::insertRecursion(RBTreeNode* node) {

			// WE go down the tree and whenever we see a 4-vertex, we recolor it
			if (node->is4vertex()) {
				node->recolor4vertex(node);
			}
			if (key == node->key) {
				return false;
			}
			if (key < node->key) {
				if (node->left) {
					if (!insertRecursion(node->left)) {
						return false;
					}
				}
				else {
					node->left = this;
					red = true;
					parent = node;
					left = nullptr;
					right = nullptr;
					return true;
				}
			}
			else if (key > node->key) {
				if (node->right) {
					if (!insertRecursion(node->right)) {
						return false;
					}
				}
				else {
					
					node->right = this;
					parent = node;
					red = true;
					left = nullptr;
					right = nullptr;
					return true;
				}
			}

		// the node is inserted

	if (!isRed(node->left) && isRed(node->right)) {
				rotateRedEdge(node->right);
	}

	if (isRed(node->left) && isRed(node->left->left)) {
		rotateRedEdge(node->left);
	}
	
	return true;
}

// Two balancing operations
void RBTreeNode::rotateRedEdge(RBTreeNode* node) {
	//node byl cerveny, posune se nahoru misto parenta a prebarvi se
	RBTreeNode* formerParent = node->parent;
	RBTreeNode* formerOtherKidOfNode;
	if (node->parent->key > node->key) {
		// rodic je vetsi, jsme tedy nalevo od nej
		formerOtherKidOfNode = node->right;
		node->right = node->parent;
		node->parent = node->parent->parent;
		node->red = false;
		formerParent->left = formerOtherKidOfNode;
		formerParent->parent = node;
		formerParent->red = true;

	}
	else {
		// rodic je mensi, jsme nalevo od nej
		formerOtherKidOfNode = node->left;
		node->left = node->parent;
		node->parent = node->parent->parent;
		node->red = false;
		formerParent->right = formerOtherKidOfNode;
		formerParent->parent = node;
		formerParent->red = true;
	}
}

void RBTreeNode::recolor4vertex(RBTreeNode* node) {
	// presouvame barvu do deti
	recolor(node);
	recolor(node->left);
	recolor(node->right);
}

bool RBTreeNode::is4vertex() {
	// Jsou li obe deti cervene, prebarvujeme
	if (isRed(left) == true && (isRed(left) == isRed(right)) && (isRed(left) != red)) {
		return true;
	}
	else {
		return false;
	}
}

bool RBTreeNode::isRed(RBTreeNode* node) {
	return node ? node->red : false;
}

int RBTreeNode::countSizeOfLeftTree() {
	int size;
	if (left) {
		size = left->countSizeOfTree();
	}
	else {
		size = 0;
	}
	
	return size;
}

int RBTreeNode::countSizeOfTree() {
	int size = 1;
	size = left ? size + left->countSizeOfTree() : size;
	size = right ? size + right->countSizeOfTree() : size;
	return size;
}

RBTreeNode* RBTreeNode::uncle() {
	if (parent) {
		if (parent->parent) {
			if (parent->key < parent->parent->key) {
				// Uncle is bigger than our parent
				return parent->parent->right;
			}
			else{
				// Uncle is smaller than our parent
				return parent->parent->left;
			}
		}
	}
	else {
		return nullptr;
	}

}

void RBTreeNode::recolor(RBTreeNode* x) {
	bool sth = x->red ? x->red = false : x->red = true;
}

int RBTreeNode::findKthMin(int k) {
	if (k < 1 || k > countSizeOfTree()) {
		// the number was not found - the place is out of bounds
		return INT_MIN;
	}

	RBTreeNode* node = this;
	while (node) {
		// kth node lies in the left subtree 
		if (k <= node->sizeOfLeftTree) {
			node = node->left;
		}
		// kth node is this node
		else if (k == node->sizeOfLeftTree + 1) {
			return node->key;
		}
		// kth node lies in right subtree
		else {
			// Make the k smaller by the size of left subtree + this node
			k = k - (node->sizeOfLeftTree + 1);
			node = node->right;
		}
	}


}

bool RBTreeNode::find(int k) {
	RBTreeNode* node = this;
	while (node) {
		cout << "Hledam " << k << " v nodu " << node->key << endl;
		if (k == node->key) {
			return true;
		}
		else if (k < node->key) {
			node = node->left;
		}
		else {
			node = node->right;
		}
	}

	return false;
}

bool RBTreeNode::BSTDefinition() {
	// if the node doesnt have children, it holds
	bool isGreatedThanMaxInLeft = true; 
	bool isSmallerThanMinInRight = true;
	bool leftSubtreeHolds = true;
	bool rightSubtreeHolds = true;
	if (left) {
		if (key < getMaxFromLeft()) {
			isGreatedThanMaxInLeft = false;
		}
		leftSubtreeHolds = left->BSTDefinition();
	}
	if (right) {
		if (key > getMinFromRight()) {
			isSmallerThanMinInRight = false;
		}
		rightSubtreeHolds = right->BSTDefinition();
	}
	return isGreatedThanMaxInLeft && isSmallerThanMinInRight && leftSubtreeHolds && rightSubtreeHolds;
}

// this function should always be used only on the root
bool RBTreeNode::rootIsBlack() {
	
	return !red;
}


bool RBTreeNode::childrenAreBlack() {
	return blackChildrenRecursion(this);
}

bool RBTreeNode::blackChildrenRecursion(RBTreeNode* node) {
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

bool RBTreeNode::sameBlackOnPath() {
	return sameBlackOnPathRecursion(left) == sameBlackOnPathRecursion(right);
}

int RBTreeNode::sameBlackOnPathRecursion(RBTreeNode* node) {
	if (node) {
		int leftSize = sameBlackOnPathRecursion(left);
		if (leftSize == sameBlackOnPathRecursion(right)) {
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

bool RBTreeNode::LLRBT() {
	return LLRBTRecursion(this);
}

bool RBTreeNode::LLRBTRecursion(RBTreeNode* node) {
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
int RBTreeNode::getMinFromRight() {
	// if there is no node in right, the definition will hold because key is most probably < INT_MAX
	int minimum = INT_MAX;
	RBTreeNode* node = right;
	while (node) {
		minimum = node->key;
		node = node->left;
	}
	return minimum;
}

int RBTreeNode::getMaxFromLeft() {
	// if there is no node in left, the definition will hold because key is most probably > INT_MIN
	int maximum = INT_MIN;
	RBTreeNode* node = left;
	while (node) {
		maximum = node->key;
		node = node->right;
	} 
	return maximum;
	
}

bool RBTreeNode::parentsChildrenCheck() {
	if (parent) {
		// We start from root and root should not have parent
		return false;
	}
	return parentsChildrenCheckRecursion(left) && parentsChildrenCheckRecursion(right);
}

bool RBTreeNode::parentsChildrenCheckRecursion(RBTreeNode* node) {
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

void RBTreeNode::print() {
		
		
		
		if (left && right) {
			cout << key << " LEFT: " << left->key << "    RIGHT: " << right->key << endl;
		}
		else if (left && !right) {
			cout << key << " LEFT: " << left->key << "    RIGHT: NULL" << endl;
		}
		else if (!left && right) {
			cout << key << " LEFT: NULL    RIGHT: " << right->key << endl;
		}
		else {
			cout << key << " LEFT: NULL    RIGHT: NULL" << endl;
		}
		if (left) {
			left->print();
		}
		if (right) {
			right->print();
		}
}