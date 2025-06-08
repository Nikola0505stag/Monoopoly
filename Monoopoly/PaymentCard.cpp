#include "PaymentCard.h"

PaymentCard::PaymentCard()
{
    setAmount(0);
}

PaymentCard::PaymentCard(int amount)
{
    setAmount(amount);
}

void PaymentCard::setAmount(int amount)
{
	this->amount = amount;
}

int PaymentCard::getAmount() const
{
    return amount;
}

void PaymentCard::applyEffect(Player& player)
{
	player.setMoney(player.getMoney() + amount);
	if (player.getMoney() < 0) {
		throw std::invalid_argument("Player cannot have negative money.");
	}
}

Card* PaymentCard::clone() const
{
	return new PaymentCard(*this);
}

void PaymentCard::print() const
{
	std::cout << "PaymentCard: Pay " << amount << " money.\n";
}
