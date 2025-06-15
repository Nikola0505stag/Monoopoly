#pragma once
#include "Fields.h"
#include <windows.h>

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
		const char text[], WORD fg, WORD bg);
	void gotoxy(int x, int y) const;
	void setColor(WORD fg, WORD bg = 0) const;
};