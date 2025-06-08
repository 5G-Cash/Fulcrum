#include "X16RV2.h"
#include "hash_algos.h"
#include "../../bitcoin/uint256.h"
#include <algorithm>

namespace X16RV2 {

QByteArray HashX16RV2(const QByteArray &header, const QByteArray &prevHash)
{
    bitcoin::uint256 prev;
    if (prevHash.size() == bitcoin::uint256::width())
        std::copy(prevHash.rbegin(), prevHash.rend(), prev.begin());
    else
        prev.SetNull();

    const uint8_t *pbegin = reinterpret_cast<const uint8_t *>(header.constData());
    const uint8_t *pend = pbegin + header.size();
    const bitcoin::uint256 result = ::HashX16RV2(pbegin, pend, prev);

    QByteArray out(bitcoin::uint256::width(), Qt::Uninitialized);
    std::copy(std::reverse_iterator(result.end()), std::reverse_iterator(result.begin()),
              reinterpret_cast<uint8_t *>(out.data()));
    return out;
}

} // namespace X16RV2
