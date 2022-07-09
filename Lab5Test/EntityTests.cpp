#include "pch.h"
#include "../lab5/include/entities/Entity.h"
#include "../lab5/include/components/GraphicsComponent.h"

namespace Entities
{

	void defaultEntityMembers(const Entity& ent)
	{
		EXPECT_EQ(ent.getPosition().x, 0);
		EXPECT_EQ(ent.getPosition().y, 0);

		EXPECT_FALSE(ent.isSpriteSheetEntity());
		EXPECT_EQ(ent.getID(), 0);
	}
	
	TEST(Entity, Init)
	{
		Entity ent;
		Entity ent2(EntityType::FIRE);
		ent.init("D:/AdvancedGameDev/AGD_Gameloop/AGD_1_D/lab5/img/potion.png", std::make_shared<SimplespriteGraphics>(2.0f));
		ent2.init("D:/AdvancedGameDev/AGD_Gameloop/AGD_1_D/lab5/img/fire.png", std::make_shared<SimplespriteGraphics>(3.0f));
		EXPECT_EQ(ent.getEntityType(), EntityType::UNDEFINED);
		EXPECT_EQ(ent2.getEntityType(), EntityType::FIRE);
		defaultEntityMembers(ent);
		defaultEntityMembers(ent2);
	}
	
	TEST(Entity, SetPos)
	{
		Entity ent;
		ent.setPosition(1.0f, 2.0f);
		EXPECT_EQ(ent.getPosition().x, 1.0f);
		EXPECT_EQ(ent.getPosition().y, 2.0f);
	}

	TEST(Entity, InitSpreadSheetEntity)
	{
		Entity ent;
		ent.init("D:/AdvancedGameDev/AGD_Gameloop/AGD_1_D/lab5/img/SpriteSheetDataTest.txt",std::make_shared<SpritesheetGraphics>());

		EXPECT_TRUE(ent.isSpriteSheetEntity());
		EXPECT_EQ(ent.getGraphicCom()->getcurrentAnime()->getName(), "Idle");
		EXPECT_EQ(ent.getSpriteScale().x, 3.0f);
		EXPECT_EQ(ent.getSpriteScale().y, 3.0f);
		EXPECT_EQ(ent.getTextureSize().x, 32);
		EXPECT_EQ(ent.getTextureSize().y, 32);
	}
	
	TEST(Entity, InitSpriteEntity)
	{
		Entity ent;
		ent.init("D:/AdvancedGameDev/AGD_Gameloop/AGD_1_D/lab5/img/potion.png", std::make_shared<SimplespriteGraphics>(2.0f));

		EXPECT_EQ(ent.getSpriteScale().x, 2.0f);
		EXPECT_EQ(ent.getSpriteScale().y, 2.0f);
		EXPECT_EQ(ent.getTextureSize().x, 50);
		EXPECT_EQ(ent.getTextureSize().y, 50);
	}
	
}