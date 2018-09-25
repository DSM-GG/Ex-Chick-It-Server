//
// Created by moreal-gram on 2018-08-29.
//

#include <iostream>
#include <thread>

#include "core/logicserver.h"
#include <base64.h>
#include "core/logicserver.h"

int main() {
    LogicServer server(4000);

    server.StartServer();

    return 0;
}