#pragma once
#include "Command.h"
class Monopoly;


class BuyCottageCommand : public Command
{
	Monopoly& game;
	size_t playerIndex;

public:
	BuyCottageCommand(Monopoly& game, size_t playerIndex);

	void execute() override;

};

