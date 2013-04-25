#include "Camera.h"

Camera::Camera()
{
	ortho = new Matrix4f();
}

Camera::~Camera()
{
	delete ortho;
}

void Camera::setup_ortho(
	float left, float right, 
	float bottom, float top, 
	float near, float far)
{
	float a = 2.0f / (right - left);
	float b = 2.0f / (top - bottom);
	float c = -2.0f / (far - near);
	
	float tx = - (right + left)/(right - left);
	float ty = - (top + bottom)/(top - bottom);
	float tz = - (far + near)/(far - near);
	
	ortho->Identity();
	ortho->Translate(tx, ty, tz);
	ortho->Scale(a, b, c);
}