#include "Renderer.h"
#include "shaders.h"

void Renderer::init(int width, int height)
{
	screen_width = width;
	screen_height = height;
	glViewport(0, 0, screen_width, screen_height);
	init_shaders();
	
	dump_object.coords = Vec2f(0.0f, 0.0f);
	dump_object.vertex[0] = 0.0f;
	dump_object.vertex[1] = 0.5f;
	dump_object.vertex[2] = -0.5f;
	dump_object.vertex[3] = -0.5f;
	dump_object.vertex[4] = 0.5f;
	dump_object.vertex[5] = -0.5f;
	dump_object.vertex[6] = 1.0f;
	dump_object.vertex[7] = 1.0f;	
	
}

void Renderer::render_frame()
{
	glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
	glClear( GL_DEPTH_BUFFER_BIT | GL_COLOR_BUFFER_BIT);	
	
	glUseProgram(simple_shader);
	setup_ortho(-1.0f, 1.0f, -1.5f, 1.5f);
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
	
	
	glVertexAttribPointer(gvPositionHandle, 2, GL_FLOAT, GL_FALSE, 0, dump_object.get_vertex());    
    glEnableVertexAttribArray(gvPositionHandle);   
	
	
	
    
    glDrawArrays(GL_LINE_LOOP, 0, 4);
}

void Renderer::setup_ortho(float left, float right, float bottom, float top, float near, float far)
{
	camera.setup_ortho(left, right, bottom, top, near, far);
	
	GLint projectionUniform = glGetUniformLocation(simple_shader, "Projection");
	glUniformMatrix4fv(projectionUniform, 1, GL_FALSE, camera.ortho->get_val()/*&ortho[0]*/);

}
