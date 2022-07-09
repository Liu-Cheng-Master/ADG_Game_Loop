#pragma once
#include "Components.h"

class TTLComponent:public Component
{
public:
	TTLComponent(int startTimeToLive) :ttl(startTimeToLive) {}
	void TTLdecrease() 
	{
		if (ttl > 0)
		{
			ttl -= 1;
		}
	}
	int getTTL() { return ttl; }
	virtual const ComponentID getID() const { return ComponentID::TTL; }

private:
	int ttl;
};
