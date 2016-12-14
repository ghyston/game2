//
//  Types.h
//  Game2
//
//  Created by Stepanov Ilia on 16/01/14.
//  Copyright (c) 2014 Stepanov Ilia. All rights reserved.
//

#ifndef Game2_Types_h
#define Game2_Types_h

//#include "../Common/ShrPtr.h"
#include "Entity.h"
#include <list>
#include <memory>

using namespace std;

class Entity;

typedef weak_ptr<Entity> EntityPtr;
typedef list<EntityPtr> Entities;
typedef Entities::iterator EntityIt;


#endif
