//
//  ShrPtr.h
//  Game2
//
//  Created by Stepanov Ilia on 19/11/13.
//  Copyright (c) 2013 Stepanov Ilia. All rights reserved.
//

#ifndef __Game2__ShrPtr__
#define __Game2__ShrPtr__

template <class T>
class ShrPtr
{
private:
	T* pointer;
	bool del_mark;
	
public:
	
	ShrPtr(T* p) : pointer(p), del_mark(false) {;}
	~ShrPtr();
	
	void mark_del() { del_mark = true; }
	void is_del() { return del_mark; }
	
	T* get() { return del_mark ? NULL : pointer; }
	
	
};

#endif /* defined(__Game2__ShrPtr__) */
