#pragma once
#include "../../include/utils/Vector2.h"
#include "Components.h"


class Entity;

class VelocityComponent: public Component
{
public:
    VelocityComponent(float speed = 1.0f) : speed(speed) {}

	void setVelocity(float x, float y) { direction.x = x, direction.y = y; }
	const Vector2f& getVelocity() const { return direction; }
	float getSpeed() { return speed; }
	virtual const ComponentID getID() const { return ComponentID::VELOCITY; }
private:
	Vector2f direction;
	float speed;
};


