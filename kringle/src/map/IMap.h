//
//  IMap.h
//  kringle
//
//  Created by Ilja Stepanow on 13/03/2017.
//  Copyright © 2017 Ilja Stepanow. All rights reserved.
//

#ifndef IMap_h
#define IMap_h

/**
 possible maps differentiation:
 dimension 2d, 3d (4d?)
 grid: rect, hexagon, binary tree
 
 common functions:
 
 bool init (mapSize, gridSize)
 
 Coordinates getRealWorldCoordinates(IndexCoordinates)
 IndexCoordinates getIndexCoordinates(Coordinates)
 
 bool isCellOccupied(Coordinate)
 array<Object> getObjectsByCoord(IndexCoordinate)
 
 array<Coordinate> findPath(Coordinate, Coordinate, ObjSize)
 array<IndexCoordinate> findPath(IndexCoordinate, IndexCoordinate, ObjSizeInGridSizes)
 
 Object getFirstObjectWithComponent<Component>()
 Object getFirstObjectWithComponent<Component>(Coordinate)
 Object getClosestObjectWithComponent<Component..>(Coordinate, ?limitSize, ?limitCount)
 Object getClosestObjectWithComponent<Component..>(Coordinate, lambda<bool, Component>, ?limit, ?limitCount)
 array<Object> getAllObjectsByConditionInRadius<Component..>(Coordinate, lambda<bool, Component>, ?limit, ?limitCount)
 //a lot of find functions. Possible combinations:
 params: 
 - components to contain
 - lambda(s) to check components
 - coordinates to start with
 - limit radius (in grids or in real coordinates)
 - limit count
 return:
 - Object
 - array of objects
 - bool
 
 Classes:
 - IndexCoordinate
 - ReadCoordinate is Vec2f ?? No
 - CellMath ?
 - CellContainer
 
 */

//template <class Cellclass, int dimensionsCount>
struct IMap
{
    virtual ~IMap() {}
    
    virtual bool init(int width, int height, float cell_size) = 0;
    
};

#endif /* IMap_h */
