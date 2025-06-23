#include "CommandFactory.h"
#include "Monopoly.h"

Command* CommandFactory::createCommand(const MyString& commandName, Monopoly& game)
{
	if (commandName == "roll_dice")
		return new RollDiceCommand(game.getDice());
	else if (commandName == "help")
		return new HelpCommand();
	return nullptr;
}
