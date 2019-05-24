#pragma once

#include <string>

class Board
{
private:

	char *board;
	int rows;
	int columns;
	int words;
public:
	Board(int rows, int columns);	
	~Board();
	void insert_word(const std::string &word);
	void print_board() const;
};
