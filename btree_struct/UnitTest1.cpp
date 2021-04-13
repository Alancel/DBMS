#include "btree.h"
#include "pch.h"
#include "CppUnitTest.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(TestIntCreation)
		{
			void* tmp1;

			tmp1 = 10;
			t_btree* tree;
			tree = btree_create_node(tmp1);
			Assert::AreEqual(tmp1, tree->item);
		}
		TEST_METHOD(TestIntInsertionLeft)
		{
			void* tmp1;
			void* tmp2;
			t_btree* tree;
			tmp1 = 10;
			tmp2 = 5;
			
			tree = btree_create_node(tmp1);
			btree_insert_data(&tree, tmp2, item_cmp);
			Assert::AreEqual(tmp2, tree->left->item);
		}
		TEST_METHOD(TestIntInsertionRight)
		{
			void* tmp1;
			void* tmp2;
			t_btree* tree;
			tmp1 = 10;
			tmp2 = 20;

			tree = btree_create_node(tmp1);
			btree_insert_data(&tree, tmp2, item_cmp);
			Assert::AreEqual(tmp2, tree->right->item);
		}
		TEST_METHOD(TestIntSearch)
		{
			void* tmp1;
			void* tmp2;
			void* tmp3;
			void* ans;
			t_btree* tree;


			tmp1 = 1;
			tmp2 = 2;
			tmp3 = 3;
			tree = btree_create_node(tmp1);
			btree_insert_data(tmp2);
			btree_insert_data(tmp2);
			ans = btree_search_item(tree, tmp2, item_cmp);
			Assert::AreEqual(tmp2, ans);
		}
		TEST_METHOD(TestStrCreation)
		{
			void* tmp1;

			tmp1 = "aaaa";
			t_btree* tree;
			tree = btree_create_node(tmp1);
			Assert::AreEqual(tmp1, tree->item);
		}
		TEST_METHOD(TestStrInsertionLeft)
		{
			void* tmp1;
			void* tmp2;
			t_btree* tree;
			tmp1 = "str";
			tmp2 = "str1";

			tree = btree_create_node(tmp1);
			btree_insert_data(&tree, tmp2, item_cmp);
			Assert::AreEqual(tmp2, tree->left->item);
		}
		TEST_METHOD(TestIntInsertionRight)
		{
			void* tmp1;
			void* tmp2;
			t_btree* tree;
			tmp1 = "str";
			tmp2 = "st";

			tree = btree_create_node(tmp1);
			btree_insert_data(&tree, tmp2, item_cmp);
			Assert::AreEqual(tmp2, tree->right->item);
		}
		TEST_METHOD(TestStrSearch)
		{
			void* tmp1;
			void* tmp2;
			void* tmp3;
			void* ans;
			t_btree* tree;

			tmp1 = "abc";
			tmp2 = "def";
			tmp3 = "aaa";
			tree = btree_create_node(tmp1);
			btree_insert_data(&tree, tmp2, item_cmp);
			btree_insert_data(&tree, tmp2, item_cmp);
			ans = btree_search_item(tree, tmp2, item_cmp);
			Assert::AreEqual(tmp2, ans);
		}
	};
}
