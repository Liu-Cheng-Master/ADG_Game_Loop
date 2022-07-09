#pragma once
#include "../../include/utils/Bitmask.h"
#include "../../include/entities/Entity.h"


class Systems
{
public:
	virtual void update(Game* game, Entity* entity, float elapsed) = 0;
	bool valiadate(Entity* entity) { return entity->hasComponent(componentMask); }
private:
	
protected:
	Bitmask componentMask;
};

class TTLSystem : public Systems
{ 
public:
	TTLSystem();
	
	virtual void update(Game* game, Entity* entity, float elapsed) override;

};

class InputSystem : public Systems
{
public:
	InputSystem();
	virtual void update(Game* game, Entity* entity, float elapsed) override;

};

class MovementSystem : public Systems
{
public:
	MovementSystem();
	virtual void update(Game* game, Entity* entity, float elapsed) override;
};

class GraphSystem : public Systems
{
public:
	GraphSystem();
	virtual void update(Game* game, Entity* entity, float elapsed) override;

};

class ColliderSystem : public Systems
{
public:
	ColliderSystem();
	virtual void update(Game* game, Entity* entity, float elapsed) override;
};