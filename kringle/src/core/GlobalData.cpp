#include <vector>

#include "core/GlobalData.h"
#include "core/GameEngine.h"
#include "common/ThreadLock.h"

unsigned int GlobalData::PLAYER_ID_1 = 1;
unsigned int GlobalData::PLAYER_ID_2 = 2;


bool GlobalData::init_scene()
{	
	camera = new Camera();

	//Game2Logic::initTestScene() was here
	
    return true;
}

Vec2f GlobalData::convert_coordinates(Vec2f screen_coord)
{
	Vec2f result;
	 // @todo: too expencive every time
	
	result.x = 2.0f * screen_coord.x / screen.width - 1.0f + camera->coords.x;
	result.y = ( screen.height - 2.0f * screen_coord.y ) * screen.ratio / screen.height;
	result.y += camera->coords.y;
	
	return result;
}
