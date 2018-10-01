//
// Created by moreal-gram on 2018-08-29.
//

#include <iostream>
#include <thread>

#include "core/gameplayserver.h"
#include <base64.h>
#include "core/gameplayserver.h"

int main() {
    LogicServer server(4000);

    server.StartServer();

    return 0;
}