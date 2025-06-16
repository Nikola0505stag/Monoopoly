
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
    std::cout << char(218); // горен ляв ъгъл
    for (int i = 1; i < n * cellSize; i++) {
        if (i % cellSize == 0)
            std::cout << char(194); // T - линия
        else
            std::cout << char(196);
    }
    std::cout << char(191) << std::endl; // горен десен ъгъл
    for (int j = 0; j < cellSize / 3; j++) {
        for (int i = 0; i <= n * cellSize; i++) {
            if (i % cellSize == 0)
                std::cout << char(179); // вертикална линия
            else
                std::cout << " ";
        }
        std::cout << std::endl;
    }



    std::cout << char(195); // Т-образна лява
    for (int i = 1; i < n * cellSize; i++) {
        if (i % cellSize == 0 && i != cellSize && i != n * cellSize - cellSize)
            std::cout << char(193);//Т-образна долна
		else if (i != cellSize && i != n * cellSize - cellSize)
			std::cout << char(196); // хоризонтална линия
		else
		    std::cout << char(197); // Централна връзка
    }
	std::cout << char(180) << std::endl; // Т-образна дясна
    for (int q = 0; q < n - 3; q++) {
        for (int j = 0; j < cellSize / 3; j++) {
            for (int i = 0; i <= n * cellSize; i++) {
                if (i != cellSize && i != n * cellSize - cellSize && i != 0 && i != n * cellSize)
                    std::cout << " ";
                else
                    std::cout << char(179); // Вертикална линия
            }
            std::cout << std::endl;
        }

        std::cout << char(195); // Т - образна дясна
        for (int i = 0; i < n * cellSize; i++) {
            if (i < cellSize - 1 || i >(n - 1) * cellSize - 1 && i != n * cellSize - 1)
                std::cout << char(196); // Хоризонтална линия
            else if (i == cellSize - 1)
                std::cout << char(180); //	Т-образна дясна
            else if (i == (n - 1) * cellSize - 1)
                std::cout << char(195); // Т - образна дясна
            else if (i == n * cellSize - 1)
                std::cout << char(180); // Т-образна дясна
            else
                std::cout << " ";
        }
        std::cout << std::endl;

    }
    for (int j = 0; j < cellSize / 3; j++) {
        for (int i = 0; i <= n * cellSize; i++) {
            if (i == 0 || i == cellSize || i == (n - 1) * cellSize || i == n * cellSize)
                std::cout << char(179); // Вертикална линия
            else
                std::cout << " ";
        }
        std::cout << std::endl;
    }
   
    for (int i = 0; i <= cellSize * n; i++) {
        if (i == cellSize || i == (n - 1) * cellSize)
            cout << char(197); // Хоризонтална линия
        else if (i == 0)
            cout << char(195); // Т-образна лява
        else if (i == n * cellSize)
            cout << char(180); // Т-образна дясна
        else if (i % cellSize == 0)
            cout << char(194); //Т-образна горна
        else std::cout << char(196); // Хоризонтална линия
    }
    cout << endl;

    for (int j = 0; j < cellSize / 3; j++) {
        for (int i = 0; i <= n * cellSize; i++) {
            if (i % cellSize == 0)
				std::cout << char(179); // Вертикална линия
            else
                cout << " ";

        }
        std::cout << std::endl;
    }
   for (int i = 0; i <= n * cellSize; i++) {
        if (i == 0)
            std::cout << char(192); // долен ляв ъгъл
        else if (i == n * cellSize)
			std::cout << char(217); // долен десен ъгъл
        else if (i % cellSize == 0) 
			std::cout << char(193); // Т-образна долна
        else 
			std::cout << char(196); // долна хоризонтална линия
    }
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