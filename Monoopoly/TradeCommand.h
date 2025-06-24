#pragma once
#include "Command.h"
class Monopoly;

class TradeCommand : public Command
{
	Monopoly& game;
	size_t playerIndex;

public:
	TradeCommand(Monopoly& game, size_t playerIndex);

	void execute() override;
};

