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
		POSITION_COMPONENT = __FIRST,	//00
		RENDER_COMPONENT,				//01
		MOVEMENT_COMPONENT,				//02
        CONNECTOR_COMPONENT,			//03
		TARGET_COMPONENT,				//04
		ENEMY_STORAGE_COMPONENT,		//05
		NODE_COMPONENT,					//06
		ENERGY_GENERATOR_COMPONENT,		//07
		TOUCHABLE_COMPONENT,			//08
		PLAYER_ID_COMPONENT,			//09
		PATH_FIND_COMPONENT,			//10
		AI_COMPONENT,					//11
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
#include "Components/AiComponent.h"

#endif	/* COMPONENTS_H */

