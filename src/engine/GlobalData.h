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
#include "Cursor.h"

class GlobalData
{
private:
    
public:
	
	// @todo: move it to types.h (when it would be created)
	typedef unsigned int PlayerID;
	
	Game2Logic logic;
	
	//@todo: Why we have pointer here?
	Camera* camera;
	
	Cursor cursor;
	
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
	
	
	//@todo: do this for more players, more flexibility!
	static unsigned int PLAYER_ID_1;
	static unsigned int PLAYER_ID_2;
	
	EntityPtr base_tower_player_1;
	EntityPtr base_tower_player_2;
	
};



#endif	/* GLOBALDATA_H */

