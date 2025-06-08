#pragma once
#include "Card.h"

class PaymentCard : public Card
{
	int amount;

public:

	PaymentCard();
	PaymentCard(int amount);
	//PaymentCard(const PaymentCard& other) = default;
	//PaymentCard& operator=(const PaymentCard& other) = default;

	void setAmount(int amount);
	int getAmount() const;

	virtual void applyEffect(Player& player) override;
	virtual Card* clone() const override;

	// Inherited via Card
	void print() const override;
};

