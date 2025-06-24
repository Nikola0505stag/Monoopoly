#include "SurrenderCommand.h"
#include "Monopoly.h"

SurrenderCommand::SurrenderCommand(Monopoly& game, size_t playerIndex):
	game(game), playerIndex(playerIndex)
{}

void SurrenderCommand::execute()
{
	game.removePlayer(playerIndex);	
	game.isGameFinished();
}
