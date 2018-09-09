//
// Created by moreal-gram on 2018-08-29.
//

#include <chrono>

#include <iostream>
#include <tuple>

#include <MySql.hpp>
#include <base64.h>

#include <core/loginserver.h>

void LoginServer::StartServer() {
    const int available_threads = std::thread::hardware_concurrency();

    if (available_threads < 2) {
        std::cerr << "[ERR] Too Low thread count from hardware_concurrency\n";
        return;
    }

    m_threadPool = new std::thread*[available_threads];

    // IOThread
    m_threadPool[0] = new std::thread([this]() { this->IOThread(); });

    for (int i = 1; i < available_threads; ++i) {
        m_threadPool[i] = new std::thread([this]() { this->WorkerThread(); });
    }

    // All Join
    for (int i = 0; i < available_threads; ++i) {
        m_threadPool[i]->join();
    }
}

void LoginServer::IOThread() {
    std::cout << "IO Thread is On!!\n";

    m_acceptor.listen(50);
//    tcp::socket sock;

    while (true) {
        tcp::socket sock = m_acceptor.accept();
        Packet packet(sock);
        m_packetQueue.push(packet);
    }
}

void LoginServer::WorkerThread() {
    std::cout << "Worker Thread is On!!\n";
    while (true) {
        while (m_packetQueue.empty());
        while (m_packetQueueMutex.try_lock());
        auto packet = m_packetQueue.front();
        m_packetQueue.pop(); // 락으로 인한 병렬성 저하를 최대한 감소시키기 위해서 front()로 복사 후 바로 pop 한다
        m_packetQueueMutex.unlock();

        // how to LOCK FREE algorithm

        HandlePacket(packet);
    }
}

bool LoginServer::Login(LoginPacket &packet) {
    try {
        char _id[5] = { }, _pw[5] = { }, _new_id[9] = { }, _new_pw[9] = { };
        std::memcpy((void*)_id, (void*)&packet.GetId(), 4);
        std::memcpy((void*)_pw, (void*)&packet.GetPw(), 4);
        std::string sId(_id), sNewId, sPw, sNewPw;
        Base64::Encode(sId, &sNewId);
        Base64::Encode(sPw, &sNewPw);

        std::vector<std::tuple<std::string, std::string>> rows;
        m_mySql.runQuery(&rows, "SELECT id, pw FROM accounts WHERE id = '?' and pw = '?';", sNewId, sNewPw);

        if (rows.empty()) {

        }
    } catch(std::exception &ex) {
        ex.what();
    };
    return true;
}

bool LoginServer::Register(RegisterPacket &packet) {
    try {
        char _id[5] = { }, _pw[5] = { }, _new_id[9] = { }, _new_pw[9] = { };
        std::memcpy((void*)_id, (void*)&packet.GetId(), 4);
        std::memcpy((void*)_pw, (void*)&packet.GetPw(), 4);
        Base64::Encode(_id, 4, _new_id, 8);
        Base64::Encode(_pw, 4, _new_pw, 8);
    } catch(std::exception &ex) {
        ex.what();
    };
    return true;
}