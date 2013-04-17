#ifndef __CREATURE_H__
#define __CREATURE_H__

#include "HysVec2f.h"

class Creature
{
protected:
	HysVec2f pos;

public:

	virtual void move(HysVec2f diff_pos)
	{
		pos += diff_pos;
	}

	virtual ~Creature()
	{}

};

#endif //__CREATURE_H__