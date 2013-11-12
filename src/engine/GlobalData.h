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
#include "GamePlay/Game2Logic.h"

class GlobalData
{
private:
    
public:
	
	Game2Logic logic;
	
	Camera* camera;
	
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
	
	Vec2f convert_coordinates(Vec2f screen_coord);
	
};



#endif	/* GLOBALDATA_H */

