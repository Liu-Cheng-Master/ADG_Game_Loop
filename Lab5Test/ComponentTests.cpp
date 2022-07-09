#include "pch.h"
#include "../../AGD_1_D/lab5/include/components/Components.h"
#include "../../AGD_1_D/lab5/include/entities/Player.h"
#include "../../AGD_1_D/lab5/include/entities/StaticEntities.h"
#include "../../AGD_1_D/lab5/include/entities/Fire.h"
#include "../../AGD_1_D/lab5/include/components/GraphicsComponent.h"


TEST(Components, AddPlayer)
{
	std::shared_ptr<Player> player = std::make_shared<Player>();
	auto& bitmask = player->getComponentSet();

	EXPECT_TRUE(bitmask.getBit(static_cast<int>(ComponentID::INPUT)));
	EXPECT_TRUE(bitmask.getBit(static_cast<int>(ComponentID::POSITION)));
	EXPECT_TRUE(bitmask.getBit(static_cast<int>(ComponentID::VELOCITY)));
	EXPECT_TRUE(bitmask.getBit(static_cast<int>(ComponentID::COLLIDER)));

	EXPECT_FALSE(bitmask.getBit(static_cast<int>(ComponentID::TTL)));
	EXPECT_FALSE(bitmask.getBit(static_cast<int>(ComponentID::GRAPH)));

	player->init("D:/AdvancedGameDev/AGD_Gameloop/AGD_1_D/lab5/img/SpriteSheetDataTest.txt", std::make_shared<SpritesheetGraphics>());
	EXPECT_TRUE(bitmask.getBit(static_cast<int>(ComponentID::GRAPH)));
}

TEST(Components, AddPotion)
{
	std::shared_ptr<Potion> potion = std::make_shared<Potion>();

	auto& bitmask = potion->getComponentSet();

	EXPECT_FALSE(bitmask.getBit(static_cast<int>(ComponentID::INPUT)));
	EXPECT_TRUE(bitmask.getBit(static_cast<int>(ComponentID::POSITION)));
	EXPECT_FALSE(bitmask.getBit(static_cast<int>(ComponentID::VELOCITY)));
	EXPECT_TRUE(bitmask.getBit(static_cast<int>(ComponentID::COLLIDER)));
	EXPECT_FALSE(bitmask.getBit(static_cast<int>(ComponentID::TTL)));
	EXPECT_FALSE(bitmask.getBit(static_cast<int>(ComponentID::GRAPH)));

	potion->init("D:/AdvancedGameDev/AGD_Gameloop/AGD_1_D/lab5/img/potion.png", std::make_shared<SimplespriteGraphics>(1.0f));
	EXPECT_TRUE(bitmask.getBit(static_cast<int>(ComponentID::GRAPH)));
}

TEST(Components, AddLog)
{
	std::shared_ptr<Log> log = std::make_shared<Log>();

	auto& bitmask = log->getComponentSet();

	EXPECT_FALSE(bitmask.getBit(static_cast<int>(ComponentID::INPUT)));
	EXPECT_TRUE(bitmask.getBit(static_cast<int>(ComponentID::POSITION)));
	EXPECT_FALSE(bitmask.getBit(static_cast<int>(ComponentID::VELOCITY)));
	EXPECT_TRUE(bitmask.getBit(static_cast<int>(ComponentID::COLLIDER)));
	EXPECT_FALSE(bitmask.getBit(static_cast<int>(ComponentID::TTL)));
	EXPECT_FALSE(bitmask.getBit(static_cast<int>(ComponentID::GRAPH)));

	log->init("D:/AdvancedGameDev/AGD_Gameloop/AGD_1_D/lab5/img/log.png", std::make_shared<SimplespriteGraphics>(1.0f));
	EXPECT_TRUE(bitmask.getBit(static_cast<int>(ComponentID::GRAPH)));
}


TEST(Components, AddFire)
{
	std::shared_ptr<Fire> fire = std::make_shared<Fire>();

	auto& bitmask = fire->getComponentSet();

	EXPECT_FALSE(bitmask.getBit(static_cast<int>(ComponentID::INPUT)));
	EXPECT_TRUE(bitmask.getBit(static_cast<int>(ComponentID::POSITION)));
	EXPECT_TRUE(bitmask.getBit(static_cast<int>(ComponentID::VELOCITY)));
	EXPECT_FALSE(bitmask.getBit(static_cast<int>(ComponentID::COLLIDER)));
	EXPECT_TRUE(bitmask.getBit(static_cast<int>(ComponentID::TTL)));
	EXPECT_FALSE(bitmask.getBit(static_cast<int>(ComponentID::GRAPH)));

	fire->init("D:/AdvancedGameDev/AGD_Gameloop/AGD_1_D/lab5/img/fire.png", std::make_shared<SimplespriteGraphics>(1.0f));
	EXPECT_TRUE(bitmask.getBit(static_cast<int>(ComponentID::GRAPH)));
}