#include "Trie_tree.h"

#include <algorithm>
#include <iostream>

#define CHARACTERS_NUMBER 26

TrieTree::TrieTree()
{
	this->is_word = false;
	this->character = '\0';
	this->value = nullptr;
	this->next = nullptr;
}

TrieTree::~TrieTree()
{
	if (this->next == nullptr)
	{
		delete [] this->next;
	}
}

void TrieTree::add_word(const std::string &str)
{
	std::string data(str);
	std::transform(data.begin(), data.end(), data.begin(), ::tolower);
	this->__add_word(data);	
}

void TrieTree::add_word(const std::string &str, void* value)
{
	std::string data(str);
	std::transform(data.begin(), data.end(), data.begin(), ::tolower);
	this->__add_word(data, value);	
}

bool TrieTree::check_if_word_exists(const std::string &str)
{
	std::string data(str);
	std::transform(data.begin(), data.end(), data.begin(), ::tolower);
	return this->__find_word(data);
}

bool TrieTree::__find_word(std::string &str)
{

	
	if (this->next == nullptr) 
	{
		return false;
	}

	if (this->character != str[0])
	{
		return false;
	}

	str.erase(0, 1);

    if (str.empty())
    {
        if (this->is_word) return true;
        else
        {
            return false;
        }
    }

	size_t index = str[0] - 'a';
	return this->next[index].__find_word(str);	
}

void* TrieTree::__get_value(std::string &str)
{
	
	if (this->next == nullptr) 
	{
		return nullptr;
	}

	if (this->character != str[0])
	{
		return nullptr;
	}

	str.erase(0, 1);

    if (str.empty())
    {
        if (this->is_word)
        {
            return this->value;
        }
        else
        {
            return nullptr;
        }
    }

	size_t index = str[0] - 'a';
	return this->next[index].__get_value(str);
}

void TrieTree::remove_word(const std::string &str)
{
	// TODO
}

void* TrieTree::get_value(const std::string &str)
{
	std::string data(str);
	std::transform(data.begin(), data.end(), data.begin(), ::tolower);
	return this->__get_value(data);
}

void TrieTree::__add_word(std::string &str)
{
	if (this->next == nullptr)
	{
		this->next = new TrieTree[CHARACTERS_NUMBER];
	}


	if (this->character == '\0') 
	{
		this->character = str[0];
	}
	str.erase(0, 1); // removes first character in the string

	if (str.empty())
	{
		this->is_word = true;
		return;
	}

	size_t index = str[0] - 'a'; // calculates index of pointer
	this->next[index].__add_word(str);
}

void TrieTree::__add_word(std::string &str, void *val)
{
	if (this->next == nullptr)
	{
		this->next = new TrieTree[CHARACTERS_NUMBER];
	}


	
	if (this->character == '\0') 
	{
		this->character = str[0];
	}
	str.erase(0, 1); // removes first character in the string

    if (str.empty())
    {
        this->is_word = true;
        this->value = val;
        return;
    }

	size_t index = str[0] - 'a'; // calculates index of pointer
	this->next[index].__add_word(str, val);
}

//////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////
Tree::Tree()
{
	this->tree = new TrieTree[CHARACTERS_NUMBER];
}

Tree::~Tree()
{
	delete [] this->tree;
}

void Tree::add_word(const std::string &str)
{
	std::string data(str);
	std::transform(data.begin(), data.end(), data.begin(), ::tolower);
	size_t index = data[0] - 'a';
	this->tree[index].add_word(data);
}

void Tree::add_word(const std::string &str, void *value)
{
	std::string data(str);
	std::transform(data.begin(), data.end(), data.begin(), ::tolower);
	size_t index = data[0] - 'a';
	this->tree[index].add_word(data, value);
}

bool Tree::check_if_word_exists(const std::string &str)
{
	std::string data(str);
	std::transform(data.begin(), data.end(), data.begin(), ::tolower);
	size_t index = data[0] - 'a';
	return this->tree[index].check_if_word_exists(data);
}

void Tree::remove_word(const std::string &str)
{
}

void* Tree::get_value(const std::string &str)
{
	std::string data(str);
	std::transform(data.begin(), data.end(), data.begin(), ::tolower);
	size_t index = data[0] - 'a';
	return this->tree[index].get_value(data);
}

