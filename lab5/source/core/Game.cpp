#include "../../include/core/Game.h"
#include "../../include/entities/Fire.h"
#include "../../include/entities/StaticEntities.h"
#include "../../include/components/GraphicsComponent.h"
#include "../../include/system/Systems.h"
#include "../../include/core/Command.h"



Game::Game() : paused(false),
               entitieNo(0)
	           
{
	inputH = std::make_unique<InputHandler>();

	system.push_back(std::make_shared<TTLSystem>());
	system.push_back(std::make_shared<GraphSystem>());
	system.push_back(std::make_shared<InputSystem>());
	system.push_back(std::make_shared<MovementSystem>());
	system.push_back(std::make_shared<ColliderSystem>());
	

	SoundService* sss = new SoundService();
	Locator::provide(sss);
}

Game::~Game()
{
}

template <typename T>
std::shared_ptr<T> Game::buildEntityAt(const std::string& filename, int col, int row)
{
	auto ent = std::make_shared<T>();
	float x = col * spriteWH * tileScale;
	float y = row * spriteWH * tileScale;
	float cntrFactor = (tileScale - itemScale) * spriteWH * 0.5f;
	
	ent->setPosition(x + cntrFactor, y + cntrFactor);
	ent->init(filename, std::make_shared<SimplespriteGraphics>(itemScale) );
	
	return ent;
}

void Game::buildBoard(int width, int height)
{
	board = std::make_unique<Board>(width, height);
}

void Game::initWindow(int width, int height)
{
	int wdt = static_cast<int>(width * spriteWH * tileScale);
	int hgt = static_cast<int>(height * spriteWH * tileScale);
	window.setSize(sf::Vector2u(wdt, hgt));
	window.redraw();
}

void Game::init(std::vector<std::string> lines)
{
	// Make sure that the vector of lines is not emtpy. h is the number of lines (height of the level)
	int h = lines.size() - 1;
	if (h < 0)
		throw std::exception("No data in level file");
	int w = -1;

	// Load the font for the window and set its title
	window.loadFont("font/AmaticSC-Regular.ttf");
	window.setTitle("Mini-Game");
	
	auto it = lines.cbegin();
	int row = 0;
	while (it != lines.cend())
	{
		int col = 0;

		// First iteration: we determine the width of the level (w) by the number of symbols in the first line.
		if(w == -1)
		{
			//The size of the window must be equal to the number of tiles it has, factoring their dimensions.
			w = it->size();
			buildBoard(w, h);
			initWindow(w, h);		
		}
		
		std::string::const_iterator is = it->cbegin();
		while (is != it->cend())
		{
			switch (*is)
			{
			case '.':
			{
				board->addTile(col,row,tileScale,TileType::CORRIDOR);

				break;
			}
			case 'w':
			{
				board->addTile(col, row, tileScale, TileType::WALL);
				break;
			}
			case 'x':
			{
				auto ent = buildEntityAt<Log>("img/log.png", col, row);
				addEntity(ent);			

				board->addTile(col, row, tileScale, TileType::CORRIDOR);
				break;
			}
			case 'p':
			{
				auto ent = buildEntityAt<Potion>("img/potion.png", col, row);

				addEntity(ent);			
	
				board->addTile(col, row, tileScale, TileType::CORRIDOR);
				break;
			}
			case '*':
				{
				player = std::make_shared<Player>();
				player->init("img/DwarfSpriteSheet_data.txt",std::make_shared<SpritesheetGraphics>());
				player->positionSprite(row,col,spriteWH,tileScale);
				addEntity(player);
				board->addTile(col, row, tileScale, TileType::CORRIDOR);
				}
			}

			col++; is++;
		}
		row++; it++;
	}
}

void Game::addEntity(std::shared_ptr<Entity> newEntity)
{
	
	entitieNo++;
	newEntity->setID(entitieNo);
	entities.push_back(newEntity);
}

void Game::handleInput()
{
	auto command{ inputH->space() };
	if (command)
	{
		command->execute(*this);
	}
	
}

void Game::update(float elapsed)
{
	if (!paused)
	{
		bigArray(elapsed);

		auto it{ entities.begin() };
		while (it != entities.end())
		{
			(*it)->update(this, elapsed);
			it++;
		}
		
		auto iterator = entities.begin();
		while (iterator != entities.end())
		{
			if((*iterator) != player && (*iterator)->getEntityType() != EntityType::FIRE )
			{
				if (player->collidesWith(*(*iterator)))
				{
					switch ((*iterator)->getEntityType())
					{
					case EntityType::POTION:
					{
						int health = dynamic_cast<Potion*> ((*iterator).get())->getHealth();
						player->getHealthComp()->changeHealth(health);
						(*iterator)->deleteEntity();
						std::cout << "Health restore value:" << health << std::endl;
						std::cout << "Health restore to:"<< player->getHealthComp()->getHealth() << std::endl;

						VisualEffcets* vfx = Locator::getVFX();
						vfx->playSound("img/potion.wav");

						break;
					}
					case EntityType::LOG: 
					{
						
						if (player->isAttacking() && 
							player->getGraphicCom()->getcurrentAnime()->isInAction() &&
							player->getGraphicCom()->getcurrentAnime()->getCurrentFrame()==4)
							
						{
							int wood = dynamic_cast<Log*> ((*iterator).get())->getWood();
							player->addWood(wood);
							(*iterator)->deleteEntity();
							std::cout << "Wood restore value:" << wood << std::endl;
							std::cout << "Wood restore to:" << player->getWood()<< std::endl;
						}
						break;
					}
						
					default:
						break;
					}
				}
			}
			iterator++;
		}

		auto iter = entities.begin();
		while (iter != entities.end())
		{
			if ((*iter)->isDeleted())
			{
				iter = entities.erase(iter);
			}
			else
			{
				iter++;
			}
		}
		
	}

	window.update();
}

void Game::render(float elapsed)
{

	window.beginDraw();

	
	board->draw(getWindow());

	for (std::shared_ptr<Entity> en: entities)
	{
		en->draw(getWindow());
	}

	//Draw FPS
	window.drawGUI(*this);

	//Close up for this frame.
	window.endDraw();
}


sf::Time Game::getElapsed() const { return gameClock.getElapsedTime(); }


void Game::setFPS(int FPS)
{
	std::string text("FPS: " + std::to_string(FPS));
	window.getFPSText().setString(text);
}


EntityID Game::getIDCounter()
{
	return entitieNo; 
}

std::shared_ptr<Entity> Game::getEntity(unsigned int idx)
{
	
	if (idx < entities.size() && idx >= 0)
	{
		return entities[idx];
	}
	else
	{
		throw std::exception("Error");
	}
}



void Game::bigArray(float elapsed)
{
	auto syst = system.begin();
	
	while (syst != system.end())
	{
		auto en = entities.begin();

		while (en != entities.end())
		{
			if (!(*en)->isDeleted() && (*syst)->valiadate(en->get()))
			{
				(*syst)->update(this, en->get(), elapsed);
			}

			en++;
		}

		syst++;
	}
}
