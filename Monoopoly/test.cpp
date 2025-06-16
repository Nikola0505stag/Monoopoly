#include "MyQueue.hpp"
#include "MyVector.hpp"
#include "MyString.h"
#include "Player.h"
#include "MovePositionCard.h"
#include "PaymentCard.h"
#include "GroupPaymentCard.h"
#include "Deck.h"
#include "Field.h"
#include "Property.h"
#include "CardField.h"
#include <iostream>
#include "Jail.h"
#include "StartField.h"
#include "Parking.h"
#include "Fields.h"
#include "GoJail.h"
#include "Board.h"
#include "Dice.h"

using namespace std;

int main() {

	Player players[3];
	players[0].setName("Player1");
	players[1].setName("Player2");
	players[2].setName("Player3");

	//cout << players[0] << endl;
	//cout << players[1] << endl;
	//cout << players[2] << endl;

	Deck deck;
	deck.fillDeck(3, players);
	deck.shuffle();
	//deck.printDeck();

	Fields fields;
	fields.setDeck(&deck);
	fields.fillFields();
	//cout << endl << endl;
	//cout << endl << endl;
	//fields.printFields();

	////fields[39]->applyEffect(players[0]);
	////cout << endl << endl;
	////cout << players[0] << endl;
	////cout << players[1] << endl;
	////cout << players[2] << endl;

	//cout << endl << endl;
	//Dice dice;
	//dice.rollingADice();
	//cout << dice.getSum();
	//
	//players[0].setPosition(players[0].getPosition() + dice.getSum());

	//cout << players[0] << endl;
	//cout << players[1] << endl;
	//cout << players[2] << endl;

	//fields[players[0].getPosition()]->applyEffect(players[0]);
	//cout << players[0] << endl;
	//cout << players[1] << endl;
	//cout << players[2] << endl;


	Board board;
	board.setFields(&fields);
	//board.printBoard();
	const int n = 11, cellSize = 10;
	board.drawGrid(n, cellSize);
	//board.gotoxy(0, 0);
	board.writeInCell(10,10, cellSize, "Start", 10, 0);

	cin.get();
	//board.gotoxy(0, 71);

	return 0;
}