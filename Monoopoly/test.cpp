#include "MyQueue.hpp"
#include "MyVector.hpp"
#include "MyString.h"
#include "Player.h"
#include "MovePositionCard.h"
#include "PaymentCard.h"
#include "GroupPaymentCard.h"

using namespace std;

int main() {

	//Player pl;
	////cin >> pl;
	//cout << pl << endl;

	//MovePositionCard move;
	//move.setPositionChange(12);

	//move.applyEffect(pl);

	//cout << pl;

	//PaymentCard pay;
	//pay.setAmount(1000);
	//pay.applyEffect(pl);

	//cout << endl << pl;


	Player players[3];
	cin >> players[0] >> players[1] >> players[2];

	cout << players[0] << "\n" << players[1] << "\n" << players[2] << "\n";

	GroupPaymentCard group(3, -100, players);
	group.applyEffect(players[0]);
	cout << players[0] << "\n" << players[1] << "\n" << players[2] << "\n";

	return 0;
}