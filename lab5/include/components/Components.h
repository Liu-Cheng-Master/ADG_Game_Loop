#pragma once

enum class ComponentID
{
	UNDEFINED = -1,
	INPUT = 0,
	POSITION = 1,
	VELOCITY = 2,
	TTL = 3,
	GRAPH=4,
	COLLIDER=5
};

class Component
{
public:
	virtual const ComponentID getID()  const = 0;
};