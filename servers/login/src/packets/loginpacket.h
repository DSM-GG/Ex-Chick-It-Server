//
// Created by moreal-gram on 2018-09-04.
//

#ifndef WSL_LOGINPACKET_H
#define WSL_LOGINPACKET_H

#include "packet.h"


class LoginPacket : public Packet {
public:
    uint32_t& GetId() { return GetDataAsAccountData().id; }
    uint32_t& GetPw() { return GetDataAsAccountData().pw; }
};

#endif //WSL_LOGINPACKET_H