#ifndef __IRENDERABLE_H__
#define __IRENDERABLE_H__

#include <GLES2/gl2.h>
#include <GLES2/gl2ext.h>

#include "Matrix4f.h"
#include "Vector2f.h"

class BaseRenderable
{
protected:

	float * vertexes;
	int vertexes_count;
	float color [4];
	GLuint shader;
	GLuint gvPositionHandle;
	GLuint gModelHandle;
	GLuint gFragColorHandle;
	static Matrix4f* model_matrix;
	static Matrix4f* model_matrix_rotate;
	static Matrix4f* model_matrix_scale;
	static Matrix4f* model_matrix_translate;
	static Matrix4f* temp_matrix;
	Vec2f coords;	
	float angle;
	float scale;
	GLenum draw_type;

public:

	BaseRenderable();
	
	virtual void set_vertexes(float * vertexes);

	virtual void set_shader(GLuint program);

	virtual void Draw();

	virtual ~BaseRenderable();

};

#endif //__IRENDERABLE_H__