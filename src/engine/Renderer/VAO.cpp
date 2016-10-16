//
//  VBO.cpp
//  Game2
//
//  Created by Stepanov Ilia on 22/09/2016.
//  Copyright © 2016 Stepanov Ilia. All rights reserved.
//

#include "VAO.hpp"

void VAO::init(GLfloat * vertexes, size_t vertexesSize,
			   GLfloat * textureCoords, size_t textureCoordsSize,
			   GLuint * indicies, size_t indiciesSize)
{
	// Use a Vertex Array Object
	glGenVertexArrays(1, &m_VAO);
	glBindVertexArray(m_VAO);
	
	glGenBuffers(4, m_Buffers);
	
	// Allocate space for vertex positions and texture coordinates
	glBindBuffer(GL_ARRAY_BUFFER, m_Buffers[POS_VB]);
	glBufferData(GL_ARRAY_BUFFER, vertexesSize + textureCoordsSize, NULL, GL_STATIC_DRAW);
	
	// Transfer the vertex positions:
	glBufferSubData(GL_ARRAY_BUFFER, 0, vertexesSize, vertexes);
	
	// Transfer the texture coordinates:
	glBufferSubData(GL_ARRAY_BUFFER, vertexesSize, textureCoordsSize, textureCoords);
	
	// Transfer the data from indices to eab
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_Buffers[INDEX_BUFFER]);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, indiciesSize, indicies, GL_STATIC_DRAW);
	
	glBindBuffer(GL_ARRAY_BUFFER, 0);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
	
	glBindVertexArray(0);
	
}

void VAO::bind()
{
	glBindBuffer(GL_ARRAY_BUFFER, m_Buffers[POS_VB]);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_Buffers[INDEX_BUFFER]);
}

void VAO::unbind()
{
	//glBindVertexArray(0);
}
