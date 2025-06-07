#ifndef FULCRUM_HASHX16RV2_H
#define FULCRUM_HASHX16RV2_H

#include "bitcoin/uint256.h"
#include <cstdint>

uint256 HashX16RV2(const uint8_t* begin, const uint8_t* end, const uint256& prevHash);

#endif // FULCRUM_HASHX16RV2_H
