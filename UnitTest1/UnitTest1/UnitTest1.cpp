#include "pch.h"
#include "CppUnitTest.h"
#include "../RBTreeHW/RBTree.cpp"
#include "../RBTreeHW/RBTree.h"
#include "../RBTreeHW/RBTreeNode.h"
#include "../RBTreeHW/RBTreeNode.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;


namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:
		/*
		TEST_METHOD_INITIALIZE(buildTree)
		{
			// Code that runs before every TEST_METHOD which is in method buildTree
			RBTreeNode firstNode = RBTreeNode(5);
			RBTree tree = RBTree();


			// Inserting values
			RBTreeNode(5).insert(&tree);
			RBTreeNode(8).insert(&tree);
			RBTreeNode(3).insert(&tree);
			RBTreeNode(4).insert(&tree);
			RBTreeNode(4).insert(&tree);
			RBTreeNode(15).insert(&tree);
			RBTreeNode(1).insert(&tree);
			RBTreeNode(7).insert(&tree);
			RBTreeNode(9).insert(&tree);
			RBTreeNode(2).insert(&tree);
			RBTreeNode(11).insert(&tree);
			RBTreeNode(6).insert(&tree);
			RBTreeNode(10).insert(&tree);

		}
		*/
		TEST_METHOD(RBTreeConstructorTest)
		{
			RBTreeNode firstNode = RBTreeNode(1);
			RBTree tree = RBTree();
			firstNode.insert(&tree);
			Assert::IsNotNull(tree.getRoot());
		}

		TEST_METHOD(RBTreeNumberOfNodesAfterInsert) {
			Assert::AreEqual(13, testTree.size());
		}

		TEST_METHOD(RBTreeInsertShapeCheck) {
			{
				Assert::IsTrue(testTree.getRoot()->parentsChildrenCheck());

			}
		}

		TEST_METHOD(RBTreeShapeAfterDelete) {
			testTree.erase(10);
			{
				// The only value that vanished is the erased one
				Assert::IsFalse(testTree.find(10));
				Assert::IsTrue(testTree.find(1));
				Assert::IsTrue(testTree.find(2));
				Assert::IsTrue(testTree.find(3));
				Assert::IsTrue(testTree.find(4));
				Assert::IsTrue(testTree.find(5));
				Assert::IsTrue(testTree.find(6));
				Assert::IsTrue(testTree.find(7));
				Assert::IsTrue(testTree.find(8));
				Assert::IsTrue(testTree.find(9));
				Assert::IsTrue(testTree.find(10));
				Assert::IsTrue(testTree.find(11));
				Assert::IsTrue(testTree.find(12));
				Assert::IsTrue(testTree.find(15));
			}
			
		}

		TEST_METHOD(RBTreeSizeAfterDelete) {
			testTree.erase(10);
			Assert::AreEqual(12, testTree.size());
		}

		TEST_METHOD(RBTreeFindExistsReturn) {
			Assert::IsTrue(testTree.find(9));
		}

		TEST_METHOD(RBTreeFindDoesntExistReturn) {
			Assert::IsFalse(testTree.find(14));
			Assert::IsFalse(testTree.find(0));
		}

		TEST_METHOD(RBTreeKthMINFindReturn) {
			for (int i = 1; i < 13; i++) {
				Assert::AreEqual(i, testTree.findKthMIN(i));
			}			
		}

		TEST_METHOD(RBTreeKthMINFindOutOfBounds) {
			Assert::IsFalse(testTree.findKthMIN(0));
			Assert::IsFalse(testTree.findKthMIN(14));
		}

		TEST_METHOD(RBTreeNodeIsRedAfterInsert) {
			
		}

	private:
		RBTree testTree;

		/*
		void buildTree() {
			//Making tree
			RBTreeNode firstNode = RBTreeNode(5);
			RBTree tree = RBTree();


			// Inserting values
			RBTreeNode(5).insert(&tree);
			RBTreeNode(8).insert(&tree);
			RBTreeNode(3).insert(&tree);
			RBTreeNode(4).insert(&tree);
			RBTreeNode(4).insert(&tree);
			RBTreeNode(15).insert(&tree);
			RBTreeNode(1).insert(&tree);
			RBTreeNode(7).insert(&tree);
			RBTreeNode(9).insert(&tree);
			RBTreeNode(2).insert(&tree);
			RBTreeNode(11).insert(&tree);
			RBTreeNode(6).insert(&tree);
			RBTreeNode(10).insert(&tree);

			// Tree Shape
			
			//				8
			//		4		         12
			//   2	   6		  10      15
			//1     3  5   7      9   11
			
		}
		*/
	};
}
