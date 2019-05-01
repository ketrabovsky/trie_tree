#pragma once

#include <string>

class TrieTree
{
private:
	TrieTree *next; // this length will be 26 because there is 26 characters in the alphabet
	bool is_word;
	char character;
	void *value;


	// private methods
	void __add_word(std::string &str);
	void __add_word(std::string &str, void *value);
	bool __find_word(std::string &str);
	void* __get_value(std::string &str);

public:
	TrieTree();
	~TrieTree();
	void add_word(const std::string &str);
	void add_word(const std::string &str, void *value);
	bool check_if_word_exists(const std::string &str);
	void remove_word(const std::string &str);
	void* get_value(const std::string &str);
};

class Tree
{
private:
	TrieTree *tree;
public:
	Tree();
	~Tree();
	void add_word(const std::string &str);
	void add_word(const std::string &str, void *value);
	bool check_if_word_exists(const std::string &str);
	void remove_word(const std::string &str);
	void* get_value(const std::string &str);
};
