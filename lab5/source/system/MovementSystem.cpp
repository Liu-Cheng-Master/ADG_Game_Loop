#include "../../include/system/Systems.h"
#include "../../include/components/Components.h"
#include "../../include/components/PositionComponent.h"
#include "../../include/components/VelocityComponent.h"

MovementSystem::MovementSystem()
{
	componentMask.turnOnBit(static_cast<int>(ComponentID::POSITION));
	componentMask.turnOnBit(static_cast<int>(ComponentID::VELOCITY));
}

void MovementSystem::update(Game* game, Entity* entity, float elapsed)
{
	std::shared_ptr<PositionComponent> position = entity->getPositionComponent();
	std::shared_ptr<VelocityComponent> velo = entity->getVelocityComponent();

	if (position) 
	{
		if (velo)
		{
			Vector2f nextPos = position->getPosition() + velo->getVelocity() * velo->getSpeed();
			position->setPosition(nextPos.x, nextPos.y);
		}
		else
		{
			throw std::runtime_error("There is no velocity component for this entity!");
		}
	}
	else
	{
		throw std::runtime_error("There is no Postion Component for this entity!");
	}
}