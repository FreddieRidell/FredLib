#pragma once

#include <array>

namespace core {

template<class T>
class DoubleBuffer{
private:
    bool index;
    std::array<T, 2> buffer;

public:
    DoubleBuffer():
	    index(0),
	    buffer({{T(), T()}})
    {
    }
    DoubleBuffer(const T& init):
	    index(0),
	    buffer({{init, init}})
    {
    }
    
    const T& read()const{return buffer[index];}
    T& write(){return buffer[1-index];}
    void write(const T& t){buffer[1-index] = t;}
    void sync(){ write(read()); }

    void swap(){index = 1-index;}

};

} //core
