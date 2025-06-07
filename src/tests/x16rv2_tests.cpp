#include "Tests.h"
#include "BTC.h"
#include <algorithm>

TEST_SUITE(x16rv2)
{
    TEST_CASE(genesis_hash)
    {
        QByteArray header = QByteArray::fromHex("020000000000000000000000000000000000000000000000000000000000000000000000828c667adb0a0f16ec1a83f793293262fa3ce6f2fa9de3d738cf58d192f8d99ac0ff1c5fffff001ef8381f00");
        auto h = BTC::hashBlockForCoin(header, BTC::Coin::VGC);
        std::reverse(h.begin(), h.end());
        TEST_CHECK(h.toHex() == "000000b3cf5064a01dcdc8931f5bae3cc38c6af1aec07f4459903e9eebae986a");
    }
}
