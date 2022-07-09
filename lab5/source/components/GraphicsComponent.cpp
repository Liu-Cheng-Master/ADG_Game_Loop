#include "../../include/components/GraphicsComponent.h"
#include "../../include/components/PositionComponent.h"
#include "../../include/entities/Entity.h"
#include "../../include/graphics/SpriteSheet.h"
#include <iostream>
#include <SFML/Graphics.hpp>
#include "../../include/utils/Vector2.h"

void SpritesheetGraphics::init(const std::string& textureFile)
{
	spriteSheet.loadSheet(textureFile);
	spriteSheet.setAnimation("Idle", true, true);
	bouboxSize = Vector2f(spriteSheet.getSpriteSize().x * spriteSheet.getSpriteScale().x,spriteSheet.getSpriteSize().y * spriteSheet.getSpriteScale().y);
}

void SpritesheetGraphics::setPosition(Vector2f position)
{
	spriteSheet.getSprite().setPosition(position.x,position.y);
}

void SpritesheetGraphics::draw(Window* window)
{
	sf::Sprite* sp = &spriteSheet.getSprite();
	const sf::Vector2f pos = sp->getPosition();
	window->draw(spriteSheet.getSprite());
}

void SimplespriteGraphics::init(const std::string& textureFile)
{
	texture.loadFromFile(textureFile);
	sprite.setTexture(texture);
	sprite.setScale(scale, scale);
	isSpriteSheet = false;
	bouboxSize = Vector2f(texture.getSize().x * sprite.getScale().x, texture.getSize().y * sprite.getScale().y);
	texturesize = { static_cast<int>(texture.getSize().x), static_cast<int>(texture.getSize().y) };
}

void SimplespriteGraphics::setPosition(Vector2f position)
{
	sprite.setPosition(position.x,position.y);
}




