//
// Created by moreal-gram on 2018-08-29.
//

#ifndef WSL_SERVER_H
#define WSL_SERVER_H

#include <iostream>
#include <thread>
#include <string>
#include <queue>
#include <mutex>

#include <packets/loginpacket.h>
#include <packets/registerpacket.h>
#include <core/serverbase.h>

#include <mysql++/mysql++.h>

class LoginServer : private ServerBase {
public:
    LoginServer(const uint16_t &port)
    : ServerBase(port) {
        mySql.connect("0.0.0.0", "root", "1234");
        mysqlpp::Query query = mySql.query("");
        query.
    }

    void StartServer();

private:

    inline void HandlePacket(Packet& packet) {
        switch (packet.GetPacketType()) {
        case LOGIN_PACKET:
            Login(*reinterpret_cast<LoginPacket*>(&packet));
            break;

        case REGISTER_PACKET:
            Register(*reinterpret_cast<RegisterPacket*>(&packet));
            break;

        default:
            std::clog << "Wrong Packet\n";
            break;
        }
    }

    // Main Functions
    bool Login(LoginPacket&);
    bool Register(RegisterPacket&);

    // Utility
    std::string GetInitializeQuery() const;
    int GetAvailableThreadCount() const;
    Packet GetNextPacket();

    void AcceptSocketConnectionAndSavePacket();

    void StartToAccessPacketQueue();
    void FinishToAccessPacketQueue();

    void InitializeDatabaseConnection();

    void InitializeIOThread();
    void InitializeWorkerThreads();

    void InitializeThreadPool();
    void StartThreadPool();

    bool ExistAccount(const std::string&, const std::string&);
    bool ExistAccount(const std::string&);

    // Interface, Abstracted
    virtual void IOThread() override;
    virtual void WorkerThread() override;

    std::thread** threadPool = nullptr;

    std::mutex packetQueueMutex;
    std::queue<Packet> packetQueue;

    mysqlpp::Connection mySql;

};


#endif //WSL_SERVER_H
