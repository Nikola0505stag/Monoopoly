#pragma once
#include "Command.h"
class Dice;
class Monopoly;

class MovePlayerCommand : public Command
{
	Dice& dice;
	Monopoly& game;
	size_t playerIndex;

public:
	MovePlayerCommand(Dice& dice, Monopoly& game,size_t playerIndex);
	
	void execute() override;

};

