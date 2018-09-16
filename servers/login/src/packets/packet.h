//
// Created by moreal-gram on 2018-08-29.
//

#ifndef WSL_PACKET_H
#define WSL_PACKET_H

#include <boost/asio.hpp>
#include "core/memorystream.h"

using namespace boost::asio::ip;

using PacketType = uint8_t;

enum Type : uint8_t {

    // ERROR CASE
    WRONG_PACKET,

    // LoginServer
    LOGIN_PACKET,
    REGISTER_PACKET,
    RESPONSE_PACKET,
//
//    // LobbyServer for Lobby and MatchMaking => Matcher
//    GET_VAR_PACKET, // With Arg Enum
//    MATCH_MAKING_REQUEST_PACKET,
//    MATCH_MAKING_RESPONSE_PACKET,
//
//    // LogicServer => Logic, Docker
//    UPDATE_VAR_PACKET, // With Enum Arg
//    ACTION_PACKET, // With Enum Arg
//
//    // LogicServer To LobbyServer
//    GAME_END_PACKET,
//
//    // LobbyServer To LogicServer
//    GAME_START_PACKET,
};

class Packet {
public:
    struct ArtoriaPacketData {
        PacketType packetType;
        char data[8];
    };

    struct ArtoriaAccountPacketData {
        PacketType packetType;
        uint32_t id, pw;
    };

    Packet(tcp::socket& socket) : m_socket(&socket) {
        socket.receive(boost::asio::buffer(&m_data, sizeof(ArtoriaPacketData)));

        PacketType& packetType = m_data.packetType;

        switch (packetType) {
        case LOGIN_PACKET:
        case REGISTER_PACKET:
            break;

        default:
            packetType = WRONG_PACKET;
            break;
        }
    }

    ~Packet() {
        m_socket->close();
    }

    inline PacketType GetPacketType() const { return m_data.packetType; }
    inline tcp::socket& GetSocket() { return *m_socket; }

    template <typename T>
    inline T& GetDataAs() const { return *(T*)(&m_data); }

    inline struct ArtoriaAccountPacketData& GetDataAsAccountData() const { return GetDataAs<ArtoriaAccountPacketData>(); }

private:
    tcp::socket* m_socket;
    struct ArtoriaPacketData m_data;
};

#endif //WSL_PACKET_H
