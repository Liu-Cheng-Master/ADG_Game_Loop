#include "../../include/utils/Rectangle.h"


bool Rectangle::inside(float x, float y) const
{
    // IX.B Implement this function, that returns true if the point <x,y> is inside this rectangle.
    if (x >= std::min(topLeft.x, bottomRight.x) &&
        x <= std::max(topLeft.x, bottomRight.x) &&
        y >= std::min(topLeft.y, bottomRight.y) &&
        y <= std::max(topLeft.y, bottomRight.y))
    {
        return true;
    }
    return false;
        
}

bool Rectangle::intersects(const Rectangle& rect) const
{
    // IX.D Implement this function, that returns true if the rectangle "rect" overlaps with this rectangle.

    //return (rect.inside(bottomRight) || rect.inside(topLeft) || inside(rect.topLeft) || inside(rect.bottomRight));


    /*
    if (this->topLeft.x + (this->bottomRight.x - this->topLeft.x) > rect.topLeft.x &&
        rect.topLeft.x + (rect.bottomRight.x - rect.topLeft.x) > this->topLeft.x &&
        this->topLeft.y + (this->topLeft.y - this->bottomRight.y) > rect.topLeft.y &&
        rect.topLeft.y + (rect.topLeft.y - rect.bottomRight.y) > this->topLeft.y)
    {
        return true;
    }
    else
    {
        return false;
    }
    */
    if (inside(rect.bottomRight) || inside(rect.topLeft) || rect.inside(bottomRight) || rect.inside(topLeft))
    {
        return true;
    }
    return false;
    
    //return false;
}

