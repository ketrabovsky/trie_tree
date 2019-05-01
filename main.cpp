#include "Trie_tree.h"
#include <string>
#include <iostream>

int main()
{
	const std::string s1 = "mleko";
	const std::string s2 = "mleczny";
	const std::string s3 = "mlekowy";
	const std::string s4 = "kolo";

	Tree tree;

	tree.add_word(s1);
	tree.add_word(s2);
	tree.add_word(s3);
	tree.add_word(s4);
	return 0;
}
