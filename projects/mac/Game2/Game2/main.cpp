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
  /*  glutInit(&argc, argv);
    glutInitWindowSize(512, 512);
    glutInitDisplayMode(GLUT_3_2_CORE_PROFILE | GLUT_RGBA | GLUT_DEPTH | GLUT_DOUBLE);
    glutCreateWindow("Game 2");
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutIdleFunc(idle);
    
    GameEngine::create_instance();
    instance = GameEngine::get_instance();
    instance->init(512, 512);*/
    
//    glutMainLoop();
    
    GLFWwindow* window;
    
    //glfwSetErrorCallback(error_callback);
    
    if (!glfwInit())
        exit(EXIT_FAILURE);
    
    window = glfwCreateWindow(640, 480, "Simple example", NULL, NULL);
    if (!window)
    {
        glfwTerminate();
        exit(EXIT_FAILURE);
    }
    
    glfwMakeContextCurrent(window);
    
    int error = 0;
    
    
   // glfwSetKeyCallback(window, key_callback);
    
    GameEngine::create_instance();
    
    if ( (error = glGetError()) != GL_NO_ERROR )
    {
        int i = 3;
    }
    
    instance = GameEngine::get_instance();
    instance->init(640, 480);
    
    if ( (error = glGetError()) != GL_NO_ERROR )
    {
        int i = 3;
    }
    
    while (!glfwWindowShouldClose(window))
    {
        float ratio;
        int width, height;
        
        glfwGetFramebufferSize(window, &width, &height);
     /*   ratio = width / (float) height;
        
        glViewport(0, 0, width, height);
        glClear(GL_COLOR_BUFFER_BIT);
        
        glMatrixMode(GL_PROJECTION);
        glLoadIdentity();
        glOrtho(-ratio, ratio, -1.f, 1.f, 1.f, -1.f);
        glMatrixMode(GL_MODELVIEW);
        
        glLoadIdentity();
        glRotatef((float) glfwGetTime() * 50.f, 0.f, 0.f, 1.f);
        
        glBegin(GL_TRIANGLES);
        glColor3f(1.f, 0.f, 0.f);
        glVertex3f(-0.6f, -0.4f, 0.f);
        glColor3f(0.f, 1.f, 0.f);
        glVertex3f(0.6f, -0.4f, 0.f);
        glColor3f(0.f, 0.f, 1.f);
        glVertex3f(0.f, 0.6f, 0.f);
        glEnd();*/
        
        if ( (error = glGetError()) != GL_NO_ERROR )
        {
            int i = 3;
        }
        
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
