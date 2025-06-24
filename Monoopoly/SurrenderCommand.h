#pragma once
#include "Command.h"
class Monopoly;


class SurrenderCommand : public Command
{
	Monopoly& game;
	size_t playerIndex;

public:
	SurrenderCommand(Monopoly& game, size_t playerIndex);

	void execute() override;

};

