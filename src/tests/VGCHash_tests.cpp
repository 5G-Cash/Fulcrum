#include "Tests.h"
#include "BTC.h"

TEST_SUITE(vgc_hash)

TEST_CASE(genesis_block)
{
    const QByteArray header = QByteArray::fromHex(
        "020000000000000000000000000000000000000000000000000000000000000000000000828c667adb0a0f16ec1a83f793293262fa3ce6f2fa9de3d738cf58d192f8d99ac0ff1c5fffff001ef8381f00");
    const QByteArray expected = QByteArray::fromHex(
        "000000b3cf5064a01dcdc8931f5bae3cc38c6af1aec07f4459903e9eebae986a");
    const QByteArray got = BTC::hashBlockForCoin(header, BTC::Coin::VGC);
    TEST_CHECK(got == expected);
}

TEST_SUITE_END()
