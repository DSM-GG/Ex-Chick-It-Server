//
// Created by moreal-gram on 2018-08-29.
//

#include <iostream>
#include <thread>

#include "core/loginserver.h"
#include <base64.h>
#include "core/loginserver.h"

int main() {
    LoginServer server(4000);

    server.StartServer();

    return 0;
}