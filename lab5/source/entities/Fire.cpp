#include "../../include/entities/Fire.h"
#include <iostream>

Fire::Fire() : Entity(EntityType::FIRE)
{
	ttl = std::make_shared<TTLComponent>(startTimeToLive);
	addComponent(ttl);
	v = std::make_shared<VelocityComponent>();
	addComponent(v);
}

void Fire::update(Game* game, float elapsed)
{
	Entity::update(game, elapsed);
}