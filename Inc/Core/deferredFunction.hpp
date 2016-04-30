#pragma once

#include <functional>
#include <vector>
#include <mutex>

namespace core {

template<bool locks = true>
class DeferredFunctionQueue{
private:
    std::vector<std::function<void()>> funQueue;
    std::mutex mtx;

public:
    DeferredFunctionQueue(){}

    template<typename Fn, typename ...Args>
    void push(Fn function, Args... args){
	if(locks)mtx.lock();
    
	funQueue.push_back(
		std::bind(function, args...)
	);

	if(locks)mtx.unlock();
    }

    void flush(){
	if(locks){
	    mtx.lock();
	}

	for(auto& fn : funQueue){
	    fn();
	}
	funQueue.clear();

	if(locks){
	    mtx.unlock();
	}
    }


};

} //core
