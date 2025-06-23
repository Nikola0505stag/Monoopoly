#pragma once
#include "Command.h"
class Monopoly;

class SellCottageCommand : public Command
{
	Monopoly& game;
	size_t playerIndex;

public:
	SellCottageCommand(Monopoly& game, size_t playerIndex);

	void execute() override;
};

