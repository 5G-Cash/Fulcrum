#include "crypto/vgc/HashX16RV2.h"
#include "bitcoin/block.h"
#include <cassert>
#include <cstring>
#include <iostream>

int main()
{
    // Genesis block header for 5G-CASH
    const unsigned char header[80] = {
        0x02,0x00,0x00,0x00, // version
        // prevhash
        0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
        // merkle root (reversed)
        0x82,0xc8,0x66,0x7a,0xdb,0x0a,0x0f,0x16,0xec,0x1a,0x83,0xf7,0x93,0x29,0x32,0x62,
        0xfa,0x3c,0xe6,0xf2,0xfa,0x9d,0xe3,0xd7,0x38,0xcf,0x58,0xd1,0x92,0xf8,0xd9,0x9a,
        // time
        0xc0,0xff,0x1c,0x5f,
        // bits
        0xff,0xff,0x00,0x1e,
        // nonce
        0xf8,0x38,0x1f,0x00
    };

    uint256 prev; prev.SetNull();
    uint256 h = HashX16RV2(header, header+80, prev);
    const char *expected = "000000b3cf5064a01dcdc8931f5bae3cc38c6af1aec07f4459903e9eebae986a";
    std::string got = h.GetHex();
    assert(got == expected);
    std::cout << "x16rv2 hash OK" << std::endl;
    return 0;
}
