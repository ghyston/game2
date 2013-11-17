//
//  main.cpp
//  Game2
//
//  Created by Stepanov Ilia on 9/27/13.
//  Copyright (c) 2013 Stepanov Ilia. All rights reserved.
//

#include <iostream>
#include <GLFW/glfw3.h>
#include "../../../../src/engine/GameEngine.h"

GameEngine * instance;

void idle();
void display();
void reshape(int width, int height);

void My_Key_Callback(GLFWwindow* wnd, int key, int action, int, int)
{
	instance->process_input(key);
}


void MouseClickCallback(GLFWwindow * wnd, int button, int action, int mods)
{
	if(button != GLFW_MOUSE_BUTTON_LEFT)
		return;
	
	double mouse_x = 0.0f;
	double mouse_y = 0.0f;
	
	glfwGetCursorPos(wnd, &mouse_x, &mouse_y);
	
	//@todo: not good, may be other actions on da futurum
	int touch_type = (action == GLFW_PRESS) ?
	InputProcessor::TouchTypes::PRESS : InputProcessor::TouchTypes::RELEASE;
	instance->process_touch(0, touch_type, mouse_x, mouse_y);
}

void MouseCursorCallback(GLFWwindow * wnd, double x, double y)
{
	instance->process_touch(0, InputProcessor::TouchTypes::MOVE, x, y);
}


int main(int argc, char ** argv)
{
    GLFWwindow* window;
    
    //glfwSetErrorCallback(error_callback);
    
    if (!glfwInit())
        exit(EXIT_FAILURE);
    
    window = glfwCreateWindow(640, 480, "Game 2", NULL, NULL);
    if (!window)
    {
        glfwTerminate();
        exit(EXIT_FAILURE);
    }
    
    glfwMakeContextCurrent(window);
       // glfwSetKeyCallback(window, key_callback);
	
	glfwSetKeyCallback(window, My_Key_Callback);
	glfwSetMouseButtonCallback(window, MouseClickCallback);
	glfwSetCursorPosCallback(window, MouseCursorCallback);
    
    GameEngine::create_instance();
       instance = GameEngine::get_instance();
    instance->init(640, 480);
    
    while (!glfwWindowShouldClose(window))
    {
		try
		{
			instance->step();
		}
		catch (int error)
		{
			(void)0;
		}
        
        glfwSwapBuffers(window);
        glfwPollEvents();
    }
    
    glfwDestroyWindow(window);
    
    glfwTerminate();
    exit(EXIT_SUCCESS);
    
    return 0;
}


void display()
{
    instance->step();
    //glutSwapBuffers();
}

void idle()
{
    instance->step();
   // glutSwapBuffers();

}

void reshape(int width, int height)
{
    //@todo: reshape engine renderer!
}
