#pragma once
#define MAX_PLAYERS 6
#include "PaymentCard.h"
class GroupPaymentCard : public PaymentCard
{
	size_t size;
	Player* players[MAX_PLAYERS];

public:

	GroupPaymentCard() = delete;
	GroupPaymentCard(size_t size, int amount, Player* players);

	void applyEffect(Player& player) override;
	Card* clone() const override;
	

	// Inherited via PaymentCard
	void print() const override;

};

