#include "BaseTower.h"

//TODO: realization is very similar to Button. Think different!
bool BaseTower::is_touched(Vec2f touched_coords)
{
	bool result = 
	 ((touched_coords.x > (coords.x - width / 2)) && 
       (touched_coords.x < (coords.x + width / 2)) &&
       (touched_coords.y > (coords.y - height / 2)) &&
       (touched_coords.y < (coords.y + height / 2)));
    
    return result;
}
