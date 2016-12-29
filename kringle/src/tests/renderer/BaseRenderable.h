#ifndef __IRENDERABLE_H__
#define __IRENDERABLE_H__

#include "GlInclude.h"

#include "../Common/Matrix4f.h"
#include "../Common/Vector2f.h"
#include "../Common/Color3f.h"
#include <cstddef>

class BaseRenderable
{
public:
	
	float * vertexes;
	
	float angle;

protected:
	
	Color3f color;
	
	int vertexes_count;
	
	float scale;
	GLenum draw_type;
	
	GLuint shader;
	GLuint gvPositionHandle;
	GLuint gModelHandle;
	GLuint gFragColorHandle;
	static Matrix4f* model_matrix;
	static Matrix4f* model_matrix_rotate;
	static Matrix4f* model_matrix_scale;
	static Matrix4f* model_matrix_translate;
	static Matrix4f* temp_matrix;	
	

public:
	
	Vec2f coords;

	BaseRenderable();
	
	virtual void setup_vertexes() = 0;
	
	virtual void SetColor(Color3f& color);
	virtual void SetColor(float red, float green, float blue);
	
	virtual void delete_vertexes();

	virtual void set_shader(GLuint program);

	virtual void Draw();

	virtual ~BaseRenderable();

};

#endif //__IRENDERABLE_H__