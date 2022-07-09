#pragma once

class HealthComponent
{
public:
	HealthComponent(int start_health, int max_health):
		current_health(start_health),
		max_pos_health(max_health) {}

	int getHealth() { return current_health; }
	int changeHealth(int changevalue)
	{
		current_health = current_health + changevalue;
		if (current_health > max_pos_health)
		{
			current_health = max_pos_health;
		}
		else if(current_health < 0)
		{
			current_health = 0;
		}
		return current_health;
	}


protected:
	int current_health;
	int max_pos_health;
};
