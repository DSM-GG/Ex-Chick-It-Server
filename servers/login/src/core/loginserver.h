//
// Created by moreal-gram on 2018-08-29.
//

#ifndef WSL_SERVER_H
#define WSL_SERVER_H

#include <boost/asio.hpp>

#include <iostream>
#include <thread>
#include <string>
#include <queue>
#include <mutex>

#include <MySql.hpp>

#include <packets/loginpacket.h>
#include <packets/registerpacket.h>
#include <core/serverbase.h>

using boost::asio::ip::tcp;

class LoginServer : private ServerBase {
public:
    LoginServer(const uint16_t &port)
    : ServerBase(port),
      mySql("0.0.0.0", "root", "1234") {

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
    void InitializeDatabaseConnection();
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

    MySql mySql;
};


#endif //WSL_SERVER_H
