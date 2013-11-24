#ifndef __GAMEENGINE_H__
#define __GAMEENGINE_H__

#include "Renderer/Renderer.h"
#include "GlobalData.h"
#include "InputProcessor.h"

/**
* Main game manager. Singletone.
*/
class GameEngine
{
public:
	//Work with OpenGL
	static Renderer * renderer;
	
	//All data
	static GlobalData* global_data;

	//Instance.
	static GameEngine* instance;
	
	static InputProcessor* input_processor;
	
	//Private c-tor.
	GameEngine();
	
public:

	void init(int width, int height);

	/**
	* One game loop step.
	*/
	void step();

	/**
	* Get game engine instance.
	* Note: Call CreateInstance at first!!
	*/
	static GameEngine* get_instance();
	
	//TODO: make it singletone and remove from this!!
	static GlobalData* get_data();
	
	// @todo: renderer should be private, but shaders should be on g_data.
	static Renderer* get_renderer();
	
	//TODO: make it to controller or something..
	static void process_touch(int id, int touch_type, float x, float y);
	
	//@todo: test only?
	static void process_input(int key);

	/**
	* Create game engine instance.
	*/
	static bool create_instance();
	
};


#endif //__GAMEENGINE_H__
