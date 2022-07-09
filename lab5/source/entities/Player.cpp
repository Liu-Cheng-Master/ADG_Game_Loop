#include "../../include/entities/Player.h"
#include "../../include/graphics/AnimBase.h"
#include "../../include/entities/Fire.h"
#include "../../include/core/Game.h"
#include "../../include/core/Command.h"
#include "../../include/components/InputComponent.h"
#include "../../include/components/VelocityComponent.h"
#include "../../include/components/GraphicsComponent.h"
#include "../../include/components/PositionComponent.h"



class Locator;

Player::Player() : Entity(EntityType::PLAYER), attacking(false), shouting(false), wood(0), shootCooldown(0),attacksoundCooldown(0)
{
	input = std::make_shared<PlayerInputComponent>();
	velocity = std::make_shared<VelocityComponent>();
	colliderplayer = std::make_shared<ColliderComponent>();
	health = std::make_shared<HealthComponent>(startingHealth, maxHealth);

	SoundService* sss = new SoundService();
	Locator::provide(sss);

	addComponent(velocity);
	addComponent(input);
	addComponent(colliderplayer);
}

Player::~Player() {}

void Player::init(const std::string& textureFile, std::shared_ptr<GraphicsComponent> gc)
{
	Entity::init(textureFile, gc);
	colliderplayer->setbboxsize(gc->getbboxsize());
}

void Player::update(Game* game, float elapsed)
{
	Entity::update(game, elapsed);
	if (!getGraphicCom()->getcurrentAnime()->isPlaying())
	{
		setAttacking(false);
		setShouting(false);
	}

	if (shootCooldown > 0)
	{
		shootCooldown -= elapsed;
	}

	if (attacksoundCooldown > 0)
	{
		attacksoundCooldown -= elapsed;
	}

	if (isShouting() &&
		getGraphicCom()->getcurrentAnime()->isInAction() &&
		getWood() >= shootingCost &&
		shootCooldown <= 0)
	{
		auto fire = game->getPlayer()->createFire();
		game->addEntity(fire);
		wood = getWood() - shootingCost;
		shootCooldown = shootCooldownTime;
		std::cout << "Wood restore to:" << wood << std::endl;

		VisualEffcets* vfx = Locator::getVFX();
		vfx->playSound("img/pop.wav");
	}

	if (isAttacking() &&
		getGraphicCom()->getcurrentAnime()->isInAction() &&
		attacksoundCooldown <= 0)
	{
		VisualEffcets* vfx = Locator::getVFX();
		vfx->playSound("img/cut.wav");
		attacksoundCooldown = attackCooldownTime;
	}

}

std::shared_ptr<Fire> Player::createFire() const
{
	auto fireEntity = std::make_shared<Fire>();		

	Vector2f pos { getPosition().x + getTextureSize().x * 0.5f, getPosition().y + getTextureSize().y * 0.5f };
	fireEntity->init("img/fire.png", std::make_shared<SimplespriteGraphics>(1.0f));
	fireEntity->getPositionComponent()->setPosition(pos.x,pos.y);
	Vector2f vel(fireSpeed, 0.f);
	if (graph->getSpirteDirection() == Direction::Left) vel.x = vel.x * -1.0f;
	fireEntity->getVelocityComponent()->setVelocity(vel.x,vel.y);

	return fireEntity;
}

void Player::addWood(int w)
{
	wood += w;
	if (wood > maxWood) wood = maxWood;
	if (wood < 0) wood = 0;
}

bool Player::hasSpriteSheet() const
{
	return graph->isSpriteSheetEntity();
}


void Player::positionSprite(int row, int col, int spriteWH, float tileScale)
{
	sf::Vector2f scaleV2f = getSpriteScale();
	sf::Vector2i textureSize = getTextureSize();

	float x = col * spriteWH * tileScale;
	float y = (row)*spriteWH * tileScale;
	float spriteSizeY = scaleV2f.y * textureSize.y;
	float cntrFactorY = ((spriteWH * tileScale) - spriteSizeY);	// to align to lower side of the tile.
	float cntrFactorX = cntrFactorY * 0.5f;						//to center horizontally

	setPosition(x + cntrFactorX, y + cntrFactorY);
	velocity->setVelocity(0.0f,0.0f);
}

void Player::draw(Window* window)
{
	colliderplayer->draw(window);
	graph->draw(window);
}

