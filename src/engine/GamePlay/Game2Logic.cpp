//
//  Game2Logic.cpp
//  Game2
//
//  Created by Stepanov Ilia on 05/11/13.
//  Copyright (c) 2013 Stepanov Ilia. All rights reserved.
//

#include "Game2Logic.h"
#include "Systems/RenderSystem.h"
#include "Systems/MoveSystem.h"
#include "Systems/TargetEnergySystem.h"
#include "Systems/EnergyCreatorSystem.h"
#include "Systems/EnergyBalanceSystem.h"
#include "Systems/AISystem.h"
#include "Systems/PathMoveSystem.h"

#include "EntityFabric.h"

void Game2Logic::LoadMap(int width, int height)
{
	GameLogic::LoadMap(width, height);
	
	GameEngine::get_renderer()->SetupGrid(
		map.entity_map.getWidth(), map.entity_map.getHeight(), map.entity_map.getCellSize());
	
	GameEngine::get_renderer()->SetupPassGrid(map.pass_map.getWidth(),
			map.pass_map.getHeight(), map.pass_map.getCellSize());
	
	path_finder.InitCells(map.pass_map.getWidth(), map.pass_map.getHeight());
}

//@todo: this functions are almost duplicate!
bool Game2Logic::CalcPath4Unit(Vec2f from, Vec2f to, std::vector<Vec2f>& points)
{
	std::vector<Vec2i> vec_i;
	if(!path_finder.CalcPathForUnit(vec_i, from, to, Entities()))
		return false;
	
	points.clear();
	float cell_half_size = map.pass_map.getCellSize() / 2;
	
	while (!vec_i.empty())
	{
		points.push_back(Vec2f(cell_half_size, cell_half_size) +
						 map.pass_map.getCoordsByIndex(vec_i.back()));
		vec_i.pop_back();
	}
	return true;
}

bool Game2Logic::CalcPath4Tower(Vec2f from, Vec2f to, std::vector<Vec2f>& points, EntityPtr tower)
{
	Entities ent_list;
	ent_list.push_back(tower);
	return CalcPath4Tower(from, to, points, ent_list);
}

bool Game2Logic::CalcPath4Tower(Vec2f from, Vec2f to, std::vector<Vec2f>& points, Entities towers)
{
	std::vector<Vec2i> vec_i;
	if(!path_finder.CalcPathForTower(vec_i, from, to, towers))
		return false;
	
	points.clear();
	float cell_half_size = map.pass_map.getCellSize() / 2;
	
	while (!vec_i.empty())
	{
		points.push_back(Vec2f(cell_half_size, cell_half_size) +
						 map.pass_map.getCoordsByIndex(vec_i.back()));
		vec_i.pop_back();
	}
	return true;
}

void Game2Logic::start()
{
	add_system(new RenderSystem());
	add_system(new MoveSystem());
	add_system(new TargetEnergySystem());
	add_system(new EnergyBalanceSystem());
	add_system(new EnergyGeneratorSystem());
	add_system(new AISystem());
	add_system(new PathMoveSystem());
}

void Game2Logic::stop()
{
	//@todo: remove all systems!
}

bool Game2Logic::CanBuildTower(Vec2f parent_coords, Vec2f coords)
{
	// First, check, intersect connection busy cells or not.
	//@todo: line intersect cells, that busy by parent tower
	/*Vec2i parent_cell = map.pass_map.getIndexesByCoords(parent_coords);
	Vec2i tower_cell = map.pass_map.getIndexesByCoords(coords);
	if(!path_finder.CheckLine(parent_cell, tower_cell))
		return false;*/
	
	// Check out of map borders.
	//@todo: move tower size to config file!
	Vec2f left_top = Vec2f(coords.x - 0.05f, coords.y + 0.05f);
	Vec2f right_bottom = Vec2f(coords.x + 0.05f, coords.y - 0.05f);
	if((coords.x < -map.map_width) ||
		(coords.x > map.map_width)	||
		(coords.y < -map.map_height) ||
		(coords.y > map.map_height))
		return false;
		
	// Is end point busy
	return map.pass_map.CheckCellsPass(left_top, right_bottom);
}

