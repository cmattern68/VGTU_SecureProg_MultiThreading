#include "Thread.hpp"
#include <iostream>
#include <string.h>

namespace vgtu::collections {

    std

    void performPrimary(std::atomic<std::array<const char *, 1000>> &files, std::atomic<unsigned long long int> &pmin, std::atomic<unsigned long long int> &pmax, std::atomic<std::size_t> &ftotal, std::atomic<char *> &lfile) {
        (void)pmin;
        (void)pmax;
        for (std::size_t i = 0; i < /*(files.load()).size()*/ 2; ++i) {
            std::array<const char *, 1000> tmp = files.load();
            std::size_t j = 0;
            for (; tmp[j] != NULL; ++j);
            if (j > 1000)
                j = tmp.size();

            //std::cout << std::endl << "1: tmp[" << j - 1 << "]  " << tmp[j - 1] << " - end" << std::endl;
            lfile = strdup(tmp[j - 1]);
            tmp[j - 1] = NULL;
            files = tmp;
            ftotal = ftotal + 1;
        }
    }

    Thread::Thread(std::atomic<std::array<const char *, 1000>> &files, std::atomic<unsigned long long int> &pmin, std::atomic<unsigned long long int> &pmax, std::atomic<std::size_t> &ftotal, std::atomic<char *> &lfile) {
        _thread = std::make_unique<std::thread>(performPrimary, std::ref(files), std::ref(pmin), std::ref(pmax), std::ref(ftotal), std::ref(lfile));
        std::cout << "1 thread added." << std::endl;
    }

    Thread::~Thread() {
        _thread->detach();
        std::cout << "1 thread removed." << std::endl;
    }
}