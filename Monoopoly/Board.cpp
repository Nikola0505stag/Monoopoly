
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

void Board::fillCells() const
{
    MyVector<MyString> curr;


   

    //colorCell(10, 10, CELL_SIZE, 0, 15);
    
    colorCell(9, 10, CELL_SIZE, 15, 0);
    curr.push_back("Med...");
    curr.push_back("Avenue");
    curr.push_back("Price:60$");
    writeMultilineInCell(9, 10, CELL_SIZE, curr, 15, 0);
    curr.clear();

    colorCell(8, 10, CELL_SIZE, 0, 15);
    curr.push_back("Draw");
    curr.push_back("Card");
    writeMultilineInCell(8, 10, CELL_SIZE, curr, 0, 15);
    curr.clear();

    colorCell(7, 10, CELL_SIZE, 15, 0);
    curr.push_back("Baltic");
    curr.push_back("Avenue");
    curr.push_back("Price:60$");
    writeMultilineInCell(7, 10, CELL_SIZE, curr, 15, 0);
    curr.clear();

    colorCell(6, 10, CELL_SIZE, 0, 15);
    curr.push_back("Draw");
    curr.push_back("Card");
    writeMultilineInCell(6, 10, CELL_SIZE, curr, 0, 15);
    curr.clear();

    colorCell(5, 10, CELL_SIZE, 0, 15);
    curr.push_back("Red");
    curr.push_back("Van");
    curr.push_back("Price:200$");
    writeMultilineInCell(5, 10, CELL_SIZE, curr, 0, 15);
    curr.clear();

    colorCell(4, 10, CELL_SIZE, 0, 9);
    curr.push_back("Oriental");
    curr.push_back("Avenue");
    curr.push_back("Price:100$");
    writeMultilineInCell(4, 10, CELL_SIZE, curr, 0, 9);
    curr.clear();

    colorCell(3, 10, CELL_SIZE, 0, 15);
    curr.push_back("Draw");
    curr.push_back("Card");
    writeMultilineInCell(3, 10, CELL_SIZE, curr, 0, 15);
    curr.clear();

    colorCell(2, 10, CELL_SIZE, 0, 9);
    curr.push_back("Vermont");
    curr.push_back("Avenue");
    curr.push_back("Price:100$");
    writeMultilineInCell(2, 10, CELL_SIZE, curr, 0, 9);
    curr.clear();

    colorCell(1, 10, CELL_SIZE, 0, 9);
    curr.push_back("Conn...");
    curr.push_back("Avenue");
    curr.push_back("Price:120$");
    writeMultilineInCell(1, 10, CELL_SIZE, curr, 0, 9);
    curr.clear();

    colorCell(0, 10, CELL_SIZE, 0, 15);
    writeInCell(0, 10, CELL_SIZE, "Jail", 0, 15);

    colorCell(0, 9, CELL_SIZE, 0, 13);
    curr.push_back("St");
    curr.push_back("Charles");
    curr.push_back("Place");
    curr.push_back("Price:140$");
    writeMultilineInCell(0, 9, CELL_SIZE, curr, 0, 13);
    curr.clear();

    colorCell(0, 8, CELL_SIZE, 0, 15);
    curr.push_back("Draw");
    curr.push_back("Card");
    writeMultilineInCell(0, 8, CELL_SIZE, curr, 0, 15);
    curr.clear();

    colorCell(0, 7, CELL_SIZE, 0, 13);
    curr.push_back("States");
    curr.push_back("Avenue");
    curr.push_back("Price:140$");
    writeMultilineInCell(0, 7, CELL_SIZE, curr, 0, 13);
    curr.clear();

    colorCell(0, 6, CELL_SIZE, 0, 13);
    curr.push_back("Virginia");
    curr.push_back("Avenue");
    curr.push_back("Price:160$");
    writeMultilineInCell(0, 6, CELL_SIZE, curr, 0, 13);
    curr.clear();

    colorCell(0, 5, CELL_SIZE, 0, 15);
    curr.push_back("Silver");
    curr.push_back("Van");
    curr.push_back("Price:200$");
    writeMultilineInCell(0, 5, CELL_SIZE, curr, 0, 15);
    curr.clear();

    colorCell(0, 4, CELL_SIZE, 0, 3);
    curr.push_back("St.");
    curr.push_back("James");
    curr.push_back("Place");
    curr.push_back("Price:180$");
    writeMultilineInCell(0, 4, CELL_SIZE, curr, 0, 3);
    curr.clear();

    colorCell(0, 3, CELL_SIZE, 0, 15);
    curr.push_back("Draw");
    curr.push_back("Card");
    writeMultilineInCell(0, 3, CELL_SIZE, curr, 0, 15);
    curr.clear();

    colorCell(0, 2, CELL_SIZE, 0, 3);
    curr.push_back("Columbia");
    curr.push_back("Avenue");
    curr.push_back("Price:180$");
    writeMultilineInCell(0, 2, CELL_SIZE, curr, 0, 3);
    curr.clear();

    colorCell(0, 1, CELL_SIZE, 0, 3);
    curr.push_back("New York");
    curr.push_back("Avenue");
    curr.push_back("Price:200$");
    writeMultilineInCell(0, 1, CELL_SIZE, curr, 0, 3);
    curr.clear();

    colorCell(0, 0, CELL_SIZE, 0, 15);
    writeInCell(0, 0, CELL_SIZE, "Parking", 0, 15);

    colorCell(1, 0, CELL_SIZE, 0, 4);
    curr.push_back("Kentucky");
    curr.push_back("Avenue");
    curr.push_back("Price:220$");
    writeMultilineInCell(1, 0, CELL_SIZE, curr, 0, 4);
    curr.clear();

    colorCell(2, 0, CELL_SIZE, 0, 15);
    curr.push_back("Draw");
    curr.push_back("Card");
    writeMultilineInCell(2, 0, CELL_SIZE, curr, 0, 15);
    curr.clear();

    colorCell(3, 0, CELL_SIZE, 0, 4);
    curr.push_back("Indiana");
    curr.push_back("Avenue");
    curr.push_back("Price:220$");
    writeMultilineInCell(3, 0, CELL_SIZE, curr, 0, 4);
    curr.clear();

    colorCell(4, 0, CELL_SIZE, 0, 4);
    curr.push_back("Illinois");
    curr.push_back("Avenue");
    curr.push_back("Price:240$");
    writeMultilineInCell(4, 0, CELL_SIZE, curr, 0, 4);
    curr.clear();

    colorCell(5, 0, CELL_SIZE, 0, 15);
    curr.push_back("White");
    curr.push_back("Van");
    curr.push_back("Price:200$");
    writeMultilineInCell(5, 0, CELL_SIZE, curr, 0, 15);
    curr.clear();

    colorCell(6, 0, CELL_SIZE, 0, 14);
    curr.push_back("Atlantic");
    curr.push_back("Avenue");
    curr.push_back("Price:260$");
    writeMultilineInCell(6, 0, CELL_SIZE, curr, 0, 14);
    curr.clear();

    colorCell(7, 0, CELL_SIZE, 0, 14);
    curr.push_back("Ventnor");
    curr.push_back("Avenue");
    curr.push_back("Price:260$");
    writeMultilineInCell(7, 0, CELL_SIZE, curr, 0, 14);
    curr.clear();

    colorCell(8, 0, CELL_SIZE, 0, 15);
    curr.push_back("Draw");
    curr.push_back("Card");
    writeMultilineInCell(8, 0, CELL_SIZE, curr, 0, 15);
    curr.clear();

    colorCell(9, 0, CELL_SIZE, 0, 14);
    curr.push_back("Marvin");
    curr.push_back("Gardens");
    curr.push_back("Price:270$");
    writeMultilineInCell(9, 0, CELL_SIZE, curr, 0, 14);
    curr.clear();

    colorCell(10, 0, CELL_SIZE, 0, 15);
    curr.push_back("Go to");
    curr.push_back("Jail");
    writeMultilineInCell(10, 0, CELL_SIZE, curr, 0, 15);
    curr.clear();

    colorCell(10, 1, CELL_SIZE, 0, 2);
    curr.push_back("Pacific");
    curr.push_back("Avenue");
    curr.push_back("Price:300$");
    writeMultilineInCell(10, 1, CELL_SIZE, curr, 0, 2);
    curr.clear();

    colorCell(10, 2, CELL_SIZE, 0, 2);
    curr.push_back("North");
    curr.push_back("Carolina");
    curr.push_back("Avenue");
    curr.push_back("Price:300$");
    writeMultilineInCell(10, 2, CELL_SIZE, curr, 0, 2);
    curr.clear();

    colorCell(10, 3, CELL_SIZE, 0, 15);
    curr.push_back("Draw");
    curr.push_back("Card");
    writeMultilineInCell(10, 3, CELL_SIZE, curr, 0, 15);
    curr.clear();

    colorCell(10, 4, CELL_SIZE, 0, 2);
    curr.push_back("Pennsyl...");
    curr.push_back("Avenue");
    curr.push_back("Price:300$");
    writeMultilineInCell(10, 4, CELL_SIZE, curr, 0, 2);
    curr.clear();

    colorCell(10, 5, CELL_SIZE, 0, 15);
    curr.push_back("Black");
    curr.push_back("Van");
    curr.push_back("Price:200$");
    writeMultilineInCell(10, 5, CELL_SIZE, curr, 0, 15);
    curr.clear();

    colorCell(10, 6, CELL_SIZE, 0, 15);
    curr.push_back("Draw");
    curr.push_back("Card");
    writeMultilineInCell(10, 6, CELL_SIZE, curr, 0, 15);
    curr.clear();

    colorCell(10, 7, CELL_SIZE, 0, 1);
    curr.push_back("Park");
    curr.push_back("Place");
    curr.push_back("Price:350$");
    writeMultilineInCell(10, 7, CELL_SIZE, curr, 0, 1);
    curr.clear();

    colorCell(10, 8, CELL_SIZE, 0, 15);
    curr.push_back("Draw");
    curr.push_back("Card");
    writeMultilineInCell(10, 8, CELL_SIZE, curr, 0, 15);
    curr.clear();

    colorCell(10, 9, CELL_SIZE, 0, 1);
    curr.push_back("Boardwalk");
    curr.push_back("Price:400$");
    writeMultilineInCell(10, 9, CELL_SIZE, curr, 0, 1);
    curr.clear();

    colorCell(10, 10, CELL_SIZE, 0, 15);
    writeInCell(10, 10, CELL_SIZE, "Start", 0, 15);

    cout << endl;
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
    const char text[], WORD fg, WORD bg) const {
    int cellHeight = cellSize / 3;

    int x = cellX * (cellSize) + (cellSize - strlen(text)) / 2 + 1;
    int y = cellY * (cellHeight + 1) + cellHeight / 2 + 1;

    gotoxy(x, y);
    setColor(fg, bg);
    std::cout << text;
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

void Board::writeMultilineInCell(int cellX, int cellY, int cellSize,
    const MyVector<MyString>& lines, WORD fg, WORD bg) const {

    int cellHeight = cellSize / 3;
    int topLeftX = cellX * (cellSize) + 1;
    int topLeftY = cellY * (cellHeight + 1) + 1;

    int totalLines = lines.getSize();

    // Центрираме вертикално
    int startLine = (cellHeight - totalLines) / 2;
    if (startLine < 0) startLine = 0;

    for (int i = 0; i < totalLines; ++i) {
        int lineLength = lines[i].getSize();
        if (lineLength > cellSize - 2) lineLength = cellSize - 2;

        int x = topLeftX + (cellSize - lineLength) / 2;
        int y = topLeftY + startLine + i;

        gotoxy(x, y);
        setColor(fg, bg);
        std::cout << lines[i];
    }

    setColor(7, 0); // reset
}

void Board::colorCell(int cellX, int cellY, int cellSize, WORD fg, WORD bg) const {
    int cellHeight = cellSize / 3;

    // Горен ляв ъгъл на клетката (вътре в рамката)
    int startX = cellX * (cellSize) + 1;
    int startY = cellY * (cellHeight + 1) + 1;

    setColor(fg, bg);

    for (int y = 0; y < cellHeight; ++y) {
        gotoxy(startX, startY + y);
        for (int x = 0; x < cellSize - 1; ++x) {
            std::cout << " ";
        }
    }

    setColor(7, 0); // reset to default (бял текст, черен фон)
}



