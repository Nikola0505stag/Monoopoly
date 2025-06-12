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

using namespace std;

int main() {
	

	Player pl("Nikola");

	Property pro(1, "Test Property", 100, 10, 50, &pl);
	//pro.print();
	cout << endl;
	//cout << pro.getOwner()->getPosition();

	CardField cardField(4);
	//cardField.print();

	Parking st;
	//st.print();

	cout << endl << endl;
	Fields fields;
	fields.addField(new Property(pro));
	fields.addField(new CardField(cardField));
	fields.addField(new Parking(st));
	fields.printFields();

	return 0;
}