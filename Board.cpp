#include "Board.hpp"

#include <iostream>

Board::Board(int rows, int columns)
: rows(rows), columns(columns)
{
	this->board = new char[this->rows * this->columns];
	this->words = 0;

	for (int i = 0; i < columns * rows; i++)
	{
		this->board[i] = '.';
	}
}

Board::~Board()
{
	delete [] this->board;
}

void Board::insert_word(const std::string &word)
{
	// TODO
}

void Board::print_board() const
{
	for (int i = 0; i < this->rows; i++)
	{
		for (int j = 0; j < this->columns; j++)
		{
			size_t position = i * columns + j;
			std::cout << this->board[position];
		}
		std::cout << std::endl;
	}
}
