#include "MyQueue.hpp"
#include "MyVector.hpp"
#include "MyString.h"
#include "Player.h"
#include "MovePositionCard.h"
#include "PaymentCard.h"
#include "GroupPaymentCard.h"
#include "Deck.h"

using namespace std;

int main() {




	Player players[3];
	cin >> players[0] >> players[1] >> players[2];
	cout << players[0] << "\t" << players[1] << "\t" << players[2];
	Deck deck;

	deck.fillDeck(3, players);
	deck.printDeck();
	deck.shuffle();

	cout << endl << endl << endl;

	deck.printDeck();

	Card* card = deck.drawCard();
	cout << endl << "Card drawn: ";
	card->print();

	card->applyEffect(players[0]);
	cout << endl << endl << endl;
	cout << players[0] << "\n" << players[1] << "\n" << players[2];
	return 0;
}