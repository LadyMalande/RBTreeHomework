#include "pch.h"
#include "CppUnitTest.h"
#include "../RBTreeHW/RBTree.cpp"
#include "../RBTreeHW/RBTree.h"
#include "../RBTreeHW/RBTreeNode.h"
#include "../RBTreeHW/RBTreeNode.cpp"
/* The tests were moved to RBTreeDefinitionTester.cpp
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace RBTreeDefinitionTest
{
	TEST_CLASS(RBTreeDefinitionTest)
	{
	public:
		
		// Classic binary search tree definition = the order of nodes sorted by keys
		// children in the left subtree are smaller/= than key, children in the right subtree are greater/= than key
		TEST_METHOD(BSTDefinition)
		{
			testKeys(testTree.getRoot());
		}

		// The root of the tree is black
		TEST_METHOD(rootIsBlack)
		{
			Assert::IsFalse(testTree.getRoot()->red);
		}

		// Both children of red node are black
		TEST_METHOD(childrenOfRedNodeAreBlack)
		{
			RBTreeNode* node = testTree.getRoot();
			checkChildrenOfRedNode(node);
		}

		// All paths going from a node to null have the same number of black nodes
		TEST_METHOD(allPathsToNilsGoThroughSameNumberOfBlack)
		{
			checkBlacksOnPath(testTree.getRoot());
		}

	private:
		RBTree testTree;
		
		void checkChildrenOfRedNode(RBTreeNode* node) {
			if(node){
				if (node->red) {
					Assert::IsFalse(testTree.isRed(node->left));
					Assert::IsFalse(testTree.isRed(node->right));
				}
				checkChildrenOfRedNode(node->left);
				checkChildrenOfRedNode(node->right);
			}
		}

		int checkBlacksOnPath(RBTreeNode* node) {
			if (node) {
				Assert::AreEqual(checkBlacksOnPath(node->left), checkBlacksOnPath(node->right));
				int isBlack;
				if (node->red) {
					isBlack = 0;
				}
				else {
					isBlack = 1;
				}
				return checkBlacksOnPath(node->left) + isBlack;
			}
			else {
				return 1;
			}
		}

		void testKeys(RBTreeNode* node) {
			if (node->left) {
				Assert::IsTrue(node->left->key =< node->key);
				testKeys(node->left);
			}
			if (node->right) {
				Assert::IsTrue(node->right->key >= node->key);
				testKeys(node->right);
			}			
		}		
	};
}

*/
