#include "../../include/components/LogicComponent.h"
#include "../../include/entities/Player.h"
#include "../../include/core/Game.h"

/*
void PlayerLogicComponnent::update(Entity* entity, Game* game, float elapsed)
{
	Player* player = dynamic_cast<Player*>(entity);
	if (!entity->getGraphicCom()->getcurrentAnime()->isPlaying())
	{
		setAttacking(false);
		setShouting(false);
	}

	if (shootCooldown > 0)
	{
		shootCooldown -= elapsed;
	}

	if (isShouting() &&
		entity->getGraphicCom()->getcurrentAnime()->isInAction() &&
		getWood() >= shootingCost &&
		shootCooldown <= 0)
	{
		//auto fire = player->createFire();
		game->addEntity(player->createFire());
		wood = getWood() - shootingCost;
		shootCooldown = shootCooldownTime;
		std::cout << "Wood restore to:" << wood << std::endl;
	}

}
*/