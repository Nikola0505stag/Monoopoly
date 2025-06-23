#pragma once
#include "Command.h"
class Monopoly;


class BuyCastleCommand : public Command
{
	Monopoly& game;
	size_t playerIndex;

public:
	BuyCastleCommand(Monopoly& game, size_t playerIndex);

	void execute() override;

};

