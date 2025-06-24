#pragma once
#include "Command.h"
class Monopoly;

class PrintFieldCommand : public Command
{
	Monopoly& game;

public:
	PrintFieldCommand(Monopoly& game);
	
	void execute() override;

};

