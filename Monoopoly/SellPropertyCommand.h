#pragma once
#include "Command.h"
class Monopoly;

class SellPropertyCommand : public Command
{
	Monopoly& game;
	size_t playerIndex;
public:
	SellPropertyCommand(Monopoly& game, size_t playerIndex);
	void execute() override;
};

