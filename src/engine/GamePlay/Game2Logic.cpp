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
#include "Systems/CollisionSystem.h"
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

bool Game2Logic::CalcPath(Vec2f from, Vec2f to, std::vector<Vec2f>& points)
{
	Vec2i from_i = map.pass_map.getIndexesByCoords(from);
	Vec2i to_i = map.pass_map.getIndexesByCoords(to);
	path_finder.SetStartEnd(from_i, to_i);
	std::vector<Vec2i> vec_i;
	if(!path_finder.CalcPath(vec_i))
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
	//add_system(new CollisionSystem());
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

bool Game2Logic::CanBuildTower(Vec2f coords)
{
	//@todo: move tower size to config file!
	Vec2f left_top = Vec2f(coords.x - 0.05f, coords.y + 0.05f);
	Vec2f right_bottom = Vec2f(coords.x + 0.05f, coords.y - 0.05f);
	bool outOfMap =
		(coords.x < -map.map_width) ||
		(coords.x > map.map_width)	||
		(coords.y < -map.map_height) ||
	(coords.y > map.map_height);
	
	return !outOfMap && map.pass_map.CheckCellsPass(left_top, right_bottom);
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

void Game2Logic::tower_attack(EntityPtr from, EntityPtr to)
{
	GetCmpt(EnergyStorageComponent, from_enesto_cmpt, from);
	GetCmpt(PositionComponent, from_pos_cmpt, from);
	// @todo: move constants to one game_disdock header file!
	// 30 - min limit for attack posibility
	if(from_enesto_cmpt->value > 30)
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
			add_entity(energy);
		}
	}
}


//@todo: free pass cells!
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








