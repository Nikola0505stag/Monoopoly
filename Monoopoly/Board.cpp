#include "Board.h"
using namespace std;

void Board::gotoxy(int x, int y) const
{
	COORD c{ (SHORT)x , (SHORT)y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c);
}

void Board::setColor(WORD fg, WORD bg) const
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), fg | (bg << 4));
}

void Board::drawGrid(int n, int cellSize) {
    gotoxy(0, 0);
    // Горен край
    std::cout << '┌';
    for (int col = 0; col < n; ++col) {
        for (int i = 0; i < cellSize; ++i) std::cout << '─';
        std::cout << (col < n - 1 ? '┬' : '┐');
    }
    std::cout << "\n";

    for (int row = 0; row < n; ++row) {
        // Вътрешни редове на клетката
        for (int line = 0; line < cellSize; ++line) {
            std::cout << '│';
            for (int col = 0; col < n; ++col) {
                for (int i = 0; i < cellSize; ++i) std::cout << ' ';
                std::cout << '│';
            }
            std::cout << "\n";
        }
        if (row < n - 1) {
            std::cout << '├';
            for (int col = 0; col < n; ++col) {
                for (int i = 0; i < cellSize; ++i) std::cout << '─';
                std::cout << (col < n - 1 ? '┼' : '┤');
            }
            std::cout << "\n";
        }
    }
    std::cout << '└';
    for (int col = 0; col < n; ++col) {
        for (int i = 0; i < cellSize; ++i) std::cout << '─';
        std::cout << (col < n - 1 ? '┴' : '┘');
    }
    std::cout << "\n";
}

void Board::writeInCell(int cellX, int cellY, int cellSize,
    const char text[], WORD fg, WORD bg) {
    int x = cellX * (cellSize + 1) + 1;
    int y = cellY * (cellSize + 1) + cellSize / 2;
    gotoxy(x, y);
    setColor(fg, bg);
    // Извеждаме всеки символ от C-style низа
    for (size_t i = 0; i < strlen(text); ++i) {
        std::cout << text[i];
    }
    setColor(7, 0);
}


Board::Board()
{
    fields = nullptr;
}

void Board::setFields(Fields* fields)
{
    this->fields = fields;
}

Fields* Board::getFields() const
{
    return fields;
}

void Board::printBoard() const
{
	if (fields == nullptr) {
		cout << "Fields are not set." << endl;
		return;
	}

	fields->printFields();
	
}
