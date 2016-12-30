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
		-w2, -h2,
		w2, -h2,
		w2, h2,
		-w2, h2,
	};
	
	GLfloat textureCoords[8] = {
		0.0, 0.0,
		1.0, 0.0,
		1.0, 1.0,
		0.0, 1.0,
	};
	
	GLuint indices[6] = {
		0, 1, 2,
		2, 3, 0
	};
	
	// Use a Vertex Array Object
	/*glGenVertexArrays(1, &m_VAO);
	glBindVertexArray(m_VAO);
	
	glGenBuffers(4, m_Buffers);
	
	// Allocate space for vertex positions and texture coordinates
	glBindBuffer(GL_ARRAY_BUFFER, m_Buffers[POS_VB]);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertexes) + sizeof(_textureCoords), NULL, GL_STATIC_DRAW);
	
	// Transfer the vertex positions:
	glBufferSubData(GL_ARRAY_BUFFER, 0, sizeof(vertexes), vertexes);
	
	// Transfer the texture coordinates:
	glBufferSubData(GL_ARRAY_BUFFER, sizeof(vertexes), sizeof(_textureCoords), _textureCoords);
	
	// Transfer the data from indices to eab
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_Buffers[INDEX_BUFFER]);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(_indices), _indices, GL_STATIC_DRAW);
	
	glBindBuffer(GL_ARRAY_BUFFER, 0);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
	
	glBindVertexArray(0);*/
	
	size_t vSize = sizeof(vertexes);
	size_t tSize = sizeof(textureCoords);
	size_t iSize = sizeof(indices);
	
	_vao.init(vertexes, vSize, textureCoords, tSize, indices, iSize);
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
	shader = 0;
}

void TextureRectRenderable::set_shader(GLuint program)
{
	shader = program;
	gvPositionHandle = glGetAttribLocation(shader, "vPosition");
	gModelHandle = glGetUniformLocation(shader, "Model");
	gFragColorHandle = glGetUniformLocation(shader, "fragColor");
	gTextureCoordHandle = glGetAttribLocation(shader, "texture_coord");
	gTexture1Handle = glGetUniformLocation(shader, "texture1");
	gTexture2Handle = glGetUniformLocation(shader, "texture2");
	
	// Then bind the uniform samplers to texture units:
	glUseProgram(shader);
	glUniform1i(gTexture1Handle, 0); //@todo: google detaily, what 0,1 means
	glUniform1i(gTexture2Handle, 1);
}

void TextureRectRenderable::Draw()
{
	//glBindBuffer(GL_ARRAY_BUFFER, m_Buffers[POS_VB]);
	//glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_Buffers[INDEX_BUFFER]);
	_vao.bind();
	
	model_matrix_rotate->RotateZ(angle);
	model_matrix_scale->Scale(scale, scale, scale);
	model_matrix_translate->Translate(coords.x, coords.y, 0.0f);
	model_matrix->Identity();
	temp_matrix->Identity();
	matrixMultiply(*model_matrix_rotate, *model_matrix_scale, *temp_matrix);
	matrixMultiply(*model_matrix_translate, *temp_matrix, *model_matrix);
	
	glEnable(GL_TEXTURE_2D);
	
	glUseProgram(shader);
	
	glActiveTexture(GL_TEXTURE0 + 0); // Texture unit 0
	glBindTexture(GL_TEXTURE_2D, texture1);
	
	glActiveTexture(GL_TEXTURE0 + 1); // Texture unit 1
	glBindTexture(GL_TEXTURE_2D, texture2);
	
	glUniform3f(gFragColorHandle, color.r, color.g, color.b);
	glUniformMatrix4fv(gModelHandle, 1, GL_FALSE, model_matrix->get_val());
	
	glVertexAttribPointer(gvPositionHandle, 2, GL_FLOAT, GL_FALSE, 0, 0);
	glEnableVertexAttribArray(gvPositionHandle);
	
	glVertexAttribPointer(gTextureCoordHandle, 2, GL_FLOAT, GL_FALSE, 0,
						  (GLvoid *)(sizeof(GLfloat) * 8));
	glEnableVertexAttribArray(gTextureCoordHandle);
	
	glDrawElements( GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
	
	
	_vao.unbind();
	glBindTexture(GL_TEXTURE_2D, 0);
	glDisable(GL_TEXTURE_2D);
	//glBindVertexArray(0);
	glBindBuffer(GL_ARRAY_BUFFER, 0);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
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
