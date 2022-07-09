#pragma once
#include "../graphics/Window.h"
#include "../graphics/SpriteSheet.h"
#include "../utils/Rectangle.h"
#include "../../include/utils/Bitmask.h"

using EntityID = unsigned int;
enum class EntityType
{
	UNDEFINED = -1,
	PLAYER = 0,
	POTION = 1,
	LOG = 2,
	FIRE = 3
};

class Game; //forward declaration
class PositionComponent;
class GraphicsComponent;
class ColliderComponent;
class TTLComponent;
class VelocityComponent;
class InputComponent;
class Component;

class Entity
{
public:

	//Constructors and Desctrutors
	Entity();
	Entity(EntityType et);
	~Entity();

	//Init and update functions
	virtual void init(const std::string& textureFile, std::shared_ptr<GraphicsComponent> gc);
	virtual void update(Game* game, float elapsed = 1.0f);
	virtual void draw(Window* window);
	virtual const std::shared_ptr<ColliderComponent>getColliderComp() const { return nullptr; }
	//Getters and Setters
	void setID(EntityID entId) { id = entId; }
	EntityID getID() const { return id; }

	const Bitmask& getComponentSet() const { return componentSet; }
	void addComponent(std::shared_ptr<Component> component);
	bool hasComponent(Bitmask mask) const;

	void setPosition(float x, float y);
	const Vector2f& getPosition() const;
	const sf::Vector2f& getSpriteScale() const;
	sf::Vector2i getTextureSize() const;
	EntityType getEntityType() const { return type; }
	bool isSpriteSheetEntity() const;
	
	bool isDeleted() const { return deleted; }
	void deleteEntity() { deleted = true; }

	const std::shared_ptr<GraphicsComponent>& getGraphicCom() { return graph; }
	const std::shared_ptr<PositionComponent>& getPositionComponent() { return position; }

	virtual std::shared_ptr<InputComponent> getInputComponent() const;
	virtual std::shared_ptr<TTLComponent> getTTLComponent() const;
	virtual std::shared_ptr<VelocityComponent> getVelocityComponent() const;

	GraphicsComponent* getgraphcompointer() { return graph.get(); }
protected:

	EntityType type;
	EntityID id;

	std::shared_ptr<PositionComponent> position;
	
	//Collision
	std::shared_ptr<GraphicsComponent> graph;
	bool deleted;

	Bitmask componentSet;
};