void Game2Logic::add_tower(EntityPtr tower)
{
	GameLogic::add_entity(tower);
	
	//setup player id
	GetCmpt(NodeComponent, node_com, tower);
	if(node_com->parent.is_set())
	{
		GetCmpt(PlayerIdComponent, parent_plr_id_cmpt, (node_com->parent));
		GetCmpt(PlayerIdComponent, self_plr_id_cmpt, tower);
		self_plr_id_cmpt->player_id = parent_plr_id_cmpt->player_id;
	}
	
	// notify ai
	GetCmpt(PlayerIdComponent, self_plr_id_cmpt, tower);
	if (self_plr_id_cmpt->player_id == GlobalData::PLAYER_ID_1 )
	{
		GameEngine::global_data->aiLogic.newTowerBuilded = true;
	}
	
	
	GetCmpt(PositionComponent, tower_pos_con, tower);
	
	Vec2f pos = tower_pos_con->position;
	Vec2f left_top = Vec2f(pos.x - 0.05f, pos.y + 0.05f);
	Vec2f right_bottom = Vec2f(pos.x + 0.05f, pos.y - 0.05f);
	map.pass_map.BlockPassCells(left_top, right_bottom, tower);
	
	//Find energy generator nearby
	EntityPtr generator = map.findClosestEntityHasCmp<EnergyGeneratorComponent>(tower_pos_con->position);
	
	if(generator.is_set())
	{
		GetCmpt(PositionComponent, generator_pos_com, generator);
		GetCmpt(EnergyGeneratorComponent, gen_com, generator);
		float dist = distance(generator_pos_com->position, tower_pos_con->position);
		if(gen_com->radius > dist)
		{
			gen_com->towers.push_back(tower);

		}
	}
}

void Game2Logic::add_energy(EntityPtr energy, EntityPtr generator)
{
	GetCmpt(TargetComponent, tar_cmpt, energy);
	GetCmpt(EnergyGeneratorComponent, engen_cmpt, generator);
	GetCmpt(PositionComponent, energy_pos_cmpt, energy);
	
	if(engen_cmpt->towers.size() == 0)
		return;
	
	float min_dist = engen_cmpt->radius;
	EntityIt it = engen_cmpt->towers.begin();
	EntityPtr closest_tower = *it;
	while (it != engen_cmpt->towers.end())
	{
		GetCmpt(PositionComponent, tower_pos_com, (*it));
			
		Vec2f dist = energy_pos_cmpt->position - tower_pos_com->position;
			
		if(dist.length() < min_dist)
		{
			closest_tower = *it;
			min_dist = dist.length();
		}
		it++;
	}
	
	tar_cmpt->target = closest_tower;
	GameLogic::add_entity(energy);
}

void Game2Logic::AddHindernis(EntityPtr hindernis)
{
	GameLogic::add_entity(hindernis);
}

void Game2Logic::tower_attack(EntityPtr from, EntityPtr to)
{
	GetCmpt(EnergyStorageComponent, from_enesto_cmpt, from);
	GetCmpt(PositionComponent, from_pos_cmpt, from);
	GetCmpt(PositionComponent, to_pos_cmpt, to);
	// @todo: move constants to one game_disdock header file!
	// 30 - min limit for attack posibility
	if(from_enesto_cmpt->value > GameConst::MIN_ENERGY_TO_ACTION)
	{
		// 10 - count energys, that would attack enemy tower
		from_enesto_cmpt->value -= 10;
		EntityPtr energy;
		for(int i = 0; i < 10; i++)
		{
			energy = EntityFabric::create_energy(from_pos_cmpt->position);
			GetCmpt(TargetComponent, targ_cmpt, energy);
			targ_cmpt->target = to;
			targ_cmpt->target_enemy = true;
			
			// сделаем красиво
			float angle = (rand() % 200) / 100.0f; // 0.0 - 2.0
			float startSpeed = 0.1f;
			float t = (rand() % 150) / 100.0f + 0.5f; // 0.5 - 2.0
			Vec2f V0 (startSpeed * cos(angle * M_PI), startSpeed * sin(angle * M_PI));
			
			//V0.x = 0.5f;
			//V0.y = 0.0f;
			
			Vec2f pos1 = from_pos_cmpt->position;
			Vec2f pos2 = to_pos_cmpt->position;
			
			Vec2f a; //velocity
			// It's math, bitches!
			a.x = 2 * (pos2.x - pos1.x - V0.x * t) / (t * t);
			a.y = 2 * (pos2.y - pos1.y - V0.y * t) / (t * t);
			
			GetCmpt(MovementComponent, mov_cmpt, energy);
			mov_cmpt->speed = V0;
			mov_cmpt->velocity = a;
			
			add_entity(energy);
		}
	}
}

void Game2Logic::remove_tower(EntityPtr tower)
{
	GetCmpt(NodeComponent, node_com, tower);
	
	//remove child from parent
	if(node_com->parent.is_set())
	{
		GetCmpt(NodeComponent, parent_node_cmpt, node_com->parent);
		EntityIt it = parent_node_cmpt->children.begin();
		while (it != parent_node_cmpt->children.end())
		{
			if(it->get() == tower.get())
			{
				parent_node_cmpt->children.erase(it);
				break;
			}
			else
			{
				it++;
			}
		}
	}
	
	//Remove parent's from children
	EntityIt it = node_com->children.begin();
	while (it != node_com->children.end())
	{
		GetCmpt(NodeComponent, child_node_comp, (*it));
		child_node_comp->parent.set(NULL);
		it++;
	}
	node_com->children.clear();
	
	//Remove self
	tower->mark_deleted();
}








