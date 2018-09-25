//
// Created by moreal-gram on 2018-08-29.
//

#ifndef WSL_SERVER_H
#define WSL_SERVER_H

#include <boost/asio.hpp>

#include <thread>
#include <string>
#include <queue>
#include <mutex>

#include <packets/loginpacket.h>
#include <packets/registerpacket.h>

#include <core/serverbase.h>

using boost::asio::ip::tcp;

class GamePlayServer : private ServerBase {
public:
    // 플레이 서버
    // 공격
    /*
     * 액션 목록
     * ---------
     * 공격 (총)
     * 이동
     * ㅌ
     */
    GamePlayServer(const uint16_t &port) : ServerBase(port) { }

    void StartServer();

private:

    inline void HandlePacket(Packet& packet) {
        switch (packet.GetPacketType()) {
        case Packet:
            Login(*reinterpret_cast<LoginPacket*>(&packet));
            break;

        case REGISTER_PACKET:
            Register(*reinterpret_cast<RegisterPacket*>(&packet));
            break;

        default:
            packet.SetPacketType(WRONG_PACKET);
//            Log
            break;
        }
    }

    // Main Functions
    bool ProcessAction();
    bool BroadCast(RegisterPacket&);
    bool Pasue();

    // Utility
    bool CreateRandomMap();
    bool HitScan();

    // Interface, Abstracted
    virtual void IOThread() override;
    virtual void WorkerThread() override;

    std::thread** m_threadPool = nullptr;

    std::mutex m_packetQueueMutex;
    std::queue<Packet> m_packetQueue;
};


#endif //WSL_SERVER_H
