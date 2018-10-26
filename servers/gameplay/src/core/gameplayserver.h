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
    : firstUser(context, ZMQ_REP),
      secondUser(context, ZMQ_REP)
    {
        firstUser.bind("tcp://*:" + port);
        secondUser.bind("tcp://*:" + port);
    }

    void StartServer();

private:
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

    zmq::context_t context;
    zmq::socket_t secondUser;
    zmq::socket_t firstUser;
};


#endif //WSL_SERVER_H