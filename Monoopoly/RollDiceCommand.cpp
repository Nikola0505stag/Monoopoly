#include "RollDiceCommand.h"
#include "Dice.h"	

RollDiceCommand::RollDiceCommand(Dice& dice): dice(dice)
{}

void RollDiceCommand::execute()
{
	dice.rollingADice();
	//std::cout << dice.getFirstDie() << " and "
		//<< dice.getSecondDie() << std::endl;
}
