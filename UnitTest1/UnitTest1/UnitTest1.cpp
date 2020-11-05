#include "pch.h"
#include "CppUnitTest.h"
#include "../RBTreeHW/RBTree.cpp"
#include "../RBTreeHW/RBTree.h"


using namespace Microsoft::VisualStudio::CppUnitTestFramework;


namespace UnitTest1
{
	class RBTreeNodeTest;
	class RBTreeTest{
	public:		
		RBTreeNodeTest* root;
		void clean() {
			root = nullptr;
		}
	};
	class RBTreeNodeTest {
	public:
		RBTreeNodeTest(int k) : red(true), left(nullptr), right(nullptr), parent(nullptr), key(k), sizeOfLeftTree(0) { }
		RBTreeNodeTest* left;
		RBTreeNodeTest* right;
		RBTreeNodeTest* parent;
		int key;
		bool red;
		int sizeOfLeftTree;
	};

	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD_INITIALIZE(clean)
		{
			// Code that runs before every TEST_METHOD which is in method buildTree
			tree.clean();
		}
		
		TEST_METHOD(RBTreeConstructorTestTrue)
		{						
			Assert::IsTrue(tree.insert(2));
		}
/*
		TEST_METHOD(RBTreeConstructorTestFalse)
		{
			tree.insert(2);
			Assert::IsFalse(tree.insert(2));
		}
*/
		TEST_METHOD(RBTreeNumberOfNodesAfterInsert) {
			for (int i : {2, 3, 4, 5, 6, 1, 0}) { 
				tree.insert(i); }
			Assert::AreEqual(tree.size(), 7);
		}

		TEST_METHOD(RBTreeInsertShapeCheck) {
			
		}

		TEST_METHOD(RBTreeShapeAfterDelete) {
			
		}

		TEST_METHOD(RBTreeSizeAfterDelete) {

		}

		TEST_METHOD(RBTreeFindExistsReturn) {

		}

		TEST_METHOD(RBTreeFindDoesntExistReturn) {

		}

		TEST_METHOD(RBTreeKthMINFindReturn) {
		
		}

		TEST_METHOD(RBTreeKthMINFindOutOfBounds) {

		}

		TEST_METHOD(RBTreeNodeIsRedAfterInsert) {
			
		}

	private:
		RBTreeTest referenceTree;
		RBTree tree;
		

		void buildTree() {
			
			//Making tree
			
			RBTreeNodeTest zero(0);
			RBTreeNodeTest one(1);
			RBTreeNodeTest two(2);
			RBTreeNodeTest three(3);
			RBTreeNodeTest four(4);
			RBTreeNodeTest five(5);
			RBTreeNodeTest six(6);
			referenceTree.root = &three;
			zero.parent = &one;
			two.parent = &one;
			one.red = false;
			one.left = &zero;
			one.right = &two;
			one.parent = &three;
			three.red = false;
			three.left = &one;
			three.right = &five;
			five.red = false;
			five.left = &four;
			five.right = &six;
			five.parent = &three;
			four.parent = &five;
			six.parent = &five;



			// Inserting values


			// Tree Shape
			
			//				3
			//     1              5
		}//    0      2       4      6

	};
}
