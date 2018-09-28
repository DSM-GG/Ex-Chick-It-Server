//
// Created by moreal-gram on 2018-09-04.
//

#ifndef WSL_REGISTERPACKET_H
#define WSL_REGISTERPACKET_H

#include "packet.h"


class RegisterPacket : Packet {
public:
    struct RegisterData {
        uint32_t id;
        uint32_t pw;
    };

    uint32_t& GetId() { return GetDataAsAccountData().id; }
    uint32_t& GetPw() { return GetDataAsAccountData().pw; }

private:
//    inline RegisterData& GetData() { return *reinterpret_cast<RegisterData*>(GetBuffer()); }
};

#endif //WSL_REGISTERPACKET_H