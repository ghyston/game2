#include <stdio.h>
#include "GlutWrapper.h"


void GlutWrapper::draw()
{
	GameEngine::get_instance()->draw_all();
}


void GlutWrapper::idle()
{
	GameEngine::get_instance()->move_all();
	glutPostRedisplay();
}


void GlutWrapper::reshape(int width, int height)
{

}


void GlutWrapper::key_down(unsigned char key, int x, int y)
{
	BaseController::Event event;

	switch (key)
    {
        case 'q':			
			//TODO: free some memory here?
            exit(0);
        break;

		case 's':
			event.device = BaseController::Event::Devices::keyboard;
			event.key = BaseController::Event::Keys::arrow_down;
			event.type = BaseController::Event::Types::press;
			GameEngine::get_instance()->to_controller(event);
		break;

		case 'w':
			event.device = BaseController::Event::Devices::keyboard;
			event.key = BaseController::Event::Keys::arrow_up;
			event.type = BaseController::Event::Types::press;
			GameEngine::get_instance()->to_controller(event);
		break;

		case 'a':
			event.device = BaseController::Event::Devices::keyboard;
			event.key = BaseController::Event::Keys::arrow_left;
			event.type = BaseController::Event::Types::press;
			GameEngine::get_instance()->to_controller(event);
		break;

		case 'd':
			BaseController::Event event;
			event.device = BaseController::Event::Devices::keyboard;
			event.key = BaseController::Event::Keys::arrow_right;
			event.type = BaseController::Event::Types::press;
			GameEngine::get_instance()->to_controller(event);
		break;
	}
}


/*void GlutWrapper::set_engine(GameEngine* engine)
{
	GlutWrapper::game_engine = engine;
}*/


void GlutWrapper::init(int argc, char** argv)
{
	//initialize glut, create window
	glutInit(&argc, argv);
    glutInitWindowSize(640, 480); //TODO: spec window sizes somewhere!
    glutInitWindowPosition(10, 10); //TODO: create fullscreen on futurum!
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE);
    glutCreateWindow("Game 1");	 //TODO: get game name from engine!

	//bind glut callbacks
    glutDisplayFunc(GlutWrapper::draw);
    glutKeyboardFunc(GlutWrapper::key_down);
    glutIdleFunc(GlutWrapper::idle);
	glutReshapeFunc(GlutWrapper::reshape);
}


void GlutWrapper::start()
{
	glutMainLoop();
}