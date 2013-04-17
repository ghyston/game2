#ifndef __GAMEENGINE_H__
#define __GAMEENGINE_H__


class Player;


#include "GLwrapper.h"
#include "GLUT/glut.h"
#include "BaseController.h"
#include "Camera.h"
#include "Creature.h"
#include "Player.h"

/**
* Main game manager. Singletone.
*/
class GameEngine
{
private:

	//Work with OpenGL
	GLwrapper* gl_wrapper;

	//Instance.
	static GameEngine* instance;

	//Private c-tor.
	GameEngine();

public:

	//TODO: do many things private!
	Player* player;
	Camera camera;
	BaseController* controller;	


	/**
	* Draw all objects.
	*/
	void draw_all();


	/**
	* Move all objects.
	*/
	void move_all();


	/**
	* Send event to controller.
	*/
	void to_controller(BaseController::Event event);

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