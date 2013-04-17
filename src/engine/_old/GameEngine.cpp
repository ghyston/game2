#include "GameEngine.h"

GameEngine* GameEngine::instance = (GameEngine*)0;

GameEngine::GameEngine()
{
	gl_wrapper = new GLwrapper();
	controller = new BaseController();
	player = new Player();
}


GameEngine* GameEngine::get_instance()
{
	return instance;
}

bool GameEngine::create_instance()
{
	instance = new GameEngine();
	return true;
}


void GameEngine::draw_all()
{
	//clear frame
	glClear(GL_COLOR_BUFFER_BIT);
    glClearColor(1.0f, 1.0f, 1.0f, 1.0f);

	//draw game field
    glViewport(0.0f, 0.0f, 640.0f, 480.0f);

	//TODO: make it global!
	float ratio = 640.0f / 480.0f;
	float zoom = 1.0f;

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(
		camera.pos.x - camera.zoom * camera.ratio, camera.pos.x + camera.zoom * camera.ratio, 
		camera.pos.y - camera.zoom * camera.ratio, camera.pos.y + camera.zoom * camera.ratio, 
		0.0f, 1.0f);	

	gl_wrapper->draw_grid();

	glColor3f(1.0f, 0.0f, 0.0f);
	glBegin(GL_LINES);
		glVertex2f(-1.0f, -1.0f);
		glVertex2f( 1.0f,  1.0f);
	glEnd();

	//TODO: draw game here!	
	glutSwapBuffers();
}

void GameEngine::move_all()
{

}


void GameEngine::to_controller(BaseController::Event event)
{
	controller->proceed(event);
}