#pragma once
#include "Command.h"
class Monopoly;

class SellCastleCommand : public Command
{
	Monopoly& game;
	size_t playerIndex;

public:
	SellCastleCommand(Monopoly& game, size_t playerIndex);

	void execute() override;
};

