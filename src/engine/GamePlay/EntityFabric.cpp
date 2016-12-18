#include "EntityFabric.h"
#include "../GameEngine.h"
#include "../Common/SomeMath.h"

EntityPtr EntityFabric::get_tower(EntityPtr parent, Vec2f coords)
{
	//@todo: assert, has parend NodeComponent or not!
	
	EntityPtr tower = Entity::create();
    shared_ptr<Entity> spTower = tower.lock();
	
	//setup pos component
	PositionComponent * pos_com = spTower->add_component<PositionComponent>();
	pos_com->position = coords;
	
	//setup render component
	RenderComponent * render_com = spTower->add_component<RenderComponent>();
    render_com->draw_type = RenderComponent::DRAW_TOWER;
	render_com->draw_layer = RenderComponent::THIRD_LAYER;
	
	//setup move component
	MovementComponent * move_com2 = new MovementComponent(); //@todo: check, should be error on compile!
    MovementComponent * move_com = spTower->add_component<MovementComponent>();
	move_com->speed = Vec2f(0.0f, 0.0f);
	move_com->velocity = Vec2f(0.0f, 0.0f);
	
	EnergyStorageComponent * es_com = spTower->add_component<EnergyStorageComponent>();
	es_com->limit = 100;
	es_com->value = 10;
	
	NodeComponent * node_com = spTower->add_component<NodeComponent>();
	node_com->parent = parent;
	
	if(!parent.expired())
	{
		GetCmpt(NodeComponent, parent_node_com, parent.lock());
		parent_node_com->children.push_back(tower);
	}
	
	TouchableComponent * touch_com = spTower->add_component<TouchableComponent>();
	touch_com->touch_size = GameConst::TOWER_TOUCH_SIZE;
	
	spTower->add_component<PlayerIdComponent>();
	spTower->add_component<AiComponent>();
	
	return tower;
}

EntityPtr EntityFabric::get_connector(EntityPtr tower_1, EntityPtr tower_2)
{
    EntityPtr connector = Entity::create();
    shared_ptr<Entity> spConn = connector.lock();
	
    ConnectorComponent * connector_com = spConn->add_component<ConnectorComponent>();
    connector_com->obj_1 = tower_1;
    connector_com->obj_2 = tower_2;
    
    RenderComponent * render_com = spConn->add_component<RenderComponent>();
    render_com->draw_type = RenderComponent::DRAW_LINE;
	render_com->draw_layer = RenderComponent::SECOND_LAYER;
    
    return connector;
}

EntityPtr EntityFabric::create_energy(Vec2f coords)
{
	EntityPtr energy = Entity::create();
    shared_ptr<Entity> spEnergy = energy.lock();
		
	PositionComponent * pos_com = spEnergy->add_component<PositionComponent>();
	pos_com->position = coords;
	
	//setup render component
	RenderComponent * render_com = spEnergy->add_component<RenderComponent>();
    render_com->draw_type = RenderComponent::DRAW_SMALL_RECT;
	render_com->draw_layer = RenderComponent::THIRD_LAYER;
	
	//setup move component
	MovementComponent * move_com = spEnergy->add_component<MovementComponent>();
	move_com->speed = Vec2f(0.0f, -0.1f);
	move_com->velocity = Vec2f(0.0f, 0.0f);
	
	//add target component
	spEnergy->add_component<TargetComponent>();
	
	return energy;
}

EntityPtr EntityFabric::create_energy_generator(Vec2f coords, float rad, float intensivity)
{
	EntityPtr generator = Entity::create();
    shared_ptr<Entity> spGen = generator.lock();
    
	PositionComponent * pos_com = spGen->add_component<PositionComponent>();
	pos_com->position = coords;
	
	EnergyGeneratorComponent * en_gen_com = spGen->add_component<EnergyGeneratorComponent>();
	en_gen_com->radius = rad;
	en_gen_com->intensivity = intensivity;
	
	RenderComponent * render_com = spGen->add_component<RenderComponent>();
    render_com->draw_type = RenderComponent::DRAW_CIRCLE;
	render_com->draw_layer = RenderComponent::FIRST_LAYER;
	
	return generator;
}

EntityPtr EntityFabric::CreateWaypoint(Vec2f coords)
{
	EntityPtr waypoint = Entity::create();
    shared_ptr<Entity> spWaypoint = waypoint.lock();
    
	PositionComponent * pos_com = spWaypoint->add_component<PositionComponent>();
	pos_com->position = coords;
	
	//@todo: this is just for debug!
	RenderComponent * render_com = spWaypoint->add_component<RenderComponent>();
    render_com->draw_type = RenderComponent::DRAW_SMALL_RECT;
	render_com->draw_layer = RenderComponent::THIRD_LAYER;
	
	return waypoint;
}

