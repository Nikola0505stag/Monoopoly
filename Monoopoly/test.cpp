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

using namespace std;

int main() {
	

	Player pl("Nikola");

	Property pro(1, "Test Property", 100, 10, 50, &pl);
	pro.print();
	cout << endl;
	cout << pro.getOwner()->getPosition();

	return 0;
}