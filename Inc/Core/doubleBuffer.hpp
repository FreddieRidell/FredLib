#pragma once

namespace core {

template<class T>
DoubleBuffer{
private:
    bool index;
    T buffer[2];

public:
    DoubleBuffer():
	    index(0){
	buffer = new[2] T;
    }
    template<typename... Params>
    DoubleBuffer(Params p):
	    index(0){
	buffer = new[2] T;
	buffer[0] = T(p);
	buffer[1] = T(p);
    }
    
    const T& read()const{return buffer[index];}
    T& write(){return buffer[1-index];}
    void write(const T& t){buffer[1-index] = t;}

    void swap(){index = 1-index;}

};

} //core
