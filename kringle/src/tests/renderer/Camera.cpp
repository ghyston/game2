#include "Camera.h"

void Camera::move(Vec2f diff)
{
	coords.x += diff.x;
	coords.y += diff.y;
}
	
void Camera::zoom(float new_val)
{
	zoom_koeff = new_val;
}