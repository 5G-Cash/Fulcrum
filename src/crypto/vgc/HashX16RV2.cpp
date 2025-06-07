#include "HashX16RV2.h"
#include "x16Rv2/hash_algos.h"

uint256 HashX16RV2(const uint8_t* begin, const uint8_t* end, const uint256& prevHash)
{
    return ::HashX16RV2<const uint8_t*>(begin, end, prevHash);
}
