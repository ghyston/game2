//
//  IMap.h
//  kringle
//
//  Created by Ilja Stepanow on 13/03/2017.
//  Copyright © 2017 Ilja Stepanow. All rights reserved.
//

#ifndef IMap_h
#define IMap_h

struct IMap
{
    virtual ~IMap() {}
    
    virtual bool init(int width, int height, float cell_size) = 0;
};


#endif /* IMap_h */
