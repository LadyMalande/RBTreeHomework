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
		
		TEST_METHOD(RBTreeConstructorTest)
		{
			RBTreeNode firstNode = RBTreeNode(1);
			RBTree tree = RBTree(&firstNode);
			Assert::AreEqual(1, tree.root->key);
		}
	};
}
