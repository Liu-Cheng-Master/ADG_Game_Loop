#include "../../include/entities/Entity.h"
#include "../../include/graphics/Window.h"
#include "../../include/core/Command.h"
#include <iostream>
#include "../../include/core/Game.h"
#include "../../include/components/PositionComponent.h"
#include "../../include/components/GraphicsComponent.h"
#include "../../include/components/ColliderComponent.h"
#include "../../include/components/Components.h"

class  Game;

Entity::Entity() :
	id(0),
	type(EntityType::UNDEFINED),
	deleted(false)
{
	position = std::make_shared<PositionComponent>();
	position->setPosition(0.f, 0.f);
	addComponent(position);
}

Entity::Entity(EntityType et) : 
	id(0),
	type (et),
	deleted(false)
{
	position = std::make_shared<PositionComponent>();
	position->setPosition(0.f, 0.f);
	addComponent(position);
}

Entity::~Entity()
{
}

void Entity::update(Game* game, float elapsed)
{
	graph->update(this, elapsed);
}
void Entity::draw(Window* window)
{
	graph->draw(window);
}

void Entity::init(const std::string& textureFile, std::shared_ptr<GraphicsComponent> gc)
{
	graph = gc;
	gc->init(textureFile);
	gc->setPosition(position->getPosition());
	addComponent(gc);
}

void Entity::addComponent(std::shared_ptr<Component> component)
{
	componentSet.turnOnBit(static_cast<unsigned int>(component->getID()));
}

bool Entity::hasComponent(Bitmask mask) const
{
	return componentSet.contains(mask);
}

void Entity::setPosition(float x, float y)
{
	position->setPosition(x, y);
}

const Vector2f& Entity::getPosition() const
{
	return position->getPosition();
}

const sf::Vector2f& Entity::getSpriteScale() const
{
	return graph->getSpriteScale();
}

sf::Vector2i Entity::getTextureSize() const
{
	return graph->getTextureSize();
}

bool Entity::isSpriteSheetEntity() const
{
	return graph->isSpriteSheetEntity();
}

std::shared_ptr<InputComponent> Entity::getInputComponent() const
{
	return nullptr;
}

std::shared_ptr<TTLComponent> Entity::getTTLComponent() const
{
	return nullptr;
}

std::shared_ptr<VelocityComponent> Entity::getVelocityComponent() const
{
	return nullptr;
}
