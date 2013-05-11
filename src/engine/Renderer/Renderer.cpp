#include "Renderer.h"
#include "shaders.h"
#include "BaseRenderable.h"
#include "Grid.h"
#include "../GameEngine.h"

void Renderer::init(int width, int height)
{
    screen_width = width;
    screen_height = height;
    glViewport(0, 0, screen_width, screen_height);
    init_shaders();

    grid.set_shader(simple_shader);
    grid.generate_grid();
    Player* player = GameEngine::get_data()->get_player();
    player->set_shader(simple_shader);

}

void Renderer::render_frame()
{
    glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
    glClear(GL_DEPTH_BUFFER_BIT | GL_COLOR_BUFFER_BIT);
    setup_ortho(-1.0f, 1.0f, -1.5f, 1.5f);
    //glUseProgram(simple_shader);  
    
    //Draw grid.
    grid.Draw();
    //Draw player
    Player* player = GameEngine::get_data()->get_player();    
    player->Draw();
}

void Renderer::init_shaders()
{
    simple_shader = Shader::createProgram(gVertexShader, gFragmentShader);
    gvPositionHandle = glGetAttribLocation(simple_shader, "vPosition");
}

void Renderer::setup_ortho(float left, float right, float bottom, float top, float near, float far)
{
    camera.setup_ortho(left, right, bottom, top, near, far);

    GLint projectionUniform = glGetUniformLocation(simple_shader, "Projection");
    glUniformMatrix4fv(projectionUniform, 1, GL_FALSE, camera.ortho->get_val()/*&ortho[0]*/);

}