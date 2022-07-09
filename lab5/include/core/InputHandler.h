#pragma once
#include "../../include/core/Command.h"
#include <iostream>
#include <SFML/Graphics.hpp>

class InputHandler
{
public:
	InputHandler();
	~InputHandler();
	std::shared_ptr<Command> space();
	
private:
	std::shared_ptr<Command> paused;
	
};

class PlayerInputHandler
{
public:
	PlayerInputHandler();
	~PlayerInputHandler();
	
	
	std::vector<std::shared_ptr<Command>>& Playeraction();

private:
	std::shared_ptr<Command> moveright;
	std::shared_ptr<Command> moveleft;
	std::shared_ptr<Command> moveup;
	std::shared_ptr<Command> movedown;
	std::shared_ptr<Command> attack;
	std::shared_ptr<Command> shout;
	std::vector<std::shared_ptr<Command>> actionvector;
	bool changemod;
};

