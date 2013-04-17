#ifndef __PLAYER_H__
#define __PLAYER_H__

#include "GameEngine.h"

class Player : public Creature
{
public:
	virtual void move(HysVec2f diff_pos);

};

#endif //__PLAYER_H__