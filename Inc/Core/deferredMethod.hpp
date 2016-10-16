#pragma once

#include <Core/deferredFunction.hpp>

namespace core {

template <class T, bool locks = true> class DeferredMethodQueue {
  private:
    T contained;
    DeferredFunctionQueue<locks> dfq;

  public:
    DeferredMethodQueue() : contained() {}

    DeferredMethodQueue(const T &init) : contained(init) {}

    DeferredMethodQueue(const T &&init) : contained(init) {}

    const T &get() const { return contained; }

    template <typename Ret, typename... Args>
    void push(Ret (T::*func)(Args...), Args... args) {
	dfq.template push<Ret, T, Args...>(func, &contained, args...);
    }

    void flush() { dfq.flush(); }
};

} // core
