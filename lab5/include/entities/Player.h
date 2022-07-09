#pragma once
#include <SFML/Audio.hpp>
#include "Entity.h"
#include "../../include/components/HealthComponent.h"
#include "../../include/components/VelocityComponent.h"
#include "../../include/components/ColliderComponent.h"
#include "../../include/Service/Service.h"
#include "../../include/Service/locator.h"


class Fire;
class GraphicsComponent;
class PlayerInputComponent;
class Player :  public Entity
{
public:

	const float playerSpeed = 100.0f;
	const int startingHealth = 60;
	const int maxHealth = 100;
	const int maxWood = 100;
	const int shootingCost = 20;
	const float fireSpeed = 2.0f;
	const float shootCooldownTime = 3.f;
	const float attackCooldownTime = 1.f;//in seconds

	Player();
	~Player();

	void init(const std::string& textureFile, std::shared_ptr<GraphicsComponent> gc);
	

	virtual void update(Game* game, float elapsed = 1.0f) override;

	virtual const std::shared_ptr<ColliderComponent>getColliderComp() const override { return colliderplayer; }
	std::shared_ptr<HealthComponent> getHealthComp() { return health; }
	virtual std::shared_ptr<InputComponent> getInputComponent() const override { return input; };
	virtual std::shared_ptr<VelocityComponent> getVelocityComponent() const override { return velocity; }

	bool isAttacking() const { return attacking; }
	void setAttacking(bool at) { attacking = at; }
	bool isShouting() const { return shouting; }
	void setShouting(bool sh) { shouting = sh; }
	int getWood() const { return wood; }
	void addWood(int w);
	bool hasSpriteSheet() const;
	void positionSprite(int row, int col, int spriteWH, float tileScale);

	bool collidesWith(Entity& other){ return colliderplayer->interesects(other.getColliderComp().get());} //
	void draw(Window* window);
	std::shared_ptr<Fire> createFire() const;
	
private:

	bool attacking;
	bool shouting;
	int wood;
	float shootCooldown;
	float attacksoundCooldown;
	std::shared_ptr<PlayerInputComponent> playerInput;
	std::shared_ptr<VelocityComponent> velocity;
	std::shared_ptr<ColliderComponent> colliderplayer;
	std::shared_ptr<InputComponent> input;
	std::shared_ptr<HealthComponent> health;
	
	
};

