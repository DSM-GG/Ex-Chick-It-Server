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

#include <MySql.hpp>

#include <core/serverbase.h>

using boost::asio::ip::tcp;

class LoginServer : private ServerBase {
public:
    LoginServer(const uint16_t &port) : ServerBase(port), m_mySql("0.0.0.0", "root", "1234", "account") { }

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
//            Log
            break;
        }
    }

    // Main Functions
    bool Login(LoginPacket&);
    bool Register(RegisterPacket&);

    // Utility
    bool ExistAccount(const std::string&, const std::string&);
    bool ExistAccount(const std::string&);
    std::string GetInitializeQuery() const;

    // Interface, Abstracted
    virtual void IOThread() override;
    virtual void WorkerThread() override;

    std::thread** m_threadPool = nullptr;

    std::mutex m_packetQueueMutex;
    std::queue<Packet> m_packetQueue;

    MySql m_mySql;
};


#endif //WSL_SERVER_H
