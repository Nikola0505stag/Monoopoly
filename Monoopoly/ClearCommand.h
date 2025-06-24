#pragma once
#include "Command.h"
class Monopoly;

class ClearCommand:public Command
{
public:

	void execute() override;

};

