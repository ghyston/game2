//
//  MemPool.hpp
//  Game2
//
//  Created by Ilja Stepanow on 26/12/2016.
//  Copyright © 2016 Stepanov Ilia. All rights reserved.
//

#ifndef MemPool_hpp
#define MemPool_hpp

#include <stack>
#include <vector>
#include <cassert>
#include <set>

using namespace std;

namespace kringle {
    
    template<class T>
    class MemPool
    {
    public:
        
        // Create new object in pool and call c-tor
        static T * const newObj();
        
        // Call d-tor to object, mark mem as free
        static void delObj(T * obj);
        
        // Remove all objects in pool, release memory.
        // @note: O(log(chunk_size)) + O(log(chunks_count))
        static void clear();
        
    private:
        
        static void createNewChunk();
        static bool isObjInPool(T* obj);
        
        static stack<T*> freePlaces;
        static vector<T*> chunks;
        
        static constexpr size_t CHUNK_SIZE = 32;
    };
    
    template <class T>
    stack<T*> MemPool<T>::freePlaces;
    
    template <class T>
    vector<T*> MemPool<T>::chunks;
    
    template<class T>
    T * const MemPool<T>::newObj()
    {
        if(freePlaces.empty())
            createNewChunk();
        
        T* memory = freePlaces.top();
        freePlaces.pop();
        
        return new(memory)T;
    }
    
    template<class T>
    void MemPool<T>::delObj(T * obj)
    {
        assert(isObjInPool(obj));
        
        obj->~T();
        freePlaces.push(obj);
    }
    
    template<class T>
    void MemPool<T>::clear()
    {
        // Transfer stack to set
        set<T*> freePlacesSet;
        while (!freePlaces.empty()) {
            freePlacesSet.insert(freePlaces.top());
            freePlaces.pop();
        }
        
        for(auto it : chunks)
        {
            // Call destructors to all objects, that are not in freePlaces
            for (size_t i = 0; i < CHUNK_SIZE; i++)
            {
                T * chunkFirst = it;
                T * p = chunkFirst + i;
                auto tmp = freePlacesSet.find(p);
                if(tmp == freePlacesSet.end()) // not found, means its not empty, d-tor should be called
                    p->~T();
                else
                    freePlacesSet.erase(tmp); // this empty space is found, remove from set
            }
            free(it);
        }
        
        assert(freePlaces.empty());
        chunks.clear();
    }
    
    template<class T>
    void MemPool<T>::createNewChunk()
    {
        T * pT = (T*)malloc(sizeof(T) * CHUNK_SIZE);
        chunks.push_back(pT);
        for(size_t i = 0; i < CHUNK_SIZE; i++)
        {
            freePlaces.push(pT + i);
        }
    }
    
    template<class T>
    bool MemPool<T>::isObjInPool(T* obj)
    {
        for(auto it : chunks)
        {
            //@todo: check this
            T * chunkFirst = it;
            int index = (obj - chunkFirst) % sizeof(T);
            if((index >= 0) && (index < CHUNK_SIZE))
                return true;
        }
        return false;
    }
}

#endif /* MemPool_hpp */
