#include "pch.h"
#include "../lab5/include/core/Game.h"
#include "../lab5/include/entities/StaticEntities.h"

namespace GameTests
{
	TEST(Game, Init)
	{
		// III.K (1/2) Uncomment the following instructions, which should now compile and pass:

		Game g;
		EXPECT_EQ(g.isPaused(), false);  
		EXPECT_EQ(g.getIDCounter(), 0); 
	}

	TEST(Game, AddEntity)
	{
		// III.K (2/2) Uncomment the following instructions, which should now compile and pass:

		Game g;
		std::shared_ptr<Log> log = g.buildEntityAt<Log>("../img/log.png", 0, 0);
		g.addEntity(log);

		std::shared_ptr<Entity> ent0 = g.getEntity(0);

		EXPECT_EQ(g.getIDCounter(), 1);  
		EXPECT_EQ(log, ent0);			
	}
};