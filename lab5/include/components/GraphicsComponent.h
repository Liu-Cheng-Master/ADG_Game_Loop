#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
#include "../../include/utils/Vector2.h"
#include "../../include/graphics/SpriteSheet.h"
#include "../../include/entities/Entity.h"
#include "../../include/entities/Player.h"

class Player;
class Game;
class Entity;
class GraphicsComponent : public Component
{
public:
	
	virtual ~GraphicsComponent() {}
	virtual void init(const std::string& textureFile) = 0;
	virtual void setPosition(Vector2f position) = 0;
	virtual bool isSpriteSheetEntity() = 0;
	virtual const sf::Vector2f& getSpriteScale() const = 0;
	virtual sf::Vector2i getTextureSize() const = 0;
	virtual void draw(Window* window) = 0;
	virtual void update(Entity* en, float elapsed) = 0;
	virtual AnimBase* getcurrentAnime() = 0;
	virtual const Direction& getSpirteDirection() const = 0;

	virtual const Vector2f& getbboxsize() const = 0;
	virtual const ComponentID getID() const { return ComponentID::GRAPH; }
private:
	
};
class SpritesheetGraphics : public GraphicsComponent
{
public:
	SpritesheetGraphics() : isSpriteSheet(true) {}
	virtual void init(const std::string& textureFile) override;
	virtual void setPosition(Vector2f position) override;
	virtual bool isSpriteSheetEntity() override { return isSpriteSheet; }
	virtual const sf::Vector2f& getSpriteScale() const override { return spriteSheet.getSpriteScale(); }
	virtual sf::Vector2i getTextureSize() const override { return spriteSheet.getSpriteSize(); };
	virtual void draw(Window* window) override;
	
	virtual void update(Entity* en, float elapsed) override {};
	
	virtual AnimBase* getcurrentAnime() override { return spriteSheet.getCurrentAnim(); }

	virtual const Direction& getSpirteDirection() const override { return spriteSheet.getSpriteDirection(); }
	virtual const Vector2f& getbboxsize() const override { return bouboxSize; }
	SpriteSheet& getspritesheet() { return spriteSheet; }
	virtual const ComponentID getID() const { return ComponentID::GRAPH; }
	

private:
	
	bool isSpriteSheet;
	SpriteSheet spriteSheet;
	Vector2f bouboxSize;
};

class SimplespriteGraphics : public GraphicsComponent
{
public:
	SimplespriteGraphics(float scale) :scale(scale), isSpriteSheet(false){};
	virtual void init(const std::string& textureFile) override;
	virtual void setPosition(Vector2f position) override;
	virtual bool isSpriteSheetEntity()override{ return isSpriteSheet; }
	virtual const sf::Vector2f& getSpriteScale() const override { return sprite.getScale(); }
	virtual sf::Vector2i getTextureSize() const override { return texturesize; }
	virtual void draw(Window* window) override { window->draw(sprite); }
	virtual void update(Entity* en, float elapsed) override { sprite.setPosition({ en->getPosition().x,en->getPosition().y }); }
	virtual const Vector2f& getbboxsize() const override { return bouboxSize; }
	virtual AnimBase* getcurrentAnime() override { throw std::runtime_error("Error!"); }

	virtual const Direction& getSpirteDirection() const override { throw std::runtime_error("Error!"); }
	sf::Sprite& getSprite() { return sprite; }
	virtual const ComponentID getID() const { return ComponentID::GRAPH; }
private:
	
	bool isSpriteSheet;
	sf::Sprite sprite;
	sf::Texture texture;
	float scale;
	Rectangle boundingBox;
	Vector2f bouboxSize;
	sf::Vector2i texturesize;
};


