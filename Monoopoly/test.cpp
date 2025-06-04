#include "MyQueue.hpp"
#include "MyVector.hpp"
#include "MyString.h"
#include "Player.h"
#include "MovePositionCard.h"
#include "PaymentCard.h"

using namespace std;

int main() {

	Player pl;
	//cin >> pl;
	cout << pl << endl;

	MovePositionCard move;
	move.setPositionChange(12);

	move.applyEffect(pl);

	cout << pl;

	PaymentCard pay;
	pay.setAmount(1000);
	pay.applyEffect(pl);

	cout << endl << pl;

	return 0;
}