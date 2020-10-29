#pragma once
#include "RBTree.h"
#include <iostream>

class RBTreeDefinitionTester {
public: bool test(RBTree*);
private: 
	bool BSTDefinition(RBTree*);
	// Methods for 4 stages of RBTree difinition
	bool rootIsBlack(RBTree*);
	bool childrenOfRedNodeAreBlack(RBTree*);
	bool allPathsToNilsGoThroughSameNumberOfBlack(RBTree*);
	bool ifOnlyChildIsRedItsOnLeft(RBTree* tree);

};