#include <iostream>

#include <core/gameplayserver.h>
#include <packets/action.pb.h>

using gameplay::ActionPacket;

void GamePlayServer::StartServer() {
    gameplay::ActionPacket packet;

    MainServerLoop();
}

void GamePlayServer::MainServerLoop() {
    while (true) {

        message.size();

        // PROCESS

        // PUB
//        zmq::message_t publishMessage(gameplay::ActionPacket::ByteSize());
//        publishMessage.

        publishSocket.send(message);
    }
}

ActionPacket GamePlayServer::ReceiveAction() {
    zmq::message_t message;
    pullSocket.recv(&message);

    ActionPacket actionPacket;
    actionPacket.ParseFromArray(message.data(), message.size());

    return actionPacket;
}

ActionPacket GamePlayServer::ProcessAction(gameplay::ActionPacket&& actionPacket) {
    if (actionPacket.is_move()) {
        // Process Move
    } else if (actionPacket.is_attack()) {
        // Process Attack
    } else {
        // Wrong input
    }
}