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
    
    GameEngine::create_instance();
       instance = GameEngine::get_instance();
    instance->init(640, 480);
    
    while (!glfwWindowShouldClose(window))
    {
        //float ratio;
        //int width, height;
        
        //glfwGetFramebufferSize(window, &width, &height);
        instance->step();
        
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
