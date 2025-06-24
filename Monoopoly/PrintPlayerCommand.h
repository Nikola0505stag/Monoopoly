#pragma once
#include "Command.h"
class Monopoly;

class PrintPlayerCommand : public Command
{
	Monopoly& game;
	size_t playerIndex;

public:
	PrintPlayerCommand(Monopoly& game, size_t playerIndex);

	void execute() override;
};

