#ifndef __GLUTWRAPPER_H__
#define __GLUTWRAPPER_H__

#include "GameEngine.h"

class GlutWrapper
{
private:

	/**
	* pointer to main engine instance.
	*/
	//static GameEngine* game_engine;

public:


	/**
	*	Init glut, bind callbacks.
	*/
	static void init(int argc, char** argv);


	/**
	*	Set engine as engine, that will answer on all glut callbacks.
	*/
	//void set_engine(GameEngine* engine);


	/**
	* GLUT callback. Call engine draw functional.
	*/
	static void draw();


	/**
	* GLUT callback. Call engine idle functional.
	*/
	static void idle();


	/**
	* GLUT callback. Call engine reshape functional.
	* TODO: or not?
	*/
	static void reshape(int width, int height);


	/**
	* GLUT callback. Call engine controllers functional.
	*/
	static void key_down(unsigned char key, int x, int y);


	/**
	* Start glut main loop.
	*/
	void start();
};

#endif //__GLUTWRAPPER_H__