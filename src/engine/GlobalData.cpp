#include "GlobalData.h"
#include "Renderer/SceneObject.h"

bool GlobalData::init_scene()
{	
	camera = new Camera();
    return true;
}