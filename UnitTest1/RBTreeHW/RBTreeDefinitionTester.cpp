#include "RBTreeDefinitionTester.h"
#include "RBTreeNode.h"
using namespace std;

bool RBTreeDefinitionTester::test(RBTree* tree) {
	bool bst = BSTDefinition(tree);
	bool rootCheck = rootIsBlack(tree);
	bool childrenCheck = childrenOfRedNodeAreBlack(tree);
	bool samenumberOfBlack = allPathsToNilsGoThroughSameNumberOfBlack(tree);
	bool LLTRBT = ifOnlyChildIsRedItsOnLeft(tree);
	if (bst && rootCheck && childrenCheck && samenumberOfBlack && LLTRBT) {
		cout << "All definiton test passed." << endl;
		return true;
	}
	else {
		cout << "Some test didn't pass:" << endl;
		cout << "Binary search tree property passed: " << bst << endl;
		cout << "Root is black passed: " << rootCheck<< endl;
		cout << "Red node has only black children passed: " << childrenCheck << endl;
		cout << "All paths have same number of black nodes passed: " << samenumberOfBlack << endl;
		cout << "One child red is left child passed: " << LLTRBT << endl;
		return false;
	}
}

// binary search tree definition: The maximum of left sub tree is less than current node, the minimum of right subtree is bigger than current node
bool RBTreeDefinitionTester::BSTDefinition(RBTree* tree) {
	return tree->getRoot()->BSTDefinition();
}
// Methods for 3 stages of RBTree difinition

// Root of the Red Black tree is always black
bool RBTreeDefinitionTester::rootIsBlack(RBTree* tree) {
	return tree->getRoot()->rootIsBlack();
}

// Children of red nodes are black == There are no two red nodes in a path from root to leaf directly after each other
bool RBTreeDefinitionTester::childrenOfRedNodeAreBlack(RBTree* tree) {
	return tree->getRoot()->childrenAreBlack();
}

// All paths from root to leaves included go through the same number of black nodes
bool RBTreeDefinitionTester::allPathsToNilsGoThroughSameNumberOfBlack(RBTree* tree) {
	return tree->getRoot()->sameBlackOnPath();
}

// The left-leaning RBTree definition - if there is only one red child, it is the left child of current node
bool RBTreeDefinitionTester::ifOnlyChildIsRedItsOnLeft(RBTree* tree) {
	return tree->getRoot()->LLRBT();
}
