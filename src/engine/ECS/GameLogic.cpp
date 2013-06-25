#include "GameLogic.h"

void GameLogic::start()
{
	//render_system = new RenderSystem();
}
	
void GameLogic::step()
{
	// @todo: remove deleted components here!
	
	for(size_t i = 0; i < systems.size(); i++)
	{
		// @todo: add init_system
		for(size_t j = 0; j < entities.size(); j++)
		{
			systems[i]->process(entities[j]);
		}
	}
}
	
void GameLogic::stop()
{
	;
}