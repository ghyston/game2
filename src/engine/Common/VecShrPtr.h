//
//  VecShrPtr.h
//  Game2
//
//  Created by Stepanov Ilia on 04/12/13.
//  Copyright (c) 2013 Stepanov Ilia. All rights reserved.
//

#ifndef __Game2__VecShrPtr__
#define __Game2__VecShrPtr__

#include <vector>
#include <list>
#include <iostream>
#include "Obj.h"

/**
 * Erase from vector elements, that was marked as deleted. 
 * (ShrPtr->(Obj*)is_deleted)
 */
template <class T>
void RemoveDeletedObjectsFromVector(std::list<ShrPtr<T>>& vec)
{
	typename std::list<ShrPtr<T>>::iterator it = vec.begin();
	while (it != vec.end())
	{
		if (((Obj*)it->get())->is_deleted())
		{
			it = vec.erase(it); // @todo: why we should increment this pointer??
		}
		else
			++it;
	}
}


#endif /* defined(__Game2__VecShrPtr__) */
