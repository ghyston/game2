//
//  RefCounter.h
//  Game2
//
//  Created by Ilja Stepanow on 26/12/2016.
//  Copyright © 2016 Stepanov Ilia. All rights reserved.
//

#ifndef RefCounter_h
#define RefCounter_h

#include "MemPool.h"

namespace kringle {

template <class T>
class RefCounter
{
private:
    
    RefCounter() = default;
    ~RefCounter() = default;
    RefCounter(const RefCounter&) = default;
    
    int counter = 0;
    T * p = NULL;
    bool deleted = false;
    
public:
    
    RefCounter * create(T * p)
    {
        RefCounter * inst = new RefCounter();
        inst->p = p;
        return inst;
    }
        
    /*void inc() { counter++; }
    
    void dec()
    {
        counter--;
        if(counter > 0)
            return;
        
        if(p != NULL)
            MemPool<T>::delObj(p);
        
        MemPool<RefCounter<T> >::delObj(this);
    }*/
    
    //friend class ShrPtr;
    
    void markDeleted() { deleted = true; }
    bool isDeleted() { return deleted; }
    
};
    
}


#endif /* RefCounter_h */
