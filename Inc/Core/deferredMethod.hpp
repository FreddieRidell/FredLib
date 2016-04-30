#pragma once

#include <Core/deferredFunction.hpp>

namespace core {

template<class T, bool locks = true>
class DeferredMethodQueue{
private:
    T containedObject;
    DeferredFunctionQueue<locks> funQueue;

public:
    DeferredMethodQueue(){}

    const T& read()const{return containedObject;}

    template<typename Fn, typename ...Args>
    void push(Fn function, Args... args){
	funQueue.push(function, containedObject, args...);
    }
    void flush(){
	funQueue.flush();
    }
};

} //core
