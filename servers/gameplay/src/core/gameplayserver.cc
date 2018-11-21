#include <iostream>

#include <core/gameplayserver.h>
#include <packets/action.pb.h>

using gameplay::EventPacket;

void GamePlayServer::InitializeSockets(const uint16_t&& port) {
    publishSocket.bind("tcp://*:" + port);
    pullSocket.bind("tcp://*:" + port+1);
}

void GamePlayServer::StartServer() {
    MainServerLoop();
}

void GamePlayServer::MainServerLoop() {
    while (true) {
        std::clog << "Test";

        auto actionPacket = ReceiveAction();

        std::clog << "Test";
        auto processedPacket = ProcessAction(actionPacket);

        std::clog << "Test";
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
            std::optional<EventPacket> movePacket; // { actionPacket };
//            CheckCanMove(const User&);/
            return movePacket;
    }

    return std::nullopt;
}


bool GamePlayServer::BroadCastAction(const std::optional<EventPacket> &eventPacket) {
    if (eventPacket.has_value()) {
        zmq::message_t message { (size_t) eventPacket.value().ByteSize() };
        eventPacket.value().SerializeToArray(message.data(), message.size());
        return publishSocket.send(message);
    }
}