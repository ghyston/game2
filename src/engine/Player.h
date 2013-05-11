/* 
 * File:   Player.h
 * Author: Hyston
 *
 * Created on 11 Май 2013 г., 7:14
 */

#ifndef PLAYER_H
#define	PLAYER_H

#include "Renderer/SceneObject.h"

class Player : public BaseRenderable 
{
private:
	int health;

public:
	
	Player() : BaseRenderable()
	{
		health = 100;
		vertexes = new float[6];
		vertexes[0] = -0.3f;
		vertexes[1] =  0.0f;
		vertexes[2] =  0.0f;
		vertexes[3] =  0.5f;
		vertexes[4] =  0.3f;
		vertexes[5] =  0.0f;
    
		vertexes_count = 3;
		
		 color[0] = 1.0f;
		 color[1] = 0.0f;
		 color[2] = 0.0f;
	}
	
	void Draw()
	{
		BaseRenderable::Draw();
		angle += 1.0f;
	}

};


#endif	/* PLAYER_H */

