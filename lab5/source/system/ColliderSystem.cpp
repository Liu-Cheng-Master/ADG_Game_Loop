
#include "../../include/system/Systems.h"
#include "../../include/components/Components.h"
#include "../../include/components/PositionComponent.h"
#include "../../include/components/ColliderComponent.h"
#include "../../include/components/GraphicsComponent.h"
#include "../../include/graphics/Window.h"
#include "../../include/core/Game.h"



ColliderSystem::ColliderSystem() 
{
	componentMask.turnOnBit(static_cast<int>(ComponentID::POSITION));
	componentMask.turnOnBit(static_cast<int>(ComponentID::COLLIDER));
}

void ColliderSystem::update(Game* game, Entity* entity, float elapsed)
{
	
	std::shared_ptr<PositionComponent> position = entity->getPositionComponent();
	std::shared_ptr<ColliderComponent> collider = entity->getColliderComp();


	if (position)
	{
		if (collider)
		{
			collider->getBoundingBox().setTopLeft(position->getPosition());
			collider->getBoundingBox().setBottomRight(position->getPosition() + collider->getbboxsize());
		}
		else
		{
			throw std::runtime_error("There is no collider component for this entity!");
		}
	}
	else
	{
		throw std::runtime_error("There is no position component for this entity!");
	}
}
