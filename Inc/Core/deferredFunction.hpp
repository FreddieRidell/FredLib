#pragma once

#include <functional>
#include <vector>
#include <mutex>

namespace core {

template <bool locks = true> class DeferredFunctionQueue {
  private:
    std::vector<std::function<void()>> funQueue;
    std::mutex mtx;

  public:
    DeferredFunctionQueue() {}

    template <typename Ret, typename... Args>
    void push(Ret func(Args...), Args... args) {
	if (locks)
	    mtx.lock();

	funQueue.push_back(std::bind(func, args...));

	if (locks)
	    mtx.unlock();
    }

    template <typename Ret = void, class Class, typename... Args>
    void push(Ret (Class::*func)(Args...), Class *inst, Args... args) {
	if (locks)
	    mtx.lock();

	funQueue.push_back(std::bind(func, inst, args...));

	if (locks)
	    mtx.unlock();
    }

    void flush() {
	if (locks)
	    mtx.lock();

	for (auto &fn : funQueue) {
	    fn();
	}
	funQueue.clear();

	if (locks)
	    mtx.unlock();
    }
};

} // core