EntityPtr EntityFabric::CreateUnit(Vec2f coords)
{
	EntityPtr unit = Entity::create();
    shared_ptr<Entity> spUnit = unit.lock();
	
	PositionComponent * pos_com = spUnit->add_component<PositionComponent>();
	pos_com->position = coords;
	
	RenderComponent * render_com = spUnit->add_component<RenderComponent>();
    render_com->draw_type = RenderComponent::DRAW_TRINAGE;
	render_com->draw_layer = RenderComponent::THIRD_LAYER;
	
	//setup move component
	MovementComponent * move_com = spUnit->add_component<MovementComponent>();
	move_com->speed = Vec2f(0.0f, 0.0f);
	move_com->velocity = Vec2f(0.0f, 0.0f);
	
	spUnit->add_component<PathFindComponent>();

	return unit;
}

//@todo: if points has y == any cell.y, calculation would be wrong!
void EntityFabric::BlockCellsByPolygon(Vec2f coords, const std::vector<Vec2f>& points, EntityPtr polygon)
{
	if(points.size() < 3)
		return;
	
	PassMap * map = &GameEngine::get_data()->logic.getMap()->pass_map;
//	Vec2f cell_half_size = Vec2f(map->getCellSize() / 2, map->getCellSize() / 2);
	float cell_size = map->getCellSize();
	
	Vec2i bb_min( map->getWidth() + 1, map->getHeight() + 1);
	Vec2i bb_max(- map->getWidth() - 1, -map->getHeight() - 1);

	// Calculate bounding box.
	for(auto it = points.begin(); it != points.end(); it++)
	{
		Vec2i indx = map->getIndexesByCoords(*it + coords);
		if(indx.x < bb_min.x)
			bb_min.x = indx.x;
		if(indx.y < bb_min.y)
			bb_min.y = indx.y;
		if(indx.x > bb_max.x)
			bb_max.x = indx.x;
		if(indx.y > bb_max.y)
			bb_max.y = indx.y;
	}
	
	Vec2f max_coords = map->getCoordsByIndex(bb_max);
	float right_x = max_coords.x + cell_size;
	float top_y = max_coords.y + cell_size;
	
	// Get list offset of cell vertex
	std::vector<Vec2f> cell_vertexes;
	cell_vertexes.push_back(Vec2f(0.0f, 0.0f));
	cell_vertexes.push_back(Vec2f(cell_size, 0.0f));
	cell_vertexes.push_back(Vec2f(0.0f, cell_size));
	cell_vertexes.push_back(Vec2f(cell_size, cell_size));
	
	// For every cell in bounding box.
	for(int i = bb_min.x; i <= bb_max.x; i++)
	{
		for(int j = bb_min.y; j <= bb_max.y; j++)
		{
			bool intersected = false;
			for(auto it = cell_vertexes.begin();
				(it != cell_vertexes.end()) && !intersected; it++)
			{
				Vec2f cell_vertex = map->getCoordsByIndex(i, j) + *it;
			
				// Calc intersection with all polygon edges.
				// @note: we use horizontal and vertical for greater accuracy
				int intersect_count_horizontal = 0;
				int intersect_count_vertical = 0;
				for(int k = 1; k <= points.size(); k++)
				{
					Vec2f p1 = points[k - 1] + coords;
					// Last point should be 0
					Vec2f p2 = points[(k == points.size()) ? 0 : k] + coords;
				
					// Vector from cell center to right bb edge, paralleled oX
					Vec2f n_r = Vec2f(right_x, cell_vertex.y);
					Vec2f n_t = Vec2f(cell_vertex.x, top_y);
				
					if(SegmentsIntersected(p1, p2, cell_vertex, n_r))
						intersect_count_horizontal++;
					if(SegmentsIntersected(p1, p2, cell_vertex, n_t))
						intersect_count_vertical++;
				}
			
				// If we have uneven intersect count, cell center is inside polygon
				intersected = ((intersect_count_horizontal % 2) == 1) &&
					((intersect_count_vertical % 2) == 1);
			}
			
			if(intersected)
				map->BlockPass(Vec2i(i, j), polygon);
		}
	}
}


//@note: before Renderer refactoring, you can create only one polygon
// rendererable object!
EntityPtr EntityFabric::CreateHindernis(Vec2f coords, std::vector<Vec2f> points)
{
	EntityPtr hindernis = Entity::create();
    shared_ptr<Entity> spObstacle = hindernis.lock();
	
	int mesh_id = GameEngine::get_renderer()->SetupPolygon(points);
	
	PositionComponent * pos_com = spObstacle->add_component<PositionComponent>();
	pos_com->position = coords;
	
	RenderComponent * render_com = spObstacle->add_component<RenderComponent>();
    render_com->draw_type = RenderComponent::DRAW_POLYGON;
	render_com->draw_layer = RenderComponent::THIRD_LAYER;
	render_com->mesh_id = mesh_id;
	
	BlockCellsByPolygon(coords, points, hindernis);
	
	return hindernis;
}
