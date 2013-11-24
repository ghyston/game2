#include "EntityFabric.h"
#include "../GameEngine.h"


Entity * EntityFabric::get_tower(Entity* parent, Vec2f coords)
{
	//@todo: assert, has parend NodeComponent or not!
	
	Entity* tower = Entity::create();
	tower->type = Entity::Types::TOWER;
	
	//setup pos component
	PositionComponent * pos_com = new PositionComponent();
	pos_com->position = coords;	
	tower->add_component<PositionComponent>(pos_com);
	
	//setup render component
	RenderComponent * render_com = new RenderComponent();
    render_com->draw_type = RenderComponent::DRAW_TOWER;
	tower->add_component<RenderComponent>(render_com);
	
	//setup move component
	MovementComponent * move_com = new MovementComponent();
	move_com->speed = Vec2f(0.0f, 0.0f);
	move_com->velocity = Vec2f(0.0f, 0.0f);
	tower->add_component<MovementComponent>(move_com);
	
	EnergyStorageComponent * es_com = new EnergyStorageComponent();
	es_com->limit = 100;
	es_com->value = 10;
	tower->add_component<EnergyStorageComponent>(es_com);
	
	NodeComponent * node_com = new NodeComponent();
	node_com->parent.SetPointer(parent);
	
	if(node_com->parent.IsSet())
	{
		GetCmpt(NodeComponent, parent_node_com, parent);
		RefEntity * child_ref = new RefEntity();
		child_ref->SetPointer(tower);
		parent_node_com->children.push_back(*child_ref);
	}
	tower->add_component<NodeComponent>(node_com);
	
	TouchableComponent * touch_com = new TouchableComponent();
	touch_com->touch_size = 0.05f;
	tower->add_component<TouchableComponent>(touch_com);
	
	PlayerIdComponent * plr_id_cmpt = new PlayerIdComponent();
	tower->add_component<PlayerIdComponent>(plr_id_cmpt);
	
	return tower;
}

Entity * EntityFabric::get_connector(Entity * tower_1, Entity * tower_2)
{
    Entity * connector = Entity::create();
	connector->type = Entity::Types::CONNECT;
    
    ConnectorComponent * connector_com = new ConnectorComponent();
    connector_com->obj_1.SetPointer(tower_1);
    connector_com->obj_2.SetPointer(tower_2);
	
    connector->add_component<ConnectorComponent>(connector_com);
    
    RenderComponent * render_com = new RenderComponent();
    render_com->draw_type = RenderComponent::DRAW_LINE;
	connector->add_component<RenderComponent>(render_com);
    
    return connector;
}

Entity * EntityFabric::create_energy(Vec2f coords)
{
	Entity * energy = Entity::create();
	energy->type = Entity::Types::ENERGY;
	
	PositionComponent * pos_com = new PositionComponent();
	pos_com->position = coords;
	energy->add_component<PositionComponent>(pos_com);
	
	//setup render component
	RenderComponent * render_com = new RenderComponent();
    render_com->draw_type = RenderComponent::DRAW_SMALL_RECT;
	energy->add_component<RenderComponent>(render_com);
	
	//setup move component
	MovementComponent * move_com = new MovementComponent();
	move_com->speed = Vec2f(0.0f, -0.1f);
	move_com->velocity = Vec2f(0.0f, 0.0f);
	energy->add_component<MovementComponent>(move_com);
	
	//add target component
	TargetComponent * target_com = new TargetComponent();
	energy->add_component<TargetComponent>(target_com);
	
	return energy;
}

Entity * EntityFabric::create_energy_generator(Vec2f coords, float rad, float intensivity)
{
	Entity * generator = Entity::create();
	
	PositionComponent * pos_com = new PositionComponent();
	pos_com->position = coords;
	generator->add_component<PositionComponent>(pos_com);
	
	EnergyGeneratorComponent * en_gen_com = new EnergyGeneratorComponent();
	en_gen_com->radius = rad;
	en_gen_com->intensivity = intensivity;
	generator->add_component<EnergyGeneratorComponent>(en_gen_com);
	
	RenderComponent * render_com = new RenderComponent();
    render_com->draw_type = RenderComponent::DRAW_CIRCLE;
	generator->add_component<RenderComponent>(render_com);
	
	return generator;
}
