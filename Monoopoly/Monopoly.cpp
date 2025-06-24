#include "Monopoly.h"


void Monopoly::playersInput()
{
	std::cout << "Insert the number of players (2-6): \n";

	int playersCount;
	std::cin >> playersCount;

	if (playersCount < 2 || playersCount > 6) {
		throw std::invalid_argument("Invalid number of players.Please enter a number between 2 and 6.");
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
			std::cout << "Player " << (i + 1) << std::endl;
			turn(players[i],i);
		}
		std::cout << std::endl;
		for (int i = 0; i < players.getSize(); i++) {
			std::cout << players[i] << "\n";
		}
	} while (!isGameOver);
	std::cout << "Game over! Thanks for playing!\n";
	std::cout << "Winner: " << players[0].getName() << "\n"; 
}

void Monopoly::turn(Player& player, size_t i)
{
	int rollCount = 0;
	int moveCount = 0;

	do {
		rollCount = 0;
		moveCount = 0;

		system("pause");
		system("cls");

		// Задължителен начален roll_dice
	again_roll:
		std::cout << "Insert command (must be roll_dice):\n> ";
		MyString command;
		std::cin >> command;

		if (command != "roll_dice") {
			std::cout << "You must roll the dice first!\n";
			goto again_roll;
		}

		Command* cmd = CommandFactory::createCommand(command, *this, i);
		if (cmd) {
			cmd->execute();
			rollCount++;
		}
		else {
			std::cout << "Invalid command.\n";
			goto again_roll;
		}
		std::cout << "Rolled: " << dice.getFirstDie() << " and " << dice.getSecondDie() << "\n";
		std::cout << "Position: " << players[i].getPosition() << "\n";

		MyString postCommand;
		do {
		again_command:
			std::cout << "Insert command:\n> ";
			std::cin >> postCommand;

			if (postCommand == "roll_dice") {
				std::cout << "You have already rolled the dice this turn!\n";
				goto again_command;
			}

			if (postCommand == "move") {
				if (moveCount >= rollCount) {
					std::cout << "You can't move more than you've rolled!\n";
					goto again_command;
				}
				moveCount++;
			}

			if (postCommand == "end") {
				if (moveCount < rollCount) {
					std::cout << "You must move before ending your turn!\n";
					goto again_command;
				}
				break; 
			}

			Command* postCmd = CommandFactory::createCommand(postCommand, *this, i);
			if (postCmd) {
				postCmd->execute();
				std::cout << "Position: " << players[i].getPosition() << "\n";
			}
			else {
				std::cout << "Invalid command.\n";
			}

		} while (true); // докато не се въведе валидна команда за движение или край на хода

		system("pause");
		system("cls");
		drawBoard();
		drawPlayersOnBoard();

	} while (dice.getFirstDie() == dice.getSecondDie()); // ако има двойка → нов ход
}


void Monopoly::acrossStart(Player& player, size_t prePos, size_t afterPos)
{
	if(afterPos < prePos)
		player.setMoney(player.getMoney() + 200);
}

void Monopoly::test()
{
	players[0].setPosition(1);
	fields[1]->applyEffect(players[0]);
	//bank.buyCottage(&players[0], "Mediterranean Avenue");
	players[0].setPosition(3);
	fields[3]->applyEffect(players[0]);
	bank.buyCottage(&players[0], "Mediterranean Avenue");
}

Dice& Monopoly::getDice()
{
	return dice;
}

Player& Monopoly::getPlayer(size_t index)
{
	return players[index];
}

Fields& Monopoly::getFields()
{
	return fields;
}

Bank& Monopoly::getBank()
{
	return bank;
}

void Monopoly::isGameFinished()
{
	if (players.getSize() <= 1)
		isGameOver = true;
}

void Monopoly::removePlayer(size_t index)
{
	if (index < players.getSize())
		players.erase(index);
}

