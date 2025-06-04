#pragma once
#include "PaymentCard.h"
class GroupPaymentCard : public PaymentCard
{
	Player* players = nullptr;

public:

	GroupPaymentCard();
	GroupPaymentCard(int amount, Player* players);

	void setPlayers(Player* players);
	Player* getPlayers() const;

	void applyEffect(Player& player) override;

	~GroupPaymentCard();
};

