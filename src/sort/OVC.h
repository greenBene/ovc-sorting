#pragma once

#include <cstdint>

constexpr uint32_t OVC_MINUS_INFINITY = 0x00000000;
constexpr uint32_t OVC_PLUS_INFINITY = 0xC0000000;

// TODO improve offset return type
static int getOffsetOVC(const uint32_t ovc) {
    if ((ovc >> 30) == 0 || (ovc >> 30) == 3)
        return -1;
    return (ovc >> 16) & 0x3FFF;
}

static int getValueOVC(const uint32_t ovc) {
    if ((ovc >> 30) == 0 || (ovc >> 30) == 3) {
        return 0;
    }
    return 0xFFFF - (ovc & 0x0000FFFF);
}

static uint32_t generateOVC(const uint16_t offset, const uint16_t value) {
    return (0b01 << 30) + (offset << 16) + (0xFFFF - value);
}