#include "HelpCommand.h"

void HelpCommand::execute()
{
	std::cout << "\n\nAvailable commands:\n"
		<< "roll_dice - Roll the dice\n" 
		<< "move - Move player after rolling a dice\n";
}
