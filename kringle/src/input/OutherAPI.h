//
//  OutherAPI.h
//  Game2
//
//  Created by Stepanov Ilia on 05/02/14.
//  Copyright (c) 2014 Stepanov Ilia. All rights reserved.
//

#ifndef __Game2__OutherAPI__
#define __Game2__OutherAPI__

// This functions is used to communicate game world to input processor
class OutherAPI
{
public:
	static void MoveWorld(float diff_x, float diff_y);
};

#endif /* defined(__Game2__OutherAPI__) */
