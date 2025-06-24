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
#include "Monopoly.h"
#include "Bank.h"

using namespace std;

int main() {



	Monopoly game;
	game.playersInput();
	game.makeGame();
	system("pause");
	system("cls");
	game.drawBoard();
	game.drawPlayersOnBoard();
	
		game.start();
	
	//game.test();
	//game.test();
	//game.test();
	//game.test();
	//game.test();
	return 0;
}