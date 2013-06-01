#ifndef __BASE_TOWER_H__
#define __BASE_TOWER_H__

#include "../Renderer/RectRenderable.h"
#include "../Gui/ITouchable.h"

class BaseTower : public RectRenderable, public ITouchable
{
	private:
		static float size;
	
	public:
		BaseTower(float x, float y) : RectRenderable(0.2f, 0.2f)
		{
			coords = Vec2f(x, y);
		}
		
		virtual bool is_touched(Vec2f touched_coords);
		
};

#endif //__BASE_TOWER_H__