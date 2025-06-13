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

using namespace std;

int main() {
	


	

	

	Player players[2];
	players[1].setName("Martin");
	players[0].setName("Nikola");

	Deck deck;
	deck.fillDeck(2, players);
	deck.shuffle();

	Fields fields;
	fields.setDeck(&deck);
	fields.fillFields();
	fields.printFields();
	std::cout << "\n\n\n";
	/*Player pl2("Martin");
	player.setMoney(1000);
	cout << player;
	cout << "\n\n";
	fields[39]->print();
	fields[39]->applyEffect(player);

	cout << player;

	cout << "\n\n";
	fields[39]->print();
	cout << "\n\n";*/

	//fields[39]->applyEffect(pl2);

	/*fields[30]->applyEffect(player);
	cout << player;*/
	fields[38]->applyEffect(players[0]);
	std::cout << "\n\n" << players[0];

	return 0;
}