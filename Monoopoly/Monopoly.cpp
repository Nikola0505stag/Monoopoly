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
	//Player* playersArray = new Player[players.getSize()];

	Player* playerArray = &players[0];

	deck.fillDeck(players.getSize(), playerArray);

	deck.shuffle();
	deck.printDeck();
	
	fields.setDeck(&deck);
	fields.fillFields();
	std::cout << std::endl;
	fields.printFields();
	
	board.setFields(&fields);
	bank.setFields(&fields);
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
	do {
		system("pause");
		system("cls");
		for (int i = 0; i < players.getSize(); i++) {
			//std::cout << "Player " << (i + 1) << std::endl;
			turn(players[i]);
		}
		std::cout << std::endl;
		for (int i = 0; i < players.getSize(); i++) {
			std::cout << players[i] << "\n";
		}
	} while (!isGameOver);
}

void Monopoly::turn(Player& player)
{
	
	do {
		system("pause");
		system("cls");

		std::cout << std::endl;
		std::cout << player.getName() << "'s turn.\n";
		dice.rollingADice();
		std::cout << dice.getFirstDie() << " " << dice.getSecondDie() << "\n";
		player.move(&dice);

		system("pause");
		system("cls");
		drawBoard();
		drawPlayersOnBoard();

		std::cout << std::endl;
		fields[player.getPosition()]->print();
		fields[player.getPosition()]->applyEffect(player);
	} while (dice.getFirstDie() == dice.getSecondDie());
}

void Monopoly::acrossStart(Player& player, size_t prePos, size_t afterPos)
{
	if(afterPos < prePos)
		player.setMoney(player.getMoney() + 200);
}

void Monopoly::test()
{
	std::cout << "Insert command:\n";
	MyString command;
	std::cout << ">";
	std::cin >> command;

	Command* cmd = CommandFactory::createCommand(command,*this);
	if (cmd) {
		cmd->execute();
		std::cout << dice.getFirstDie() << dice.getSecondDie() << "\n";
	}
	else {
		std::cout << "Invalid command.\n";
	}

}

Dice& Monopoly::getDice()
{
	return dice;
}

