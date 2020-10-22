#pragma once
#include "RBTree.h"

class RBTreeDefinitionTester {
public: void test(RBTree*);
private: 
	void BSTDefinition(RBTree*);
	// Methods for 4 stages of RBTree difinition
	void rootIsBlack(RBTree*);
	void childrenOfRedNodeAreBlack(RBTree*);
	void allPathsToNilsGoThroughSameNumberOfBlack(RBTree*);

};