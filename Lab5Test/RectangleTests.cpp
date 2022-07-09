#include "pch.h"
#include "../lab5/include/utils/Rectangle.h"

namespace ArithmeticOperations {

	TEST(RectangleOperations, Init) {
		Rectangle r1;
		EXPECT_EQ(r1.getTopLeft().x, 0.0f);
		EXPECT_EQ(r1.getTopLeft().y, 0.0f);
		EXPECT_EQ(r1.getBottomRight().x, 0.0f);
		EXPECT_EQ(r1.getBottomRight().y, 0.0f);
	}

	TEST(RectangleOperations, InitVal) {
		Rectangle r1({ 0.5f, 3.1f }, { 4.5f, -1.0f });
		EXPECT_EQ(r1.getTopLeft().x, 0.5f);
		EXPECT_EQ(r1.getTopLeft().y, 3.1f);
		EXPECT_EQ(r1.getBottomRight().x, 4.5f);
		EXPECT_EQ(r1.getBottomRight().y, -1.0f);
	}

	TEST(RectangleOperations, SettVal) {
		Rectangle r1;
		r1.setTopLeft({ 0.5f, 3.1f });
		r1.setBottomRight({ 4.5f, -1.0f });
		EXPECT_EQ(r1.getTopLeft().x, 0.5f);
		EXPECT_EQ(r1.getTopLeft().y, 3.1f);
		EXPECT_EQ(r1.getBottomRight().x, 4.5f);
		EXPECT_EQ(r1.getBottomRight().y, -1.0f);
	}

	TEST(RectangleOperations, Inside) {
		// IX.A Test that checks the Rectangle::inside function
		//      This function determines if a point (float x, float y; passed by parameter) is inside 
		//      a rectangle object, returning true if that's the case. 
		Rectangle r1({ 0.5f, 3.1f }, { 4.5f, -1.0f });
		Vector2f vector1 = {0.9f,0.1f};
		EXPECT_TRUE(r1.inside(vector1));
		
	}

	TEST(RectangleOperations, Intersects) {
		// IX.C Test that checks the Rectangle::intersects function
		//      This function determines if a rectangle passed by parameter) intersects/overlaps with the
		//      rectangle object that this function is called upon, returning true if that's the case. 
		Rectangle r1({ 0.5f, 3.1f }, { 4.5f, -1.0f });
		Rectangle r2({ 1.0f, 3.0f }, { 2.0f, 2.0f });
		EXPECT_TRUE(r2.intersects(r1));
	}


}