#include "MovePlayerCommand.h"
#include "Dice.h"
#include "Monopoly.h"

MovePlayerCommand::MovePlayerCommand(Dice& dice, Monopoly& game, size_t playerIndex):
	dice(dice), game(game),playerIndex(playerIndex)
{}

void MovePlayerCommand::execute()
{
	Player& player = game.getPlayer(playerIndex);
	int prePos = player.getPosition();
	player.move(&dice);

	game.getFields()[player.getPosition()]->print();
	game.getFields()[player.getPosition()]->applyEffect(player);
	game.acrossStart(player,prePos,player.getPosition());
}
