#include "../../include/system/Systems.h"
#include "../../include/components/Components.h"
#include "../../include/components/PositionComponent.h"
#include "../../include/components/GraphicsComponent.h"
#include "../../include/components/VelocityComponent.h"


GraphSystem::GraphSystem()
{
	componentMask.turnOnBit(static_cast<int>(ComponentID::POSITION));
	componentMask.turnOnBit(static_cast<int>(ComponentID::GRAPH));
	componentMask.turnOnBit(static_cast<int>(ComponentID::VELOCITY));

	
	
}

void GraphSystem::update(Game* game, Entity* entity, float elapsed)
{
	std::shared_ptr<PositionComponent> position = entity->getPositionComponent();
	auto graph = dynamic_cast<GraphicsComponent*>(entity->getgraphcompointer());
	std::shared_ptr<VelocityComponent> velo = entity->getVelocityComponent();

	if (position) 
	{
		if (graph)
		{
			if (velo)
			{
				if (graph->isSpriteSheetEntity())
				{
					
					auto spritesheetgraph = dynamic_cast<SpritesheetGraphics*>(graph);

					auto& spritesheet = spritesheetgraph->getspritesheet();
					
					auto player = dynamic_cast<Player*>(entity);
					
					
					if (player->isAttacking())
					{
						spritesheet.setAnimation("Attack", true, false);
					}
					else if (player->isShouting())
					{
						spritesheet.setAnimation("Shout", true, false);
					}
					else if (player->getVelocityComponent()->getVelocity().x > 0)
					{

						spritesheet.setAnimation("Walk", true, true);
						spritesheet.setSpriteDirection(Direction::Right);
					}
					else if (player->getVelocityComponent()->getVelocity().x < 0)
					{
						spritesheet.setAnimation("Walk", true, true);
						spritesheet.setSpriteDirection(Direction::Left);
					}
					else if (player->getVelocityComponent()->getVelocity().y)
					{
						spritesheet.setAnimation("Walk", true, true);
					}
					else if (player->getVelocityComponent()->getVelocity().x == 0 && player->getVelocityComponent()->getVelocity().y == 0)
					{
						spritesheet.setAnimation("Idle", true, true);
					}
					spritesheet.getSprite().setPosition(position->getPosition().x, position->getPosition().y);
					spritesheet.update(elapsed);
					
				}
				else
				{
					auto simplesheetgraph = dynamic_cast<SimplespriteGraphics*>(graph);
					simplesheetgraph->getSprite().setPosition(position->getPosition().x, position->getPosition().y);
				}
			}
			else
			{
				throw std::runtime_error("There is no velocity component for this entity!");
			}
			
		}
		else
		{
			throw std::runtime_error("There is no graph component for this entity!");
		}
	}
	else
	{
		throw std::runtime_error("There is no postion component for this entity!");
	}
}
