#pragma once

#include <cstdint>
#include "Record.h"


static int16_t offset(const uint32_t ovc) {
    if ((ovc >> 30) == 0)
        return -1;
    return (ovc >> 16) & 0x3FFF;
}

static uint32_t genOVC(const uint16_t offset, const uint16_t value) {
    return (0b01 << 30) + (offset << 16) + (0xFFFF - value);
}