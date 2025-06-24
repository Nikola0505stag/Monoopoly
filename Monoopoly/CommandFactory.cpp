#include "CommandFactory.h"
#include "Monopoly.h"

Command* CommandFactory::createCommand(const MyString& commandName, Monopoly& game,size_t index)
{
	if (commandName == "roll_dice")
		return new RollDiceCommand(game.getDice());
	else if (commandName == "help")
		return new HelpCommand();
	else if (commandName == "move")
		return new MovePlayerCommand(game.getDice(), game, index);
	else if (commandName == "sell_property")
		return new SellPropertyCommand(game, index);
	else if (commandName == "buy_cottage")
		return new BuyCottageCommand(game, index);
	else if (commandName == "buy_castle")
		return new BuyCastleCommand(game, index);
	else if (commandName == "sell_cottage")
		return new SellCottageCommand(game, index);
	else if (commandName == "sell_castle")
		return new SellCastleCommand(game, index);
	else if (commandName == "clear")
		return new ClearCommand();
	else if (commandName == "print_player")
		return new PrintPlayerCommand(game, index);
	else if (commandName == "surrender")
		return new SurrenderCommand(game, index);
	else if (commandName == "print_field")
		return new PrintFieldCommand(game);
	return nullptr;
}
