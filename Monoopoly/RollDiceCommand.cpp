#include "RollDiceCommand.h"
#include "Dice.h"	

RollDiceCommand::RollDiceCommand(Dice& dice): dice(dice)
{}

void RollDiceCommand::execute()
{
	dice.rollingADice();
}
