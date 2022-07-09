#include "../../include/core/InputHandler.h"


InputHandler::InputHandler() : paused(std::make_shared<PausedCommand>()) {}
InputHandler::~InputHandler() {}

std::shared_ptr<Command> InputHandler::space()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::P))
	{
		return paused;
	}
	return nullptr;
}

PlayerInputHandler::PlayerInputHandler() :
	moveright(std::make_shared<MoveRightCommand>()),
	moveleft(std::make_shared<MoveLeftCommand>()),
	moveup(std::make_shared<MoveUpCommand>()),
	movedown(std::make_shared<MoveDownCommand>()),
	attack(std::make_shared<AttackCommand>()),
	shout(std::make_shared<ShoutCommand>()),
    changemod(false){}

PlayerInputHandler::~PlayerInputHandler() {}


std::vector<std::shared_ptr<Command>>& PlayerInputHandler::Playeraction()
{
	// TODO: insert return statement here
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter))
	{
		changemod = !changemod;
		std::cout << "Change Model!";
	}

	actionvector.clear();
	
	if (changemod)
	{
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
		{
			actionvector.push_back(moveright);
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
		{
			actionvector.push_back(moveleft);
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
		{
			actionvector.push_back(moveup);
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
		{
			actionvector.push_back(movedown);
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
		{
			actionvector.push_back(attack);
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::LShift))
		{
			actionvector.push_back(shout);
		}

		return actionvector;
	}
	
	else
	{
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
		{
			actionvector.push_back(moveright);
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
		{
			actionvector.push_back(moveleft);
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
		{
			actionvector.push_back(moveup);
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
		{
			actionvector.push_back(movedown);
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
		{
			actionvector.push_back(attack);
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::LShift))
		{
			actionvector.push_back(shout);
		}

		return actionvector;
	}
	
	
}


