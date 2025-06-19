#include "Monopoly.h"


void Monopoly::playersInput()
{
	std::cout << "Insert the number of players (2-6): \n";

	int playersCount;
	std::cin >> playersCount;

	if (playersCount < 2 || playersCount > 6) {
		throw std::invalid_argument("Invalid number of players."
			" Please enter a number between 2 and 6.");
	}

	for (int i = 0; i < playersCount; i++) {
		MyString number;
		number = number.intToMyString(i + 1);
		//std::cout << number;
		MyString name = "Player " + number;
		//std::cout << name << "\n";

		players.push_back(Player(name));
	}

	//for (int i = 0; i < players.getSize(); i++) {
	//	std::cout << players[i] << "\n";
	//}
}

void Monopoly::makeGame()
{
	Player* playersArray = new Player[players.getSize()];

	for (int i = 0; i < players.getSize(); i++) {
		playersArray[i] = players[i];
	}

	//for (int i = 0; i < players.getSize(); i++) {
	//	std::cout << "in \t";
	//	std::cout << playersArray[i] << "\n";
	//}
	deck.fillDeck(players.getSize(), playersArray);
	deck.shuffle();
	deck.printDeck();
	
	fields.setDeck(&deck);
	fields.fillFields();
	std::cout << std::endl;
	fields.printFields();
	
	board.setFields(&fields);
}

void Monopoly::drawBoard()
{
	const int n = 11, cellSize = 10;
	board.drawGrid(n, cellSize);
	board.fillCells();

	board.moveCursorToBottom();
}

void Monopoly::drawPlayersOnBoard()
{

	for (int i = 0; i < players.getSize(); i++) {
		board.showPlayer(&players[i]);
	}
	board.moveCursorToBottom();
}

void Monopoly::start()
{
	turn(players[0]);
}

void Monopoly::turn(Player& player)
{
	
	do {
		std::cout << std::endl;
		dice.rollingADice();
		std::cout << dice.getFirstDie() << " " << dice.getSecondDie() << "\n";
		player.move(&dice);

		std::cout << std::endl;
		fields[player.getPosition()]->print();
		fields[player.getPosition()]->applyEffect(player);
	} while (dice.getFirstDie() == dice.getSecondDie());
}

