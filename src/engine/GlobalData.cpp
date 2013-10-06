#include <vector>

#include "GlobalData.h"
#include "Common/ThreadLock.h"
#include "GameEngine.h"

bool GlobalData::init_scene()
{	
	camera = new Camera();	
    return true;
}
