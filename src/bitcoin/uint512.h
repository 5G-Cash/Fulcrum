#pragma once

#include "uint256.h"

namespace bitcoin {

/** 512-bit opaque blob. */
class uint512 : public base_blob<512> {
public:
    using base_blob<512>::base_blob;
    explicit constexpr uint512(const base_blob<512> &b) noexcept : base_blob<512>(b) {}
};

} // namespace bitcoin
