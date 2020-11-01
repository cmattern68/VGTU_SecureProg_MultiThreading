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
                else if (nb < pmin || pmin == 0)
                    pmin = nb;
            }
        }
    }

    void performPrimary(std::atomic<std::array<const char *, 1000>> &producer,
                        std::atomic<std::array<const char *, 1000>> &consumer,
                        std::atomic<unsigned long long int> &pmin,
                        std::atomic<unsigned long long int> &pmax,
                        std::atomic<std::size_t> &ftotal,
                        std::atomic<char *> &lfile) {
        for (std::size_t i = 0; i < (producer.load()).size(); ++i) {
            std::array<const char *, 1000> ptmp = producer.load();
            std::array<const char *, 1000> ctmp = consumer.load();
            std::size_t j = 0;
            std::size_t k = 0;
            bool isDone = false;

            for (; ptmp[j] != NULL; ++j);
            if (j > 1000)
                j = ptmp.size();

            for (; ctmp[k] != NULL; ++k) {
                if (ctmp[k] == ptmp[j - 1])
                    isDone = true;
            }
            if (!isDone) {
                ctmp[k] = strdup(ptmp[j - 1]);
                consumer = ctmp;

                std::string filename = ptmp[j - 1];
                lfile = strdup(ptmp[j - 1]);
                ptmp[j - 1] = NULL;
                producer = ptmp;
                ftotal = ftotal + 1;
                getPrimaries(FileLoader::loadFileContent(filename), std::ref(pmin), std::ref(pmax));
            }
        }
    }

    Thread::Thread(std::atomic<std::array<const char *, 1000>> &producer,
                   std::atomic<std::array<const char *, 1000>> &consumer,
                   std::atomic<unsigned long long int> &pmin,
                   std::atomic<unsigned long long int> &pmax,
                   std::atomic<std::size_t> &ftotal,
                   std::atomic<char *> &lfile) {
        _thread = std::make_unique<std::thread>(performPrimary,
                                                std::ref(producer),
                                                std::ref(consumer),
                                                std::ref(pmin),
                                                std::ref(pmax),
                                                std::ref(ftotal),
                                                std::ref(lfile));
        //std::cout << "1 thread added." << std::endl;
    }

    Thread::~Thread() {
        _thread->detach();
        //std::cout << "1 thread removed." << std::endl;
    }
}