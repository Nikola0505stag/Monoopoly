#pragma once
#include "Command.h"
#include <iostream>
class HelpCommand : public Command
{
	// Inherited via Command
	void execute() override;
};

