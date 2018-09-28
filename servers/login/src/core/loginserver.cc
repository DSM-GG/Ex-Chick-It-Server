#include <chrono>

#include <iostream>
#include <fstream>
#include <tuple>

#include <MySql.hpp>
#include <base64.h>

#include <core/loginserver.h>
#include <core/serverbase.h>

void LoginServer::StartServer() {
    InitializeDatabaseConnection();
    InitializeThreadPool();
    StartThreadPool();
}

void LoginServer::IOThread() {
    acceptor.listen(50);

    while (true) {
        AcceptSocketConnectionAndSavePacket();
    }
}

void LoginServer::AcceptSocketConnectionAndSavePacket() {
    tcp::socket sock = acceptor.accept();
    Packet packet(sock);
    packetQueue.push(packet);
}

void LoginServer::WorkerThread() {
    while (true) {
        StartToAccessPacketQueue();
        auto packet = GetNextPacket();
        FinishToAccessPacketQueue();

        HandlePacket(packet);
    }
}

bool LoginServer::ExistAccount(const std::string &id, const std::string &pw) {
    std::vector<std::tuple<std::string, std::string>> rows;
    mySql.runQuery(&rows, "SELECT id, pw FROM accounts WHERE id = '?' and pw = '?';", id, pw);
    return !rows.empty();
}

bool LoginServer::ExistAccount(const std::string &id) {
    std::vector<std::tuple<std::string, std::string>> rows;
    mySql.runQuery(&rows, "SELECT id, pw FROM accounts WHERE id = '?';", id);
    return !rows.empty();
}

void LoginServer::InitializeDatabaseConnection() {
    try {
        mySql.runCommand("CREATE DATABASE IF NOT EXISTS accounts;");
        mySql.runCommand("use accounts;");
        mySql.runCommand(GetInitializeQuery().c_str());
    } catch (MySqlException& ex) {
        std::clog << ex.what() << '\n';
    }
}

void LoginServer::InitializeIOThread() {
    threadPool[0] = new std::thread([this]() { this->IOThread(); });
}

void LoginServer::InitializeWorkerThreads() {
    for (int i = 1; i < GetAvailableThreadCount(); ++i) {
        threadPool[i] = new std::thread([this]() { this->WorkerThread(); });
    }
}

void LoginServer::InitializeThreadPool() {
    auto availableThreadCount = GetAvailableThreadCount();
    threadPool = new std::thread*[availableThreadCount];
    InitializeIOThread();
    InitializeWorkerThreads();
}

int LoginServer::GetAvailableThreadCount() const {
    return std::thread::hardware_concurrency() - 1;
}

void LoginServer::StartThreadPool() {
    const int available_threads = GetAvailableThreadCount();

    for (int i = 0; i < available_threads; ++i) {
        threadPool[i]->join();
    }
}

void LoginServer::StartToAccessPacketQueue() {
    while (packetQueue.empty());
    while (packetQueueMutex.try_lock());
}

void LoginServer::FinishToAccessPacketQueue() {
    packetQueue.pop();
    packetQueueMutex.unlock();
}

std::string LoginServer::GetInitializeQuery() const {
    std::ifstream ifs("sql/accounts.sql");

    std::string query;
    std::getline(ifs, query, '\0');

    return query;
}

Packet LoginServer::GetNextPacket() {
    StartToAccessPacketQueue();
    auto packet = packetQueue.front();
    FinishToAccessPacketQueue();

    return packet;
}

bool LoginServer::Login(LoginPacket &packet) {
    try {
        std::string id((char*) &packet.GetId()), pw((char*) &packet.GetPw()), bId, bPw;
        Base64::Encode(id, &bId);
        Base64::Encode(pw, &bPw);

        if (ExistAccount(bId, bPw)) {
            return true;
        } else {
            return false;
        }
    } catch(std::exception &ex) {
        ex.what();
    };
}

bool LoginServer::Register(RegisterPacket &packet) {
    try {
        std::string id((char*) &packet.GetId()), pw((char*) &packet.GetPw()), bId, bPw;
        Base64::Encode(id, &bId);
        Base64::Encode(pw, &bPw);

        if (ExistAccount(id)) {;
            return false;
        } else {
            mySql.runCommand("INSERT INTO accounts VALUES('?', '?');", bId, bPw);
            std::clog << "Register!!\n";
            return true;
        }
    } catch(std::exception &ex) {
        ex.what();
    };
}