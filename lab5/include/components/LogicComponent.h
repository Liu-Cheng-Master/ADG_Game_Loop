#pragma once
#include "../../include/entities/Entity.h"
#include "../../include/components/GraphicsComponent.h"


class Entity;
class Game;
class LogicComponent
{
public:
	virtual void update(Entity* entity, Game* game, float elapsed) = 0;
	virtual bool isAttacking() const = 0;
	virtual void setAttacking(bool at) = 0;
	virtual int getWood() const = 0;
	virtual bool isShouting() const = 0;
	virtual void setShouting(bool sh) = 0;
private:

};

class PlayerLogicComponnent : public LogicComponent
{
public:
	PlayerLogicComponnent(int shotcost, float shotcotime) : attacking(false), shouting(false), wood(0), shootCooldown(0), shootingCost(shotcost), shootCooldownTime(shotcotime){}
	virtual void update(Entity* entity, Game* game, float elapsed) override;

	bool isAttacking() const { return attacking; }
	void setAttacking(bool at) { attacking = at; }
	int getWood() const { return wood; }
	bool isShouting() const { return shouting; }
	void setShouting(bool sh) { shouting = sh; }

private:
	bool attacking;
	bool shouting;
	int wood;
	float shootCooldown;
	const int shootingCost;
	float shootCooldownTime;
};


