//
//  Obj.h
//  Game2
//
//  Created by Stepanov Ilia on 01/12/13.
//  Copyright (c) 2013 Stepanov Ilia. All rights reserved.
//

#ifndef Game2_Obj_h
#define Game2_Obj_h

class Obj
{
public:
	Obj() : ref_counter(0) {;}
	
	virtual ~Obj() {;}
	
	int ref_counter;
};


#endif
