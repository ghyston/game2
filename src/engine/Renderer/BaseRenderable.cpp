#include "BaseRenderable.h"

Matrix4f* BaseRenderable::model_matrix = new Matrix4f();
Matrix4f* BaseRenderable::model_matrix_rotate = new Matrix4f();
Matrix4f* BaseRenderable::model_matrix_scale = new Matrix4f();
Matrix4f* BaseRenderable::model_matrix_translate = new Matrix4f();
Matrix4f* BaseRenderable::temp_matrix = new Matrix4f();
    
BaseRenderable::BaseRenderable()
{
    coords = Vec2f(0.0f, 0.0f);
    angle = 0.0f;
    scale = 1.0f;
    draw_type = GL_TRIANGLE_STRIP;
}

void BaseRenderable::set_shader(GLuint program)
{
    shader = program;
    gvPositionHandle = glGetAttribLocation(shader, "vPosition");
    gModelHandle = glGetUniformLocation(shader, "Model");
    gFragColorHandle = glGetUniformLocation(shader, "fragColor");
}

void BaseRenderable::Draw()
{    
    model_matrix_rotate->RotateZ(angle);
    model_matrix_scale->Scale(scale, scale, scale);
    model_matrix_translate->Translate(coords.x, coords.y, 0.0f);
    model_matrix->Identity();
    temp_matrix->Identity();
    matrixMultiply(*model_matrix_rotate, *model_matrix_scale, *temp_matrix);
    matrixMultiply(*model_matrix_translate, *temp_matrix, *model_matrix);
    
    glUseProgram(shader);
    glUniform3f(gFragColorHandle, color[0], color[1], color[2]);

    glVertexAttribPointer(gvPositionHandle, 2, GL_FLOAT, GL_FALSE, 0, vertexes);
    glEnableVertexAttribArray(gvPositionHandle);

    glUniformMatrix4fv(gModelHandle, 1, GL_FALSE, model_matrix->get_val());
    glDrawArrays(draw_type, 0, vertexes_count);
}

BaseRenderable::~BaseRenderable()
{
	//TODO: delete matrixes!
	//delete [] vertexes;
}