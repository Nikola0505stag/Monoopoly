#pragma once
#include "Card.h"

class PaymentCard : public Card
{
	int amount;

public:

	PaymentCard();
	PaymentCard(int amount);



	void setAmount(int amount);
	int getAmount() const;

	void applyEffect(Player& player) override;
};

