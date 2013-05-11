/* 
 * File:   GlobalData.h
 * Author: Hyston
 *
 * Created on 11 Май 2013 г., 7:02
 */

#ifndef GLOBALDATA_H
#define	GLOBALDATA_H

#include "Player.h"

class GlobalData
{
private:
//    Scene * scene;
    Player * player;
    
public:
    
    bool init_scene(/*const char * data*/);
	
	Player* get_player();
};



#endif	/* GLOBALDATA_H */

