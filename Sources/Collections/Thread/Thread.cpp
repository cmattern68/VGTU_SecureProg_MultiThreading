#include "Thread.hpp"
#include <iostream>

namespace vgtu::collections {

    void performPrimary(std::atomic<std::array<const char *, 1000>> &files) {
        for (std::size_t i = 0; i < /*(files.load()).size()*/ 2; ++i) {
            std::array<const char *, 1000> tmp = files.load();
            std::size_t j = 0;
            for (; tmp[j] != NULL; ++j);
            if (j > 1000)
                j = tmp.size();

            //std::cout << std::endl << "1: tmp[" << j - 1 << "]  " << tmp[j - 1] << " - end" << std::endl;
            tmp[j - 1] = NULL;
            files = tmp;
        }
    }

    Thread::Thread(std::atomic<std::array<const char *, 1000>> &files) {
        _thread = std::make_unique<std::thread>(performPrimary, std::ref(files));
        std::cout << "1 thread added." << std::endl;
    }

    Thread::~Thread() {
        _thread->detach();
        std::cout << "1 thread removed." << std::endl;
    }
}