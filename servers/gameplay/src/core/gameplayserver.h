//
// Created by moreal-gram on 2018-08-29.
//

#ifndef WSL_SERVER_H
#define WSL_SERVER_H

#include <thread>
#include <string>
#include <queue>
#include <mutex>

#include <zmq.hpp>

#include <packets/action.pb.h>

using gameplay::EventPacket;

class GamePlayServer {

    struct User {
        struct Position {
            float x;
            float y;
        } position;
    };

 public:
    GamePlayServer(const uint16_t &port)
    : publishSocket(context, ZMQ_PUB),
      pullSocket(context, ZMQ_PULL)
    {
    }

    void StartServer();

 private:

    void InitializeSockets(const uint16_t&&);

    // Utility
    bool CreateRandomMap();
    bool HitScan(const User&, const User&);

    // Loop
    void MainServerLoop();
    EventPacket ReceiveAction();
    std::optional<EventPacket> ProcessAction(const EventPacket&);
    bool BroadCastAction(const std::optional<EventPacket>&);

    zmq::context_t context;
    zmq::socket_t publishSocket;
    zmq::socket_t pullSocket;
};


#endif //WSL_SERVER_H