#pragma once
#include "Command.h"
class Dice;

class RollDiceCommand : public Command
{
	Dice& dice;

public:
	RollDiceCommand(Dice& dice);
	void execute() override;
};

