#include "GLwrapper.h"

void GLwrapper::draw_grid()
{
	//lines are from -10.0f to 10.0f
	const int count_lines = 100;	

	float step = 20.0f / count_lines;
	float half_count = step * count_lines / 2;

	glColor3f(0.8f, 0.8f, 0.8f);
	for(int i = 0; i < count_lines; i++)
	{
		//draw vertical lines
		glBegin(GL_LINES);
			glVertex2f(i * step - half_count, -10.0f);
			glVertex2f(i * step - half_count,  10.0f);
		glEnd();

		//draw horizontal lines
		glBegin(GL_LINES);
			glVertex2f(-10.0f, i * step - half_count);
			glVertex2f( 10.0f, i * step - half_count);
		glEnd();

		
	}
}