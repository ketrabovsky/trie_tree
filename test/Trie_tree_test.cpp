#include <gtest/gtest.h>

#include "../Trie_tree.h"

#include <iostream>
#include <vector>

struct Point {
	int a;
	int b;
};

TEST(Trie_tree_test, insertWordAndCheck)
{
	const std::string s1 = "mleko";
	const std::string s2 = "mleczny";
	const std::string s3 = "mlekowy";
	const std::string s4 = "kolo";
	const std::string s5 = "komar";
	const std::string s6 = "mleczarz";
	const std::string s7 = "potomek";
	const std::string s8 = "pot";
	const std::string s9 = "pota";
	const std::string s10 = "muszkieter";
	const std::string s11 = "muszkiet";

	std::vector<std::string> test_vector;		
	test_vector.push_back(s1);
	test_vector.push_back(s2);
	test_vector.push_back(s3);
	test_vector.push_back(s4);
	test_vector.push_back(s5);
	test_vector.push_back(s6);
	test_vector.push_back(s7);
	test_vector.push_back(s10);
	test_vector.push_back(s11);

	Tree tree;

	for (const auto &s : test_vector)
	{
		tree.add_word(s);
	}

	EXPECT_TRUE(tree.check_if_word_exists(s1));
	EXPECT_TRUE(tree.check_if_word_exists(s2));
	EXPECT_TRUE(tree.check_if_word_exists(s3));
	EXPECT_TRUE(tree.check_if_word_exists(s4));
	EXPECT_TRUE(tree.check_if_word_exists(s5));
	EXPECT_TRUE(tree.check_if_word_exists(s6));
	EXPECT_TRUE(tree.check_if_word_exists(s7));
	EXPECT_TRUE(tree.check_if_word_exists(s10));
	EXPECT_TRUE(tree.check_if_word_exists(s11));

	EXPECT_FALSE(tree.check_if_word_exists(s8));
	EXPECT_FALSE(tree.check_if_word_exists(s9));
}

TEST(Trie_tree_test, insertWordAndValue)
{
	const std::string s1 = "mleko";
	const std::string s2 = "mleczny";

	Point val1 = {
		.a = 15,
		.b = 29
	};
	Point val2 = {
		.a = 30,
		.b = 49
	};
	void *v1 = &val1;
	void *v2 = &val2;

	Tree tree;

	tree.add_word(s1, v1);
	tree.add_word(s2, v2);

	EXPECT_TRUE(true == tree.check_if_word_exists(s1));
	EXPECT_TRUE(true == tree.check_if_word_exists(s2));

	void *r1 = tree.get_value(s1);
	void *r2 = tree.get_value(s2);

	ASSERT_FALSE(nullptr == r1);
	ASSERT_FALSE(nullptr == r2);

	auto rr1 = *(Point*)r1;
	auto rr2 = *(Point*)r2;

	ASSERT_EQ(r1, &val1);
	ASSERT_EQ(r2, &val2);
}
