#pragma once
#include "Fields.h"
#include <windows.h>
#include "MyVector.hpp"
#include "MyString.h"
//#include <iostream>
#define CELL_SIZE 10

class Board
{
	Fields* fields = nullptr;

public:
	Board();

	void setFields(Fields* fields);
	Fields* getFields() const;

	void printBoard() const;

	void drawGrid(int n, int cellSize);
	void writeInCell(int cellX, int cellY, int cellSize,
		const char text[], WORD fg, WORD bg) const;
	void gotoxy(int x, int y) const;
	void setColor(WORD fg, WORD bg = 0) const;
	void fillCells() const;

	void writeMultilineInCell(int cellX, int cellY, int cellSize,
		const MyVector<MyString>& lines,
		WORD fg, WORD bg) const;
	void colorCell(int cellX, int cellY, int cellSize, WORD fg, WORD bg) const;

	void showPlayer(Player* player);

	void moveCursorToBottom() const;

	void colorCellPerson(int cellX, int cellY, int cellSize, WORD fg, WORD bg) const;
};
