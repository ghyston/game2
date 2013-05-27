#include "Button.h"

bool Button::is_touched(float x, float y)
{
    if((x > (coords.x - width / 2)) && 
       (x < (coords.x + width / 2)) &&
       (y > (coords.y - height / 2)) &&
       (y < (coords.y + height / 2)))
    {
        on_touch();
        //is touched!
        return true;
    }
    //TODO: this is shit!! Ugly, fuckn shiiiTTT!! >(((
    
    on_release();
    return false;
}

void Button::on_touch()
{
    this->color[0] = color_pressed.r;
    this->color[1] = color_pressed.g;
    this->color[2] = color_pressed.b;
}
	
void Button::on_release()
{
    this->color[0] = color_idle.r;
    this->color[1] = color_idle.g;
    this->color[2] = color_idle.b;    
}

void Button::setup_vertexes()
{
	float h2 = height / 2;
		float w2 = width / 2;
		
	vertexes = new float[8];
	vertexes[0] = -w2;
	vertexes[1] = -h2;
		
	vertexes[2] = -w2;
	vertexes[3] =  h2;
		
	vertexes[4] =  w2;
	vertexes[5] = -h2;
		
	vertexes[6] =  w2;
	vertexes[7] =  h2;
    
	vertexes_count = 4;
		
	color[0] = 1.0f;
	color[1] = 1.0f;
	color[2] = 0.0f;
}