//
// Created by moreal-gram on 2018-08-30.
//

#ifndef WSL_IO_SERVICE_POOL_H
#define WSL_IO_SERVICE_POOL_H

#include <boost/asio.hpp>

#include <iostream>
#include <memory>

class IOServicePool {
private:
    boost::asio::io_service* ioServices;
    int nextService;

public:
    IOServicePool(const int poolSize=100) : nextService(0) {
        using boost::asio::io_service;
        ioServices = new io_service[poolSize];
    }

    ~IOServicePool() {
        delete[] ioServices;
    }

    boost::asio::io_service* get_io_service() {
        if (nextService == 100) {
            std::cerr << "[ERR] Pool is full!\n";
            return nullptr;
        }
        else {
            return &ioServices[nextService++];
        }
    }
};

#endif //WSL_IO_SERVICE_POOL_H
