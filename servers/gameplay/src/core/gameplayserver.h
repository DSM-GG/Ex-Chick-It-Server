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

class GamePlayServer {
public:

    GamePlayServer(const uint16_t &port)
    : publishSocket(context, ZMQ_PUB),
      pullSocket(context, ZMQ_PULL)
    {
        publishSocket.bind("tcp://*:" + port);
        pullSocket.bind("tcp://*:" + port);
    }

    void StartServer();

private:
    // Main Functions
    bool BroadCast(gameplay::ActionPacket&);

    // Utility
    bool CreateRandomMap();
    bool HitScan(gameplay::User&, gameplay::User&);

    // Loop
    void MainServerLoop();
    gameplay::ActionPacket ProcessAction(gameplay::ActionPacket);

    zmq::context_t context;
    zmq::socket_t publishSocket;
    zmq::socket_t pullSocket
};


#endif //WSL_SERVER_H