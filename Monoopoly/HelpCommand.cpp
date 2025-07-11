#include "HelpCommand.h"

void HelpCommand::execute()
{
	std::cout << "\n\nAvailable commands:\n"
		<< "roll_dice - Roll the dice\n" 
		<< "move - Move player after rolling a dice\n"
		<< "sell_property - Sell property to the Bank\n"
		<< "buy_cottage - by cottage on a property\n"
		<< "buy_castle - by castle on a property\n"
		<< "sell_cottage - sell cottage from a property to the bank\n"
		<< "sell_castle - sell castle from a property to the bank\n"
		<< "clear - clear the console\n"
		<< "print_player - prints player stats\n"
		<< "surrender - the player leaves the game\n"
		<< "print_field - prints a given field\n"
		<< "trade - trade property with other players\n";
	std::cout << "\n\n";
}
