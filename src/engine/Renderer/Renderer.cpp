#include "Renderer.h"
#include "shaders.h"

void Renderer::init(int width, int height)
{
	screen_width = width;
	screen_height = height;
	glViewport(0, 0, screen_width, screen_height);
	init_shaders();
}

void Renderer::render_frame()
{
	glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
	glClear( GL_DEPTH_BUFFER_BIT | GL_COLOR_BUFFER_BIT);	
	draw_grid();
}

void Renderer::init_shaders()
{
	simple_shader = Shader::createProgram(gVertexShader, gFragmentShader);
	gvPositionHandle = glGetAttribLocation(simple_shader, "vPosition");
}

void Renderer::draw_grid()
{
	const GLfloat gTriangleVertices[] = { 0.0f, 0.5f, -0.5f, -0.5f, 0.5f, -0.5f, 0.0f, 0.0f };
	glUseProgram(simple_shader);
	
	glVertexAttribPointer(gvPositionHandle, 2, GL_FLOAT, GL_FALSE, 0, gTriangleVertices);    
    glEnableVertexAttribArray(gvPositionHandle);   
	
	setup_ortho(-1.0f, 1.0f, -1.5f, 1.5f);
	
    
    glDrawArrays(GL_LINE_LOOP, 0, 4);
}

void Renderer::setup_ortho(float left, float right, float bottom, float top, float near, float far)
{
	float a = 2.0f / (right - left);
	float b = 2.0f / (top - bottom);
	float c = -2.0f / (far - near);
	
	float tx = - (right + left)/(right - left);
	float ty = - (top + bottom)/(top - bottom);
	float tz = - (far + near)/(far - near);
	
	float ortho[16] = {
		a, 0, 0, tx,
		0, b, 0, ty,
		0, 0, c, tz,
		0, 0, 0, 1
	};
	
	GLint projectionUniform = glGetUniformLocation(simple_shader, "Projection");
	glUniformMatrix4fv(projectionUniform, 1, GL_FALSE, &ortho[0]);

}
