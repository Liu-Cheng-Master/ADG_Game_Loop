#include "../../include/core/Command.h"
#include "../../include/core/Game.h"
#include <iostream>

MoveRightCommand::~MoveRightCommand() {}
void MoveRightCommand::execute(Game& game)
{
	auto v = game.getPlayer()->getVelocityComponent();
	v->setVelocity(1.0f, v->getVelocity().y);
}

MoveLeftCommand::~MoveLeftCommand() {}
void MoveLeftCommand::execute(Game& game) 
{
	auto v = game.getPlayer()->getVelocityComponent();
	v->setVelocity(-1.0f, v->getVelocity().y);
}

MoveUpCommand::~MoveUpCommand() {}
void MoveUpCommand::execute(Game& game) 
{
	auto v = game.getPlayer()->getVelocityComponent();
	v->setVelocity(v->getVelocity().x, -1.0f);
}

MoveDownCommand::~MoveDownCommand() {}
void MoveDownCommand::execute(Game& game)
{
	auto v = game.getPlayer()->getVelocityComponent();
	v->setVelocity(v->getVelocity().x, 1.0f);
}

AttackCommand::~AttackCommand() {}
void AttackCommand::execute(Game& game)
{
	game.getPlayer()->setAttacking(true);
}

ShoutCommand::~ShoutCommand() {}
void ShoutCommand::execute(Game& game)
{
	game.getPlayer()->setShouting(true);
}
