#include "../../include/system/Systems.h"
#include "../../include/components/Components.h"
#include "../../include/components/TTLComponent.h"

TTLSystem::TTLSystem() 
{
	componentMask.turnOnBit(static_cast<int>(ComponentID::TTL));
};

void TTLSystem::update(Game* game, Entity* entity, float elapsed)
{
	std::shared_ptr<TTLComponent> TTl = entity->getTTLComponent();
	if (TTl)
	{
		TTl->TTLdecrease();
		if (TTl->getTTL() <= 0)
		{
			entity->deleteEntity();
		}
	}
	else
	{
		throw std::runtime_error("There is no TTL for this entity!");
	}
	
}