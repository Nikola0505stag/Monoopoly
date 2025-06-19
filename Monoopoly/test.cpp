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

	Deck deck;
	deck.fillDeck(3, players);
	deck.shuffle();
	deck.printDeck();

	Fields fields;
	fields.setDeck(&deck);
	fields.fillFields();
	cout << endl << endl;
	cout << endl << endl;
	fields.printFields();

	Dice dice;
	dice.rollingADice();
	cout << dice.getSum() << endl;
	
	players[0].move(&dice);

	dice.rollingADice();
	cout << dice.getSum() << endl;
	players[1].move(&dice);

	dice.rollingADice();
	cout << dice.getSum() << endl;
	players[2].move(&dice);

	cout << players[0] << endl;
	cout << players[1] << endl;
	cout << players[2] << endl;

	players[0].setPosition(30);
	fields[players[0].getPosition()]->applyEffect(players[0]);

	
	players[0].prison();
	//dice.rollingADice();
	//players[0].move(&dice);


	system("pause");
	Board board;
	board.setFields(&fields);
	const int n = 11, cellSize = 10;
	board.drawGrid(n, cellSize);
	board.fillCells();
	board.showPlayer(&players[0]);
	board.showPlayer(&players[1]);
	board.showPlayer(&players[2]);
	
	board.moveCursorToBottom();
	fields[players[0].getPosition()]->applyEffect(players[0]);
	fields[players[1].getPosition()]->applyEffect(players[1]);
	fields[players[2].getPosition()]->applyEffect(players[2]);
	
	std::cout << endl << endl;
	cout << players[0] << endl;
	cout << players[1] << endl;
	cout << players[2] << endl;
	
	system("pause");
	system("cls");
	
	board.drawGrid(n, cellSize);
	board.fillCells();
	board.showPlayer(&players[0]);
	board.showPlayer(&players[1]);
	board.showPlayer(&players[2]);
   
	board.moveCursorToBottom();
	return 0;
}