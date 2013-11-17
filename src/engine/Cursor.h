//
//  Cursor.h
//  Game2
//
//  Created by Stepanov Ilia on 17/11/13.
//  Copyright (c) 2013 Stepanov Ilia. All rights reserved.
//

#ifndef __Game2__Cursor__
#define __Game2__Cursor__

#include "Common/Vector2f.h"

class Cursor
{
public:
	Cursor() : show(false) {;}
	
	Vec2f position;
	
	void Show() { show = true; }
	void Hide() { show = false; }
	
	void Draw();
	
private:
	bool show;
};

#endif /* defined(__Game2__Cursor__) */
