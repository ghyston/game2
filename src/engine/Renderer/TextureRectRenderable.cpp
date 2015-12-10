//
//  TextureRectRenderable.cpp
//  Game2
//
//  Created by Stepanov Ilia on 11/01/15.
//  Copyright (c) 2015 Stepanov Ilia. All rights reserved.
//

#include "TextureRectRenderable.h"

void TextureRectRenderable::setup_vertexes()
{
	float h2 = height / 2;
	float w2 = width / 2;
	
	
	// 1 square (made by 2 triangles) to be rendered
	GLfloat vertexes[8] = {
		-0.5, -0.5,
		0.5, -0.5,
		0.5, 0.5,
		-0.5, 0.5,
	};
	
	GLfloat _textureCoords[8] = {
		0.0, 0.0,
		1.0, 0.0,
		1.0, 1.0,
		0.0, 1.0,
	};
	
	GLuint _indices[6] = {
		0, 1, 2,
		2, 3, 0
	};
	
	
	/*vertexes = new float[8];
	vertexes[0] = -w2;
	vertexes[1] = -h2;
	
	vertexes[2] =  w2;
	vertexes[3] = -h2;
	
	vertexes[4] =  w2;
	vertexes[5] =  h2;
	
	vertexes[6] = -w2;
	vertexes[7] =  h2;
	
	_textureCoords = new float[8];
	
	_textureCoords[0] = 0.0;
	_textureCoords[1] = 0.0;
	
	_textureCoords[2] = 1.0;
	_textureCoords[3] = 0.0;
	
	_textureCoords[4] = 1.0;
	_textureCoords[5] = 1.0;
	
	_textureCoords[6] = 0.0;
	_textureCoords[7] = 1.0;
	
	_indices = new int[6];
	
	_indices[0] = 0;
	_indices[1] = 1;
	_indices[2] = 2;
	
	_indices[3] = 2;
	_indices[4] = 3;
	_indices[5] = 0;*/
	
	
	//vertexes_count = 4;
	
	// Use a Vertex Array Object
	glGenVertexArrays(1, &_vao);
	glBindVertexArray(_vao);
	
	glGenBuffers(1, &_vbo);
	
	// Allocate space for vertex positions and texture coordinates
	glBindBuffer(GL_ARRAY_BUFFER, _vbo);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertexes) + sizeof(_textureCoords), NULL, GL_STATIC_DRAW);
	
	// Transfer the vertex positions:
	glBufferSubData(GL_ARRAY_BUFFER, 0, sizeof(vertexes), vertexes);
	
	// Transfer the texture coordinates:
	glBufferSubData(GL_ARRAY_BUFFER, sizeof(vertexes), sizeof(_textureCoords), _textureCoords);
	
	// Create an Element Array Buffer that will store the indices array:
	glGenBuffers(1, &_eab);
	
	// Transfer the data from indices to eab
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, _eab);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(_indices), _indices, GL_STATIC_DRAW);
	
	glVertexAttribPointer(gvPositionHandle, 2, GL_FLOAT, GL_FALSE, 0, 0);
	glEnableVertexAttribArray(gvPositionHandle);
	
	//	glVertexAttribPointer(texture_coord_attribute, 2, GL_FLOAT, GL_FALSE, 0, (GLvoid *)sizeof(vertices_position));
	glVertexAttribPointer(gTextureHandle, 2, GL_FLOAT, GL_FALSE, 0, (GLvoid *)(sizeof(vertexes)));
	glEnableVertexAttribArray(gTextureHandle);
}


Matrix4f* TextureRectRenderable::model_matrix = new Matrix4f();
Matrix4f* TextureRectRenderable::model_matrix_rotate = new Matrix4f();
Matrix4f* TextureRectRenderable::model_matrix_scale = new Matrix4f();
Matrix4f* TextureRectRenderable::model_matrix_translate = new Matrix4f();
Matrix4f* TextureRectRenderable::temp_matrix = new Matrix4f();

TextureRectRenderable::TextureRectRenderable()
{
	coords = Vec2f(0.0f, 0.0f);
	angle = 0.0f;
	scale = 1.0f;
	draw_type = GL_TRIANGLE_STRIP;
	//vertexes = NULL;
	shader = 0;
}

void TextureRectRenderable::set_shader(GLuint program)
{
	shader = program;
	gvPositionHandle = glGetAttribLocation(shader, "vPosition");
	gModelHandle = glGetUniformLocation(shader, "Model");
	gFragColorHandle = glGetUniformLocation(shader, "fragColor");
	gTextureHandle = glGetAttribLocation(shader, "texture_coord");
}

void TextureRectRenderable::Draw()
{
	model_matrix_rotate->RotateZ(angle);
	model_matrix_scale->Scale(scale, scale, scale);
	model_matrix_translate->Translate(coords.x, coords.y, 0.0f);
	model_matrix->Identity();
	temp_matrix->Identity();
	matrixMultiply(*model_matrix_rotate, *model_matrix_scale, *temp_matrix);
	matrixMultiply(*model_matrix_translate, *temp_matrix, *model_matrix);

	glBindVertexArray(_vao);
	
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, _texture);

	
	glUseProgram(shader);
	glUniform3f(gFragColorHandle, color.r, color.g, color.b);
	glUniformMatrix4fv(gModelHandle, 1, GL_FALSE, model_matrix->get_val());
	
	glVertexAttribPointer(gvPositionHandle, 2, GL_FLOAT, GL_FALSE, 0, 0);
	glEnableVertexAttribArray(gvPositionHandle);
	
	glVertexAttribPointer(gTextureHandle, 2, GL_FLOAT, GL_FALSE, 0, (GLvoid *)(sizeof(GLfloat) * 8));
	glEnableVertexAttribArray(gTextureHandle);
	
	//glDrawArrays(draw_type, 0, vertexes_count);
	
	
	glDrawElements( GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
	
	glBindTexture(GL_TEXTURE_2D, 0);
	glDisable(GL_TEXTURE_2D);
	glBindVertexArray(0);
}

void TextureRectRenderable::delete_vertexes()
{
	/*if(vertexes != NULL)
	{
		delete [] vertexes;
	}*/
}

void TextureRectRenderable::SetColor(Color3f& color)
{
	this->color = color;
}

void TextureRectRenderable::SetColor(float red, float green, float blue)
{
	this->color = Color3f(red, green, blue);
}

TextureRectRenderable::~TextureRectRenderable()
{
	//TODO: delete matrixes!
	//delete [] vertexes;
}