#include "EntityFabric.h"
#include "../GameEngine.h"


Entity * EntityFabric::get_tower(Vec2f coords)
{
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
	es_com->value = 25;
	tower->add_component<EnergyStorageComponent>(es_com);
	
	return tower;
}

Entity * EntityFabric::get_connector(Entity * tower_1, Entity * tower_2)
{
    Entity * connector = Entity::create();
	connector->type = Entity::Types::CONNECT;
    
    ConnectorComponent * connector_com = new ConnectorComponent();
    connector_com->obj_1.pointer = tower_1;
    connector_com->obj_2.pointer = tower_2;
	tower_1->register_listener(&connector_com->obj_1);
	tower_2->register_listener(&connector_com->obj_2);
	
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
	target_com->target.pointer = NULL;
	energy->add_component<TargetComponent>(target_com);
	
	return energy;
}
