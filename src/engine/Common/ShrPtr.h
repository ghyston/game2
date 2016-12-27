//
//  ShrPtr.h
//  Game2
//
//  Created by Stepanov Ilia on 01/12/13.
//  Copyright (c) 2013 Stepanov Ilia. All rights reserved.
//

#ifndef __Game2__ShrPtr__
#define __Game2__ShrPtr__

//@todo: move to engine/memory
#include <iostream>
#include "../RefCounter.h"
#include "../MemPool.h"

namespace kringle {

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
        ptr = pointer.ptr;
		incr_counter();
	}
	
	// D-tor.
	~ShrPtr() { decr_counter(); }
	
	
	/// assignment of clPtr
	ShrPtr& operator = ( const ShrPtr& pointer )
	{
		set(pointer.get());
		return *this;
	}
	
    //@todo: check, do we need it somewhere, except entity components container
	/// -> operator
	T* operator -> () const
	{
		return get();
	}
	
	// Is pointer set. It can be NULL.
	bool is_set()
	{
		return (ptr != NULL) && (ptr->p != NULL);
	}
	
private:
	RefCounter<T>* ptr = NULL;
	
	void incr_counter()
	{
		ptr->counter++;
	}
	
	void decr_counter()
	{
		if(!is_set()) return;
		ptr->counter--;
		check();
	}
    
    // Set pointer to this ShrPtr. @note: prev pointer, if exist, realesed
    void set(T* ptr)
    {
        decr_counter();
        
        this->ptr = MemPool<RefCounter<T>>::newObj();
        this->ptr->p = ptr;
        
        if(is_set())
            incr_counter();
    }
    
    // Return pure current pointer
    T* get() const
    {
        return ptr->p;
    }
	
	void check()
	{
        if(ptr == nullptr)
            return;
        
		if(ptr->ref_counter > 0)
			return;
        
        if(ptr->p != nullptr)
            MemPool<T>::delObj(ptr->p);
            
        MemPool<RefCounter<T> >::delObj(ptr);
		ptr = NULL;
	}
};
    
}

#endif /* defined(__Game2__ShrPtr__) */
