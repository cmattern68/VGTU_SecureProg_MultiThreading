#include "Thread.hpp"
#include <iostream>
#include <string.h>
#include <vector>
#include <FileLoader.hpp>
#include <string>

namespace vgtu::collections {

    bool isPrime(unsigned long long int nb) {
        if (nb <= 0 || nb == 1) {
            return false;
        }
        else {
            for (unsigned long long int i = 2; i <= (nb / 2); ++i) {
                if (nb % i == 0) {
                    return false;
                    break;
                }
            }
        }
        return true;
    }

    void getPrimaries(std::vector<unsigned long long int> content, std::atomic<unsigned long long int> &pmin, std::atomic<unsigned long long int> &pmax) {
        for (const unsigned long long int &nb : content) {
            if (isPrime(nb)) {
                if (nb > pmax)
                    pmax = nb;
                else if (nb < pmin)
                    pmin = nb;
            }
        }
    }

    void performPrimary(std::atomic<std::array<const char *, 1000>> &files, std::atomic<unsigned long long int> &pmin, std::atomic<unsigned long long int> &pmax, std::atomic<std::size_t> &ftotal, std::atomic<char *> &lfile) {
        (void)pmin;
        (void)pmax;
        for (std::size_t i = 0; i < (files.load()).size(); ++i) {
            std::array<const char *, 1000> tmp = files.load();
            std::size_t j = 0;
            for (; tmp[j] != NULL; ++j);
            if (j > 1000)
                j = tmp.size();

            //std::cout << std::endl << "1: tmp[" << j - 1 << "]  " << tmp[j - 1] << " - end" << std::endl;
            getPrimaries(FileLoader::loadFileContent(std::string(tmp[j - 1])), std::ref(pmin), std::ref(pmax));
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