#include <iostream>

#include <core/gameplayserver.h>
#include <packets/action.pb.h>

void GamePlayServer::StartServer() {
    gameplay::ActionPacket packet;

    MainServerLoop();
}

void GamePlayServer::MainServerLoop() {
    while (true) {
        // PULL
        zmq::message_t message;
        pullSocket.recv(&message);

        message.size();

        // PROCESS

        // PUB
//        zmq::message_t publishMessage(gameplay::ActionPacket::ByteSize());
//        publishMessage.

        publishSocket.send(message);
    }
}
