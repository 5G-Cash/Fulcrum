#include "Tests.h"
#include "BTC.h"
#include "bitcoin/block.h"
#include <QFile>

TEST_SUITE(vgc_extension)
{
    TEST_CASE(no_extension_block)
    {
        const QString path = ":testdata/vgc_block.bin";
        QFile f(path);
        TEST_CHECK_MESSAGE(f.open(QFile::ReadOnly), "Unable to open resource");
        const QByteArray blockData = f.readAll();
        const int baseHdr = BTC::GetBlockHeaderSize();
        const int extSz   = BTC::extraHeaderSizeForCoin(BTC::Coin::VGC);
        static const QByteArray kVgcExt{"VGC!",4};
        bool hasExtra = blockData.size() >= baseHdr + extSz &&
                         blockData.mid(baseHdr, extSz) == kVgcExt;
        TEST_CHECK(!hasExtra);
        auto trimmed = blockData;
        if (hasExtra) trimmed.remove(baseHdr, extSz);
        auto blk = BTC::Deserialize<bitcoin::CBlock>(trimmed, 0, false, false, true, false);
        TEST_CHECK(!blk.vtx.empty());
    };
}
TEST_SUITE_END()
