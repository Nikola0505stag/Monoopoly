#pragma once
#include "Player.h"
#include "Deck.h"
#include "Fields.h"
#include "Dice.h"
#include "MyVector.hpp"
#include "Board.h"

class GameManager
{
	MyVector<Player> players;
	Deck deck;
	Fields fields;
	Dice dice;
	Board board;

public:

	GameManager();
	//GameManager(const Deck& deck, const Fields& fields, const Dice& dice, const Board& board);
};

