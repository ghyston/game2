#ifndef __GAMEENGINE_H__
#define __GAMEENGINE_H__

#include "Renderer/Renderer.h"

/**
* Main game manager. Singletone.
*/
class GameEngine
{
private:

	//Work with OpenGL
	Renderer * renderer;

	//Instance.
	static GameEngine* instance;

	//Private c-tor.
	GameEngine();

public:

	void init(int width, int height);

	/**
	* Draw all objects.
	*/
	void draw_all();


	/**
	* Move all objects.
	*/
	void move_all();
	

	/**
	* Get game engine instance.
	* Note: Call CreateInstance at first!!
	*/
	static GameEngine* get_instance();

	/**
	* Create game engine instance.
	*/
	static bool create_instance();

};

#endif //__GAMEENGINE_H__
