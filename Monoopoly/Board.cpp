#include "Board.h"

Board::Board()
{
	fields.fillFields();
}

void Board::printBoard() const
{
	std::cout << "--------------------\n";
	std::cout << "|                  |\n";
	std::cout << "|                  |\n";
	std::cout << "|                  |\n";
	std::cout << "|                  |\n";
	std::cout << "|                  |\n";
	std::cout << "|                  |\n";
	std::cout << "|                  |\n";
	std::cout << "|                  |\n";
	std::cout << "|                  |\n";
	std::cout << "--------------------\n";
}
