#include <stdio.h>
#include <windows.h>
#include "glut.h"
#include "gl.h"
#include "glext.h"
#include <math.h>


void Draw()
{	

}

void Idle()
{
	
}

void KeyPress(unsigned char key, int x, int y)
{	
	switch (key)
    {
        case 'q':
            exit(0);	
	}
}

void MouseClick(int button, int state, int x, int y)
{
	
}
	

int main(int argc, char** argv)
{
	glutInit(&argc, argv);
    glutInitWindowSize(400,400);
    glutInitWindowPosition(10,10);
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE);

    glutCreateWindow("Towers win");

    glutDisplayFunc(Draw);    
    glutIdleFunc(Idle);
	glutKeyboardFunc(KeyPress);
	glutMouseFunc(MouseClick);

	


	glutMainLoop();	

    return EXIT_SUCCESS;
}
