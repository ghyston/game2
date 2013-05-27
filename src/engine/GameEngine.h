#ifndef __GAMEENGINE_H__
#define __GAMEENGINE_H__

#include "Renderer/Renderer.h"
#include "GlobalData.h"
#include "Gui/GameGui.h"
#include "Gui/TouchController.h"

/**
* Main game manager. Singletone.
*/
class GameEngine
{
private:

	//Work with OpenGL
	Renderer * renderer;
	
	//All data
	static GlobalData* global_data;

	//Instance.
	static GameEngine* instance;
	
	//Game gui, cap.
	static GameGui* game_gui;
	
	static TouchController* controller;

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
	
	//TODO: make it singletone and remove from this!!
	static GlobalData* get_data();
	
	//Return pointer to game gui main class;
	static GameGui* get_gui();
	
	//TODO: make it to controller or something..
	static void process_touch(float x, float y, short touch_type);

	/**
	* Create game engine instance.
	*/
	static bool create_instance();

};

#endif //__GAMEENGINE_H__
