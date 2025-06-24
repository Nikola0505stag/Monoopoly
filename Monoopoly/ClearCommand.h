#pragma once
#include "Command.h"
class Monopoly;

class ClearCommand:public Command
{
public:


	// Inherited via Command
	void execute() override;

};

