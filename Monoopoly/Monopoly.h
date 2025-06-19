#pragma once
#include "MyVector.hpp"
#include "Player.h"
#include "Deck.h"
#include "Fields.h"
#include "Dice.h"
#include "Board.h"

class Monopoly
{
	MyVector<Player> players;
	Deck deck;
	Fields fields;
	Dice dice;
	Board board;

	bool pair();

	//void vectorToArray(Player* playersArray);
public:
	void playersInput();
	void makeGame();
	void drawBoard();
	void drawPlayersOnBoard();
	void start();
	void turn(Player& player);
};

