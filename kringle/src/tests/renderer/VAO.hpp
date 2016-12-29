//
//  VBO.hpp
//  Game2
//
//  Created by Stepanov Ilia on 22/09/2016.
//  Copyright © 2016 Stepanov Ilia. All rights reserved.
//

#ifndef VBO_hpp
#define VBO_hpp

#include "GlInclude.h"
#include <cstddef>

class VAO
{
public:
	
	void init(GLfloat * vertexes, size_t vertexesSize,
			  GLfloat * textureCoords, size_t textureCoordsSize,
			  GLuint * indicies, size_t indiciesSize);
	void bind();
	void unbind();
	
protected:
	
	GLuint m_VAO;
	GLuint m_Buffers[4];
};

#endif /* VBO_hpp */
