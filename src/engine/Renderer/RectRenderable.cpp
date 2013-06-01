#include "RectRenderable.h"

void RectRenderable::setup_vertexes()
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
		
	color[0] = 0.0f;
	color[1] = 0.0f;
	color[2] = 1.0f;
}
