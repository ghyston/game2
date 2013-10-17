#include "EntityFabric.h"
#include "../GameEngine.h"

Entity * EntityFabric::get_tower(Vec2f coords)
{
	Entity* tower = new Entity();
	
	//setup pos component
	PositionComponent * pos_com = new PositionComponent();
	pos_com->position = coords;	
	tower->add_component(ComponentsType::POSITION_COMPONENT, pos_com);
	
	//setup render component
	RenderComponent * render_com = new RenderComponent();
    render_com->draw_type = RenderComponent::DRAW_RECT;
	tower->add_component(ComponentsType::RENDER_COMPONENT, render_com);
	
	//setup move component
	MovementComponent * move_com = new MovementComponent();
	move_com->speed = Vec2f(0.0f, 0.0f);
	move_com->velocity = Vec2f(0.0f, 0.0f);
	tower->add_component(ComponentsType::MOVEMENT_COMPONENT, move_com);
	return tower;
}

Entity * EntityFabric::get_connector(Entity * tower_1, Entity * tower_2)
{
    Entity * connector = new Entity();
    
    ConnectorComponent * connector_com = new ConnectorComponent();
    connector_com->obj_1 = tower_1;
    connector_com->obj_2 = tower_2;
    connector->add_component(
        ComponentsType::CONNECTOR_COMPONENT, connector_com);
    
    RenderComponent * render_com = new RenderComponent();
    render_com->draw_type = RenderComponent::DRAW_LINE;
	connector->add_component(
        ComponentsType::RENDER_COMPONENT, render_com);
    
    return connector;
}

Entity * EntityFabric::create_energy(Vec2f coords)
{
	Entity * energy = new Entity();
	
	PositionComponent * pos_com = new PositionComponent();
	pos_com->position = coords;
	energy->add_component(ComponentsType::POSITION_COMPONENT, pos_com);
	
	//setup render component
	RenderComponent * render_com = new RenderComponent();
    render_com->draw_type = RenderComponent::DRAW_SMALL_RECT;
	energy->add_component(ComponentsType::RENDER_COMPONENT, render_com);
	
	//setup move component
	MovementComponent * move_com = new MovementComponent();
	move_com->speed = Vec2f(0.0f, -0.1f);
	move_com->velocity = Vec2f(0.0f, 0.0f);
	energy->add_component(ComponentsType::MOVEMENT_COMPONENT, move_com);
	
	//add target component
	TargetComponent * target_com = new TargetComponent();
	target_com->target = NULL;
	energy->add_component(ComponentsType::TARGET_COMPONENT, target_com);
	
	return energy;
}
