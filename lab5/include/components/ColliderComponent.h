#pragma once
#include <iostream>
#include "../../include/utils/Rectangle.h"
#include "../../include/entities/Entity.h"
#include "../../include/graphics/Window.h"


class ColliderComponent : public Component
{
public:
	Rectangle& getBoundingBox(){ return boundingBox; }
	void setbboxsize(Vector2f size) { bboxSize = size; }
	const Vector2f getbboxsize() { return bboxSize; }
	void draw(Window* window) { window->draw(boundingBox.getDrawableRect()); }
	
	bool interesects(ColliderComponent* collider)
	{
		return boundingBox.intersects(collider->getBoundingBox());
	}

	virtual const ComponentID getID() const { return ComponentID::COLLIDER; }


private:
	Rectangle boundingBox;
	Vector2f bboxSize;
};
