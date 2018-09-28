//
// Created by moreal-gram on 2018-08-29.
//

#include <chrono>

#include <iostream>
#include <fstream>
#include <tuple>

#include <MySql.hpp>
#include <base64.h>

#include <core/LogicServer.h>

void LogicServer::StartServer() {
    // Initialize Threads
    const int available_threads = std::thread::hardware_concurrency() - 1; // TODO Change

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

    // Running Threads
    for (int i = 0; i < available_threads; ++i) {
        m_threadPool[i]->join();
    }
}

void LogicServer::IOThread() {
    std::clog << "IO Thread is On!!\n";

    m_acceptor.listen(50);

    while (true) {
        tcp::socket sock = m_acceptor.accept();
        Packet packet(sock);
        m_packetQueue.push(packet);
    }
}

void LogicServer::WorkerThread() {
    std::clog << "Worker Thread is On!!\n";
    while (true) {
        while (m_packetQueue.empty());
        while (m_packetQueueMutex.try_lock());
        auto packet = m_packetQueue.front();
        m_packetQueue.pop(); // 락으로 인한 병렬성 저하를 최대한 감소시키기 위해서 front()로 복사 후 바로 pop 한다
        m_packetQueueMutex.unlock();

        // FIXME: how to LOCK FREE algorithm

        HandlePacket(packet);
    }
}

bool LogicServer::ExistAccount(const std::string &id, const std::string &pw) {
    std::vector<std::tuple<std::string, std::string>> rows;
    m_mySql.runQuery(&rows, "SELECT id, pw FROM accounts WHERE id = '?' and pw = '?';", id, pw);

    return !rows.empty();
}

bool LogicServer::ExistAccount(const std::string &id) {
    std::vector<std::tuple<std::string, std::string>> rows;
    m_mySql.runQuery(&rows, "SELECT id, pw FROM accounts WHERE id = '?';", id);

    return !rows.empty();
}

std::string LogicServer::GetInitializeQuery() const {
    std::ifstream ifs("sql/accounts.sql");

    std::string query;
    std::getline(ifs, query, '\0');

    return query;
}

bool LogicServer::Login(LoginPacket &packet) {
    try {
        std::string id((char*) &packet.GetId()), pw((char*) &packet.GetPw()), bId, bPw;
        Base64::Encode(id, &bId);
        Base64::Encode(pw, &bPw);

        if (ExistAccount(bId, bPw)) {
            std::clog << "Login!!\n";
            packet.GetSocket().send("123");
        } else {
            std::clog << "Wrong Account\n";
        }
    } catch(std::exception &ex) {
        ex.what();
    };
    return true;
}

bool LogicServer::Register(RegisterPacket &packet) {
    try {
        std::string id((char*) &packet.GetId()), pw((char*) &packet.GetPw()), bId, bPw;
        Base64::Encode(id, &bId);
        Base64::Encode(pw, &bPw);

        if (ExistAccount(id)) {
            std::clog << "Already there is the id\n";
        } else {
            std::clog << "Register!!\n";
            m_mySql.runCommand("INSERT INTO accounts VALUES('?', '?');", bId, bPw);
        }
    } catch(std::exception &ex) {
        ex.what();
    };
    return true;
}