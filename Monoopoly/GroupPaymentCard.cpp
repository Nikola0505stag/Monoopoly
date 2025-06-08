#include "GroupPaymentCard.h"

GroupPaymentCard::GroupPaymentCard(size_t size, int amount, Player* players) : PaymentCard(amount)
{
	if (size > MAX_PLAYERS) {
		throw std::invalid_argument("Size exceeds maximum number of players.");
	}
	this->size = size;
	for (size_t i = 0; i < size; ++i) {
		this->players[i] = &players[i];
	}
}

void GroupPaymentCard::applyEffect(Player& player)
{
	for (size_t i = 0; i < size; ++i) {
		if (players[i]->getName() != player.getName()) {
			players[i]->setMoney(players[i]->getMoney() - getAmount());
			player.setMoney(player.getMoney() + getAmount());
		}
	}
	if (player.getMoney() < 0) {
		throw std::invalid_argument("Player cannot have negative money.");
	}
}
