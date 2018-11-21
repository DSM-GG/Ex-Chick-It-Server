//
// Created by moreal-gram on 2018-08-29.
//

#include <iostream>
#include <thread>

#include "core/gameplayserver.h"

int main() {
    GamePlayServer server(40000);

    server.StartServer();

    return 0;
}