//
//  TouchTypes.cpp
//  Game2
//
//  Created by Stepanov Ilia on 16/11/13.
//  Copyright (c) 2013 Stepanov Ilia. All rights reserved.
//

#include "TouchTypes.h"
#include "GameEngine.h"

//---------SIMPLE_TOUCH_INPUT-------------

void SimpleTouchInput::OnPress(Vec2f coords)
{
	
}

void SimpleTouchInput::OnMove(Vec2f coords)
{
	
}

void SimpleTouchInput::OnRelease(Vec2f coords)
{
	
}

//---------WORLD_TOUCH_INPUT-------------
void WorldTouchInput::OnPress(Vec2f coords)
{
	press_coords = coords;
	old_cam_pos = GameEngine::global_data->camera->coords;
}

void WorldTouchInput::OnMove(Vec2f coords)
{
	Vec2f screen_diff = (coords - press_coords);
	screen_diff.x *= 2.0 / GameEngine::global_data->screen.width;
	screen_diff.y *= - 2.0 * GameEngine::global_data->screen.ratio /
	GameEngine::global_data->screen.height;
	
	//@todo: move it to outer interface!
	GameEngine::global_data->camera->coords =
	old_cam_pos - screen_diff;
}

void WorldTouchInput::OnRelease(Vec2f coords)
{
	press_coords = Vec2f(0.0f);
}

//---------TOWER_TOUCH_INPUT-------------
void TowerMoveTouchInput::OnPress(Vec2f coords)
{
	Vec2f world_coords = GameEngine::global_data->convert_coordinates(coords);
	press_coords = world_coords;
	GetCmpt(PositionComponent, pos_com, touched_entity);
	old_entity_coords = pos_com->position;
}

void TowerMoveTouchInput::OnMove(Vec2f coords)
{
	//@todo: be very carefull! touched_entity can be not set!
	GetCmpt(PositionComponent, pos_com, touched_entity);
	Vec2f world_coords = GameEngine::global_data->convert_coordinates(coords);
	pos_com->position = old_entity_coords + (world_coords - press_coords);
}

void TowerMoveTouchInput::OnRelease(Vec2f coords)
{
	touched_entity = NULL;

}

void TowerMoveTouchInput::SetEntity(Entity * entity)
{
	this->touched_entity = entity;
}