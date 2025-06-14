#include "Board.h"
using namespace std;

Board::Board()
{
    

    for (int i = 0; i < WIDTH; i++) {
        std::cout << "-";
    }
    std::cout << std::endl;
}
