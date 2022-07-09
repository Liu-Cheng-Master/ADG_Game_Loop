#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
#include "Components.h"
class  Game;
class  PlayerInputHandler;

class InputComponent : public Component
{
public:
	virtual ~InputComponent() {}
	virtual void update(Game& game) {};

	virtual const std::shared_ptr<PlayerInputHandler> getPlayerInputHandler() const { return nullptr; };
	virtual const ComponentID getID() const { return ComponentID::INPUT; }
private:

};

class PlayerInputComponent : public InputComponent
{
public:
	PlayerInputComponent() :playerinputcomp{ std::make_shared<PlayerInputHandler>() }{}
	~PlayerInputComponent() {}
	

	virtual const std::shared_ptr<PlayerInputHandler> getPlayerInputHandler() const override { return playerinputcomp; }

private:
	std::shared_ptr<PlayerInputHandler> playerinputcomp;
};



