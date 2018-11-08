#include <iostream>

#include <core/gameplayserver.h>
#include <packets/action.pb.h>

using gameplay::EventPacket;

void GamePlayServer::InitializeSockets(const uint16_t&& port) {
    publishSocket.bind("tcp://*:" + port);
    pullSocket.bind("tcp://*:" + port);
}

void GamePlayServer::StartServer() {
    MainServerLoop();
}

void GamePlayServer::MainServerLoop() {
    while (true) {

        auto actionPacket = ReceiveAction();

        auto processedPacket = ProcessAction(actionPacket);

        BroadCastAction(processedPacket);
    }
}

EventPacket GamePlayServer::ReceiveAction() {
    zmq::message_t message;
    pullSocket.recv(&message);

    EventPacket eventPacket;
    eventPacket.ParseFromArray(message.data(), message.size());

    return eventPacket;
}

std::optional<EventPacket> GamePlayServer::ProcessAction(const EventPacket& actionPacket) {
    switch(actionPacket.type()) {
        case EventPacket::ATTACK:
            break;

        case EventPacket::MOVE:
            std::optional<EventPacket> movePacket;// { actionPacket };
            return movePacket;
    }
    std::optional<EventPacket> wrongEmptyPacket;
    return wrongEmptyPacket;
}
