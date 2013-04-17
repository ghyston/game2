#include <stdio.h>
#include <windows.h>
#include "GLUT/glut.h"
#include "GameEngine.h"
#include "GlutWrapper.h"

GlutWrapper*	glut_wrapper;


/**
 * Entry point.
 */
int main(int argc, char** argv)
{
	GameEngine::create_instance();	
	GameEngine::get_instance()->camera.set_ratio(640.0f / 480.0f);

	glut_wrapper = new GlutWrapper();	
	glut_wrapper->init(argc, argv);
	glut_wrapper->start();
	
	return 0;
}