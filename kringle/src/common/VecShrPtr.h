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
#include "ShrPtr.h"
#include <memory>

using namespace std;

/**
 * Erase from vector elements, that was marked as deleted. 
 * (ShrPtr->(Obj*)is_deleted)
 */
template <class T>
void RemoveDeletedObjectsFromContainer(std::list<weak_ptr<T> >& vec)
{
	auto it = vec.begin();
	while (it != vec.end())
	{
		if (it->expired())
		{
			it = vec.erase(it);
		}
		else
			++it;
	}
}


#endif /* defined(__Game2__VecShrPtr__) */
