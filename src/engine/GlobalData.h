/* 
 * File:   GlobalData.h
 * Author: Hyston
 *
 * Created on 11 Май 2013 г., 7:02
 */

#ifndef GLOBALDATA_H
#define	GLOBALDATA_H

#include <vector>
#include "Common/ThreadLock.h"
#include "Renderer/Camera.h"
#include "GamePlay/BaseTower.h"

class GlobalData
{
private:
    
public:
	
	Camera* camera;
	
	std::vector<BaseTower*> towers;
	
	MyCThreadLock* tower_mutex;
	
	struct DeviceScreen
	{		
		void setup(int screen_h, int screen_w)
		{
			width = screen_w;
			height = screen_h;
			ratio = (float)height / (float) width;
		}
		
		int width;
		int height;
		float ratio;
	} screen;	
    
    bool init_scene();
	
	//TODO: add to GamePlay!
	BaseTower* add_tower(Vec2f coords);
	
	BaseTower* touch_tower(Vec2f coords);
	
};



#endif	/* GLOBALDATA_H */

