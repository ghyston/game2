//
//  main.cpp
//  Game2
//
//  Created by Stepanov Ilia on 9/27/13.
//  Copyright (c) 2013 Stepanov Ilia. All rights reserved.
//

#include <iostream>
#include <GLUT/glut.h>
#include "../../../../src/engine/GameEngine.h"

GameEngine * instance;

void idle();
void display();
void reshape(int width, int height);

int main(int argc, char ** argv)
{
    glutInit(&argc, argv);
    glutInitWindowSize(512, 512);
    glutInitDisplayMode(GLUT_3_2_CORE_PROFILE | GLUT_RGBA | GLUT_DEPTH | GLUT_DOUBLE);
    glutCreateWindow("Game 2");
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutIdleFunc(idle);
    
    GameEngine::create_instance();
    instance = GameEngine::get_instance();
    instance->init(512, 512);
    
    glutMainLoop();
    
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
    glutSwapBuffers();

}

void reshape(int width, int height)
{
    //@todo: reshape engine renderer!
}
