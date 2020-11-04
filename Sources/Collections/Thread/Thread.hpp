#ifndef THREAD_HPP
#define THREAD_HPP

#include <thread>
#include <atomic>
#include <array>
#include <memory>
#include "Window.hpp"

namespace vgtu::collections {
    class Thread {
    public:
        ~Thread();
        Thread(std::atomic<std::array<const char *, 1000>> &,
                std::atomic<std::array<const char *, 1000>> &,
                std::atomic<unsigned long long int> &,
                std::atomic<unsigned long long int> &,
                std::atomic<std::size_t> &,
                std::atomic<char *> &,
               unsigned short int);
        Thread(const Thread &) = delete;
        Thread &operator=(const Thread &) = delete;
    private:
        std::unique_ptr<std::thread> _thread;
    };
}

#endif
