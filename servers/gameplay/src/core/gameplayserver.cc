#include <iostream>

#include <core/gameplayserver.h>

void GamePlayServer::StartServer() {
    InitializeThreadPool();
    StartThreadPool();
}

void GamePlayServer::IOThread() {
    acceptor.listen(50);

    while (true) {
        AcceptSocketConnectionAndSavePacket();
    }
}

void GamePlayServer::AcceptSocketConnectionAndSavePacket() {
    tcp::socket sock = acceptor.accept();
    Packet packet(sock);
    packetQueue.push(packet);
}

void GamePlayServer::WorkerThread() {
    while (true) {
        StartToAccessPacketQueue();
        auto packet = GetNextPacket();
        FinishToAccessPacketQueue();

        HandlePacket(packet);
    }
}

void GamePlayServer::InitializeIOThread() {
    threadPool[0] = new std::thread([this]() { this->IOThread(); });
}

void GamePlayServer::InitializeWorkerThreads() {
    for (int i = 1; i < GetAvailableThreadCount(); ++i) {
        threadPool[i] = new std::thread([this]() { this->WorkerThread(); });
    }
}

void GamePlayServer::InitializeThreadPool() {
    auto availableThreadCount = GetAvailableThreadCount();
    threadPool = new std::thread*[availableThreadCount];
    InitializeIOThread();
    InitializeWorkerThreads();
}

int GamePlayServer::GetAvailableThreadCount() const {
    return std::thread::hardware_concurrency() - 1;
}

void GamePlayServer::StartThreadPool() {
    const int available_threads = GetAvailableThreadCount();

    for (int i = 0; i < available_threads; ++i) {
        threadPool[i]->join();
    }
}

void GamePlayServer::StartToAccessPacketQueue() {
    while (packetQueue.empty());
    while (packetQueueMutex.try_lock());
}

void GamePlayServer::FinishToAccessPacketQueue() {
    packetQueue.pop();
    packetQueueMutex.unlock();
}

Packet GamePlayServer::GetNextPacket() {
    StartToAccessPacketQueue();
    auto packet = packetQueue.front();
    FinishToAccessPacketQueue();

    return packet;
}
