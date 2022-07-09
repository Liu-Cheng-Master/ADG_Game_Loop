#pragma once
#include "Entity.h"
#include "../../include/components/TTLComponent.h"
#include "../../include/components/VelocityComponent.h"

class Fire : public Entity
{
public:
	const int startTimeToLive = 150; //frames

	Fire();

	virtual void update(Game* game, float elapsed = 1.0f) override;

	int getTTL() const { return ttl->getTTL(); }
	virtual std::shared_ptr<TTLComponent> getTTLComponent() const override { return ttl; }
	virtual std::shared_ptr<VelocityComponent> getVelocityComponent() const override { return v; }
private:
	std::shared_ptr<TTLComponent> ttl;
	std::shared_ptr<VelocityComponent> v;
};

