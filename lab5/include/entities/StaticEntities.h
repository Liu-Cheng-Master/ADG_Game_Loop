#pragma once
#include "Entity.h"
#include "../../include/components/GraphicsComponent.h"
#include "../../include/components/ColliderComponent.h"
#include "../../include/components/PositionComponent.h"


class Potion : public Entity
{
public:
	Potion() : Entity(EntityType::POTION) { colliderCom = std::make_shared<ColliderComponent>(); addComponent(colliderCom); }//
	~Potion() {}

	void init(const std::string& textureFile, std::shared_ptr<GraphicsComponent> gc) override
	{
		Entity::init(textureFile, gc);
		colliderCom->setbboxsize(gc->getbboxsize());
	}
	
	virtual void draw(Window* window) override
	{
		Entity::draw(window);
		colliderCom->draw(window);
	}
	
	virtual void update(Game* game, float elapsed = 1.0f) override { graph->update(this, elapsed); }
	virtual const std::shared_ptr<ColliderComponent>getColliderComp() const override { return colliderCom; }
	int getHealth() const { return potionHealth; }

protected:
	const int potionHealth = 10;
	std::shared_ptr<ColliderComponent> colliderCom;
};


class Log : public Entity
{
public:
	Log() : Entity(EntityType::LOG) { colliderCom = std::make_shared<ColliderComponent>(); addComponent(colliderCom); }
	~Log() {}

	void init(const std::string& textureFile, std::shared_ptr<GraphicsComponent> gc) override
	{
		Entity::init(textureFile, gc);
		colliderCom->setbboxsize(gc->getbboxsize());
	}
	
	virtual void draw(Window* window) override
	{
		Entity::draw(window);
		colliderCom->draw(window);
	}
	
	virtual void update(Game* game, float elapsed = 1.0f) override { graph->update(this, elapsed); }
	virtual const std::shared_ptr<ColliderComponent>getColliderComp() const override { return colliderCom; }
	int getWood() const { return woodAdded; }

protected:
	const int woodAdded = 15;
	std::shared_ptr<ColliderComponent> colliderCom;
};