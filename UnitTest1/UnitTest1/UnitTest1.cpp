#include "pch.h"
#include "CppUnitTest.h"
#include "../RBTreeHW/RBTree.cpp"
#include "../RBTreeHW/RBTreeNode.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;


namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD_INITIALIZE(buildTree)
		{
			// Code that runs before every TEST_METHOD which is in method buildTree

		}
		TEST_METHOD(RBTreeConstructorTest)
		{
			RBTreeNode firstNode = RBTreeNode(1);
			RBTree tree = RBTree(&firstNode);
			Assert::AreEqual(1, tree.getRoot()->key);
		}

		TEST_METHOD(RBTreeNumberOfNodesAfterInsert) {
			Assert::AreEqual(13, testTree.size());
		}

		TEST_METHOD(RBTreeInsertShapeCheck) {
			{
				Assert::IsNull(testTree.find(8)->parent);
				Assert::AreEqual(4,testTree.find(8)->left->key);
				Assert::AreEqual(12,testTree.find(8)->right->key);
				
				Assert::AreEqual(8, testTree.find(4)->parent->key);
				Assert::AreEqual(2, testTree.find(4)->left->key);
				Assert::AreEqual(6, testTree.find(4)->right->key);

				Assert::AreEqual(8, testTree.find(12)->parent->key);
				Assert::AreEqual(10, testTree.find(12)->left->key);
				Assert::AreEqual(15, testTree.find(12)->right->key);

				Assert::AreEqual(4, testTree.find(2)->parent->key);
				Assert::AreEqual(1, testTree.find(2)->left->key);
				Assert::AreEqual(3, testTree.find(2)->right->key);

				Assert::AreEqual(4, testTree.find(6)->parent->key);
				Assert::AreEqual(5, testTree.find(6)->left->key);
				Assert::AreEqual(7, testTree.find(6)->right->key);

				Assert::AreEqual(12, testTree.find(10)->parent->key);
				Assert::AreEqual(9, testTree.find(10)->left->key);
				Assert::AreEqual(11, testTree.find(10)->right->key);

				Assert::AreEqual(12, testTree.find(15)->parent->key);
				Assert::IsNull(testTree.find(15)->left);
				Assert::IsNull(testTree.find(15)->right);

				Assert::AreEqual(2, testTree.find(1)->parent->key);
				Assert::IsNull(testTree.find(1)->left);
				Assert::IsNull(testTree.find(1)->right);

				Assert::AreEqual(2, testTree.find(3)->parent->key);
				Assert::IsNull(testTree.find(3)->left);
				Assert::IsNull(testTree.find(3)->right);

				Assert::AreEqual(6, testTree.find(5)->parent->key);
				Assert::IsNull(testTree.find(5)->left);
				Assert::IsNull(testTree.find(5)->right);

				Assert::AreEqual(6, testTree.find(7)->parent->key);
				Assert::IsNull(testTree.find(7)->left);
				Assert::IsNull(testTree.find(7)->right);

				Assert::AreEqual(10, testTree.find(9)->parent->key);
				Assert::IsNull(testTree.find(9)->left);
				Assert::IsNull(testTree.find(9)->right);

				Assert::AreEqual(10, testTree.find(11)->parent->key);
				Assert::IsNull(testTree.find(11)->left);
				Assert::IsNull(testTree.find(11)->right);


			}
		}

		TEST_METHOD(RBTreeShapeAfterDelete) {
			testTree.erase(10);
			{
				Assert::IsNull(testTree.find(8)->parent);
				Assert::AreEqual(4, testTree.find(8)->left->key);
				Assert::AreEqual(12, testTree.find(8)->right->key);

				Assert::AreEqual(8, testTree.find(4)->parent->key);
				Assert::AreEqual(2, testTree.find(4)->left->key);
				Assert::AreEqual(6, testTree.find(4)->right->key);

				Assert::AreEqual(8, testTree.find(12)->parent->key);
				Assert::AreEqual(9, testTree.find(12)->left->key);
				Assert::AreEqual(15, testTree.find(12)->right->key);

				Assert::AreEqual(4, testTree.find(2)->parent->key);
				Assert::AreEqual(1, testTree.find(2)->left->key);
				Assert::AreEqual(3, testTree.find(2)->right->key);

				Assert::AreEqual(4, testTree.find(6)->parent->key);
				Assert::AreEqual(5, testTree.find(6)->left->key);
				Assert::AreEqual(7, testTree.find(6)->right->key);

				Assert::AreEqual(12, testTree.find(15)->parent->key);
				Assert::IsNull(testTree.find(15)->left);
				Assert::IsNull(testTree.find(15)->right);

				Assert::AreEqual(2, testTree.find(1)->parent->key);
				Assert::IsNull(testTree.find(1)->left);
				Assert::IsNull(testTree.find(1)->right);

				Assert::AreEqual(2, testTree.find(3)->parent->key);
				Assert::IsNull(testTree.find(3)->left);
				Assert::IsNull(testTree.find(3)->right);

				Assert::AreEqual(6, testTree.find(5)->parent->key);
				Assert::IsNull(testTree.find(5)->left);
				Assert::IsNull(testTree.find(5)->right);

				Assert::AreEqual(6, testTree.find(7)->parent->key);
				Assert::IsNull(testTree.find(7)->left);
				Assert::IsNull(testTree.find(7)->right);

				Assert::AreEqual(12, testTree.find(9)->parent->key);
				Assert::IsNull(testTree.find(9)->left);
				Assert::AreEqual(11,testTree.find(9)->right->key);

				Assert::AreEqual(9, testTree.find(11)->parent->key);
				Assert::IsNull(testTree.find(11)->left);
				Assert::IsNull(testTree.find(11)->right);
			}
			Assert::IsNull(testTree.find(10));
		}

		TEST_METHOD(RBTreeSizeAfterDelete) {
			testTree.erase(10);
			Assert::AreEqual(12, testTree.size());
		}

		TEST_METHOD(RBTreeFindExistsReturn) {
			Assert::IsNotNull(testTree.find(9));
		}

		TEST_METHOD(RBTreeFindDoesntExistReturn) {
			Assert::IsNull(testTree.find(14));
		}

		TEST_METHOD(RBTreeKthMINFindReturn) {
			for (int i = 1; i < 14; i++) {
				Assert::AreEqual(i, testTree.findKthMIN(i)->key);
			}			
		}

		TEST_METHOD(RBTreeKthMINFindOutOfBounds) {
			Assert::IsNull(testTree.findKthMIN(0));
			Assert::IsNull(testTree.findKthMIN(14));
		}

		TEST_METHOD(RBTreeNodeIsRedAfterInsert) {
			Assert::IsTrue(testTree.find(10)->red);
		}

	private:
		RBTree testTree;

		void buildTree() {
			//Making tree
			RBTreeNode firstNode = RBTreeNode(5);
			RBTree tree = RBTree(&firstNode);

			// Inserting values
			tree.insert(12);
			tree.insert(8);
			tree.insert(3);
			tree.insert(4);
			tree.insert(4);
			tree.insert(15);
			tree.insert(1);
			tree.insert(7);
			tree.insert(9);
			tree.insert(2);
			tree.insert(11);
			tree.insert(6);
			tree.insert(10);

			// Tree Shape
			/*
							8
					4		         12
			   2	   6		  10      15
			1     3  5   7      9   11
			*/
		}
	};
}
