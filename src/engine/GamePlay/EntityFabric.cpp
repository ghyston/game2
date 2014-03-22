#include "EntityFabric.h"
#include "../GameEngine.h"


EntityPtr EntityFabric::get_tower(EntityPtr parent, Vec2f coords)
{
	//@todo: assert, has parend NodeComponent or not!
	
	EntityPtr tower = Entity::create();
	tower->type = Entity::Types::TOWER;
	
	//setup pos component
	PositionComponent * pos_com = new PositionComponent();
	pos_com->position = coords;	
	tower->add_component<PositionComponent>(pos_com);
	
	//setup render component
	RenderComponent * render_com = new RenderComponent();
    render_com->draw_type = RenderComponent::DRAW_TOWER;
	render_com->draw_layer = RenderComponent::THIRD_LAYER;
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
	node_com->parent = parent;
	
	if(parent.is_set())
	{
		GetCmpt(NodeComponent, parent_node_com, parent);
		parent_node_com->children.push_back(tower);
	}
	tower->add_component<NodeComponent>(node_com);
	
	TouchableComponent * touch_com = new TouchableComponent();
	touch_com->touch_size = 0.05f;
	tower->add_component<TouchableComponent>(touch_com);
	
	PlayerIdComponent * plr_id_cmpt = new PlayerIdComponent();
	tower->add_component<PlayerIdComponent>(plr_id_cmpt);
	
	return tower;
}

EntityPtr EntityFabric::get_connector(EntityPtr tower_1, EntityPtr tower_2)
{
    EntityPtr connector = Entity::create();
	connector->type = Entity::Types::CONNECT;
    
    ConnectorComponent * connector_com = new ConnectorComponent();
    connector_com->obj_1 = tower_1;
    connector_com->obj_2 = tower_2;
	
    connector->add_component<ConnectorComponent>(connector_com);
    
    RenderComponent * render_com = new RenderComponent();
    render_com->draw_type = RenderComponent::DRAW_LINE;
	render_com->draw_layer = RenderComponent::SECOND_LAYER;
	connector->add_component<RenderComponent>(render_com);
    
    return connector;
}

EntityPtr EntityFabric::create_energy(Vec2f coords)
{
	EntityPtr energy = Entity::create();
	energy->type = Entity::Types::ENERGY;
	
	PositionComponent * pos_com = new PositionComponent();
	pos_com->position = coords;
	energy->add_component<PositionComponent>(pos_com);
	
	//setup render component
	RenderComponent * render_com = new RenderComponent();
    render_com->draw_type = RenderComponent::DRAW_SMALL_RECT;
	render_com->draw_layer = RenderComponent::THIRD_LAYER;
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

EntityPtr EntityFabric::create_energy_generator(Vec2f coords, float rad, float intensivity)
{
	EntityPtr generator = Entity::create();
	
	PositionComponent * pos_com = new PositionComponent();
	pos_com->position = coords;
	generator->add_component<PositionComponent>(pos_com);
	
	EnergyGeneratorComponent * en_gen_com = new EnergyGeneratorComponent();
	en_gen_com->radius = rad;
	en_gen_com->intensivity = intensivity;
	generator->add_component<EnergyGeneratorComponent>(en_gen_com);
	
	RenderComponent * render_com = new RenderComponent();
    render_com->draw_type = RenderComponent::DRAW_CIRCLE;
	render_com->draw_layer = RenderComponent::FIRST_LAYER;
	generator->add_component<RenderComponent>(render_com);
	
	return generator;
}
