//
//  TextureRectRenderable.h
//  Game2
//
//  Created by Stepanov Ilia on 11/01/15.
//  Copyright (c) 2015 Stepanov Ilia. All rights reserved.
//

#ifndef __Game2__TextureRectRenderable__
#define __Game2__TextureRectRenderable__


#include "GlInclude.h"

#include "../Common/Matrix4f.h"
#include "../Common/Vector2f.h"
#include "../Common/Color3f.h"
#include <cstddef>

class TextureRectRenderable
{
	//protected:
public:
	
	/*float * vertexes;
	float * _textureCoords;
	int * _indices;
	int vertexes_count;*/
	
	Color3f color;
	float angle;
	float scale;
	GLenum draw_type;
	
	GLuint _vbo;
	GLuint _eab;
	GLuint _vao;
	
	GLuint _texture;
	GLuint shader;
	GLuint gvPositionHandle;
	GLuint gModelHandle;
	GLuint gFragColorHandle;
	GLuint gTextureHandle;
	static Matrix4f* model_matrix;
	static Matrix4f* model_matrix_rotate;
	static Matrix4f* model_matrix_scale;
	static Matrix4f* model_matrix_translate;
	static Matrix4f* temp_matrix;
	
	float width;
	float height;
	
	//@note: call setup_vertexes() after that!
	void set_height(float height) { this->height = height; }
	//@note: call setup_vertexes() after that!
	void set_width(float width) { this->width = width; }
	
public:
	
	Vec2f coords;
	
	TextureRectRenderable();
	
	virtual void setup_vertexes();
	
	virtual void setTexture(GLuint texture) { _texture = texture; }
	virtual void SetColor(Color3f& color);
	virtual void SetColor(float red, float green, float blue);
	
	virtual void delete_vertexes();
	
	virtual void set_shader(GLuint program);
	
	virtual void Draw();
	
	virtual ~TextureRectRenderable();
	
};

#endif /* defined(__Game2__TextureRectRenderable__) */
