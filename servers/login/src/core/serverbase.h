//
// Created by moreal-gram on 2018-08-30.
//

#ifndef WSL_SERVERBASE_H
#define WSL_SERVERBASE_H

#include <core/io_service_pool.h>
#include <packets/packet.h>

#include <boost/asio.hpp>

using boost::asio::ip::tcp;

class ServerBase {
public:
    ServerBase(const uint16_t &PORT_NUM=40000, const int &POOL_SIZE=100, const int &BUFFER_SIZE=540) : m_buffer(new char[BUFFER_SIZE]),
        m_ios_pool(POOL_SIZE), m_acceptor(*m_ios_pool.get_io_service(), tcp::endpoint(tcp::v4(), PORT_NUM)){ }

protected:
    char *m_buffer;
    IOServicePool m_ios_pool;

    tcp::acceptor m_acceptor;

    virtual void IOThread() = 0;
    virtual void WorkerThread() = 0;

//    inline void HandleWrongPacket(Packet& packet) {
//        packet.GetSocket();
//    }
};


#endif //WSL_SERVERBASE_H
