#include <gtest/gtest.h>

#include "../Trie_tree.h"

#include <iostream>
#include <vector>

struct costam {
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

	std::vector<std::string> test_vector;		
	test_vector.push_back(s1);
	test_vector.push_back(s2);
	test_vector.push_back(s3);
	test_vector.push_back(s4);
	test_vector.push_back(s5);
	test_vector.push_back(s6);
	test_vector.push_back(s7);

	Tree tree;

	for (const auto &s : test_vector)
	{
		tree.add_word(s);
	}


	EXPECT_TRUE(true == tree.check_if_word_exists(s1));
	EXPECT_TRUE(true == tree.check_if_word_exists(s2));
	EXPECT_TRUE(true == tree.check_if_word_exists(s3));
	EXPECT_TRUE(true == tree.check_if_word_exists(s4));
	EXPECT_TRUE(true == tree.check_if_word_exists(s5));
	EXPECT_TRUE(true == tree.check_if_word_exists(s6));
	EXPECT_TRUE(true == tree.check_if_word_exists(s7));
	EXPECT_TRUE(false == tree.check_if_word_exists(s8));
}

TEST(Trie_tree_test, insertWordAndValue)
{
	const std::string s1 = "mleko";
	const std::string s2 = "mleczny";

	//int val1 = 0x4141;
	//int val2 = 0x4343;

	costam val1 = {
		.a = 15,
		.b = 29
	};
	costam val2 = {
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

	costam rr1 = *(costam*)r1;
	costam rr2 = *(costam*)r2;

	std::cout << "STRUCT 1 a: " << rr1.a << " b: " << rr1.b << std::endl;
	std::cout << "STRUCT 2 a: " << rr2.a << " b: " << rr2.b << std::endl;

	ASSERT_EQ(r1, &val1);
	ASSERT_EQ(r2, &val2);
}
