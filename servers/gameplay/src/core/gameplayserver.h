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

#include <core/serverbase.h>

using boost::asio::ip::tcp;

class GamePlayServer : private ServerBase {
public:
    GamePlayServer(const uint16_t &port)
    : ServerBase(port) {

    }

    void StartServer();

private:

    inline void HandlePacket(Packet& packet) {
        switch (packet.GetPacketType()) {
        case ACTION_PACKET:
            break;

        default:
            break;
        }
    }

    int GetAvailableThreadCount() const;
    Packet GetNextPacket();

    void AcceptSocketConnectionAndSavePacket();

    void StartToAccessPacketQueue();
    void FinishToAccessPacketQueue();

    void InitializeIOThread();
    void InitializeWorkerThreads();

    void InitializeThreadPool();
    void StartThreadPool();

    // Main Functions
    bool ProcessAction();
    bool BroadCast(RegisterPacket&);

    // Utility
    bool CreateRandomMap();
    bool HitScan();

    virtual void IOThread() override;
    virtual void WorkerThread() override;

    std::thread** threadPool = nullptr;

    std::mutex packetQueueMutex;
    std::queue<Packet> packetQueue;
};


#endif //WSL_SERVER_H