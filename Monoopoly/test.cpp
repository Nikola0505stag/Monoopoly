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

	GroupPaymentCard group(3, 100, players);

	Deck deck;

	deck.addCard(new MovePositionCard(5));
	deck.addCard(group.clone());
	deck.addCard(new PaymentCard(3));

	cout << endl;
	deck.printDeck();

	cout << endl << endl;

	deck.shuffle();
	deck.printDeck();
	cout << endl << endl;

	Card* card = deck.drawCard();
	cout << "\nDrawn card: ";
	card->print();

	card->applyEffect(players[0]);

	cout << players[0] << endl << players[1] << endl << players[2];

	delete card;
	return 0;
}