#include "../../include/core/Command.h"
#include "../../include/core/Game.h"
#include <iostream>

PausedCommand::~PausedCommand() {}

void PausedCommand::execute(Game& game)
{
	game.togglePause();
}