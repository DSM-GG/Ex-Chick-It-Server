//
// Created by moreal-gram on 2018-08-30.
//

#ifndef WSL_SERVERBASE_H
#define WSL_SERVERBASE_H

#include <packets/packet.h>

#include <boost/asio.hpp>

using boost::asio::ip::tcp;

class ServerBase {
public:
    ServerBase(
            const uint16_t &PORT_NUM=40000,
            const int &POOL_SIZE=100,
            const int &BUFFER_SIZE=540
    ) : buffer(new char[BUFFER_SIZE]),
        acceptor(ioService, tcp::endpoint(tcp::v4(), PORT_NUM)) {

    }

protected:
    char *buffer;
    boost::asio::io_service ioService;

    tcp::acceptor acceptor;

    virtual void IOThread() = 0;
    virtual void WorkerThread() = 0;
};


#endif //WSL_SERVERBASE_H
