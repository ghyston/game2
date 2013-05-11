#include "GlobalData.h"
#include "Renderer/SceneObject.h"

bool GlobalData::init_scene(/*const char* data*/)
{
    player = new Player();
        
	//player->coords = Vec2f(0.0f, 0.0f);
	
    return true;
}

Player* GlobalData::get_player()
{
    return player;
}