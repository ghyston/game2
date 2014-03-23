/* 
 * File:   Components.h
 * Author: Hyston
 *
 * Created on 17 Июнь 2013 г., 16:46
 */

#ifndef __COMPONENTS_H__
#define	__COMPONENTS_H__

struct ComponentsType
{
	enum Enum
	{
		__INVALID = -1,
		__FIRST = 0,
		POSITION_COMPONENT = __FIRST,	//0
		RENDER_COMPONENT,				//1
		MOVEMENT_COMPONENT,				//2
        CONNECTOR_COMPONENT,			//3
		TARGET_COMPONENT,				//4
		ENEMY_STORAGE_COMPONENT,		//5
		NODE_COMPONENT,					//6
		ENERGY_GENERATOR_COMPONENT,		//7
		TOUCHABLE_COMPONENT,			//8
		PLAYER_ID_COMPONENT,			//9
		PATH_FIND_COMPONENT,			//10
		__COUNT
	};
};

#include "Components/MovementComponent.h"
#include "Components/PositionComponent.h"
#include "Components/RenderComponent.h"
#include "Components/ConnectorComponent.h"
#include "Components/TargetComponent.h"
#include "Components/EnergyStorageComponent.h"
#include "Components/NodeComponent.h"
#include "Components/EnergyGeneratorComponent.h"
#include "Components/TouchableComponent.h"
#include "Components/PlayerIdComponent.h"
#include "Components/PathFindComponent.h"

#endif	/* COMPONENTS_H */

