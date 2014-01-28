//
//  ShrPtr.h
//  Game2
//
//  Created by Stepanov Ilia on 01/12/13.
//  Copyright (c) 2013 Stepanov Ilia. All rights reserved.
//

#ifndef __Game2__ShrPtr__
#define __Game2__ShrPtr__

#include <iostream>
#include "Obj.h"

// My great implementation on std::shared_ptr from C++11.
template <class T>
class ShrPtr
{
public:
	
	// C-tor
	ShrPtr(T* ptr = NULL) : ptr(NULL)
	{
		set(ptr);
	}
	
	// Copy c-tor
	ShrPtr(const ShrPtr<T>& pointer)
	{
		ptr = (Obj*)pointer.get();
		incr_counter();
	}
	
	// D-tor.
	~ShrPtr() { decr_counter(); }
	
	// Set pointer to this ShrPtr. @note: prev pointer, if exist, realesed
	void set(T* ptr)
	{
		decr_counter();
			
		this->ptr = (Obj*)ptr;
		if(is_set())
			incr_counter();
	}
	
	/// assignment of clPtr
	ShrPtr& operator = ( const ShrPtr& pointer )
	{
		set(pointer.get());
		return *this;
	}
	
	/// -> operator
	T* operator -> () const
	{
		return get();
	}
	
	// Return pure current pointer
	T* get() const
	{
		return (T*)ptr;
	}
	
	// Is pointer set. It can be NULL.
	bool is_set()
	{
		return (ptr != NULL);
	}
	
private:
	Obj* ptr;
	
	void incr_counter()
	{
		ptr->ref_counter++;
	}
	
	void decr_counter()
	{
		if(!is_set()) return;
		ptr->ref_counter--;
		check();
	}
	
	void check()
	{
		if(ptr->ref_counter > 0)
			return;
		delete ptr;
		ptr = NULL;
	}
};

#endif /* defined(__Game2__ShrPtr__) */
