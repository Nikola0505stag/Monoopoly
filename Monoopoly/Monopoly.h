#pragma once
#include "MyVector.hpp"
#include "Player.h"
#include "Deck.h"
#include "Fields.h"
#include "Dice.h"
#include "Board.h"
#include "Bank.h"
#include "CommandFactory.h"

class Monopoly
{
	MyVector<Player> players;
	Deck deck;
	Fields fields;
	Dice dice;
	Board board;
	Bank bank;

	bool isGameOver = false;

	bool pair();

	//void vectorToArray(Player* playersArray);
public:
	void playersInput();
	void makeGame();
	void drawBoard();
	void drawPlayersOnBoard();
	void start();
	void turn(Player& player, size_t i);

	void acrossStart(Player& player,size_t prePos, size_t afterPos);

	void test();

	Dice& getDice();
	Player& getPlayer(size_t index);
	Fields& getFields();
	Bank& getBank();
};

