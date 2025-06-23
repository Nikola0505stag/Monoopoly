#include "CommandFactory.h"
#include "Monopoly.h"

Command* CommandFactory::createCommand(const MyString& commandName, Monopoly& game)
{
	if(commandName == "roll_dice")
		return new RollDiceCommand(game.getDice());
	return nullptr;
}
