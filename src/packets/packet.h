//
// Created by moreal-gram on 2018-08-29.
//

#ifndef WSL_PACKET_H
#define WSL_PACKET_H

#include <boost/asio.hpp>
#include "../core/memorystream.h"

using namespace boost::asio::ip;

using PacketType = uint8_t;

enum Type : uint8_t {

    // ERROR CASE
    WRONG_PACKET,

    // LoginServer => Artoria
    LOGIN_PACKET,
    REGISTER_PACKET,
    ARTORIA_RESPONSE_PACKET,

    // LobbyServer for Lobby and MatchMaking => Matcher
    GET_VAR_PACKET, // With Arg Enum
    MATCH_MAKING_REQUEST_PACKET,
    MATCH_MAKING_RESPONSE_PACKET,

    // LogicServer => Logic, Docker
    UPDATE_VAR_PACKET, // With Enum Arg
    ACTION_PACKET, // With Enum Arg

    // LogicServer To LobbyServer
    GAME_END_PACKET,

    // LobbyServer To LogicServer
    GAME_START_PACKET,
};

class Packet {
public:
    Packet(tcp::socket& socket) : m_socket(&socket) {
        switch (m_packetType) {
        case LOGIN_PACKET:
            // Get ID and PW as hash value
            // so account values are statical

            // Hash -> MD5 ( || Something)
            // ID 4 byte / PW 4 byte

            // one more hashing with salt

            // TODO: Make DB Connection and SELECT

            break;

        case REGISTER_PACKET:
            // Get ID and PW as hash value
            // Hash -> MD5 ( || Another Something)
            // ID 4 byte / PW 4 byte

            // one more hashing with salt

            // TODO: Make DB Connection and INSERT

            break;

        default:
            m_packetType = WRONG_PACKET;
        }
    }

    inline PacketType GetPacketType() const { return m_packetType; }
    inline tcp::socket& GetSocket() { return *m_socket; }
    inline void Close() const { m_socket->close(); }
    inline void* GetBuffer() const { return m_buffer; }

private:
    tcp::socket* m_socket;
    PacketType m_packetType;
    void* m_buffer;
};

#endif //WSL_PACKET_H
