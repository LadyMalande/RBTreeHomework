#include "pch.h"
#include "CppUnitTest.h"
#include "../RBTreeHW/RBTree.cpp"
#include "../RBTreeHW/RBTreeNode.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace RBTreeDefinitionTest
{
	TEST_CLASS(RBTreeDefinitionTest)
	{
	public:
		
		TEST_METHOD(BSTDefinition)
		{
			
		}

		TEST_METHOD(rootIsBlack)
		{
			Assert::IsFalse(testTree.getRoot()->red);
		}

		TEST_METHOD(childrenOfRedNodeAreBlack)
		{
			RBTreeNode* node = testTree.getRoot();
			checkChildrenOfRedNode(node);
		}

		TEST_METHOD(allPathsToNilsGoThroughSameNumberOfBlack)
		{
		}

	private:
		RBTree testTree;
		void checkChildrenOfRedNode(RBTreeNode* node) {
			while (node) {
				if (node->red) {
					Assert::IsFalse(testTree.isRed(node->left));
					Assert::IsFalse(testTree.isRed(node->right));
				}
				checkChildrenOfRedNode(node->left);
				checkChildrenOfRedNode(node->right);
			}
		}
		
	};
}
