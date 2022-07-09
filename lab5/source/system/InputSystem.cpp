#include "../../include/system/Systems.h"
#include "../../include/components/Components.h"
#include "../../include/components/InputComponent.h"
#include "../../include/components/VelocityComponent.h"
#include "../../include/core/InputHandler.h"
#include "../../include/core/Game.h"

InputSystem::InputSystem()
{
	componentMask.turnOnBit(static_cast<int>(ComponentID::INPUT));
	componentMask.turnOnBit(static_cast<int>(ComponentID::VELOCITY));
}

void InputSystem::update(Game* game, Entity* entity, float elapsed) 
{
	std::shared_ptr<InputComponent> input = entity->getInputComponent();
	std::shared_ptr<VelocityComponent> velo = entity->getVelocityComponent();

	if (input)
	{
		if (velo)
		{
			velo->setVelocity(0.f, 0.f);

			auto inputhandler = input->getPlayerInputHandler() ;

			if (inputhandler) 
			{
				auto command =  inputhandler->Playeraction() ;
				for (auto action : command)
				{
					action->execute(*game);
				}
			}
			else
			{
				throw std::runtime_error("There is no PlayerHandler for the Input system in this update!");
			}
		}
		else
		{
			throw std::runtime_error("There is no Velocity for this entity!");
		}
	}
	else
	{
		throw std::runtime_error("There is no InputComponent for this entity!");
	}
}

