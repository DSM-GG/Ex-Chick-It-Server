//
// Created by moreal-gram on 2018-09-04.
//

#ifndef WSL_LOGINPACKET_H
#define WSL_LOGINPACKET_H

#include "packet.h"


class LoginPacket : public Packet {
public:
    struct LoginData {
        uint32_t id;
        uint32_t pw;
    };

    uint32_t& GetId() { return GetData().id; }
    uint32_t& GetPw() { return GetData().pw; }

private:
    inline LoginData& GetData() { return *reinterpret_cast<LoginData*>(GetBuffer()); }
};

#endif //WSL_LOGINPACKET_H