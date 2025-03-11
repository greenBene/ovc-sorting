#pragma once

#include <cstdint>

/*
    (Negative) Ascending Offset-value coding (32bit)
    [2bit] - Flag
    [14bit] - Offset
    [16bit] - Value

    Flag:

 */


constexpr uint32_t POSITIVE_AOVC_ZERO = 0x40000000;
constexpr uint32_t NEGATIVE_AOVC_ZERO = 0x80000000;
constexpr uint32_t MINUS_INFINITY = 0x00000000;
constexpr uint32_t PLUS_INFINITY = 0xC0000000;



static uint32_t generatePositiveAOVC(const uint16_t arity, const uint16_t offset, const uint16_t value) {
    return (0b01 << 30) | (((arity - offset) << 16) + value);
}

static uint32_t generateNegativeAOVC(const uint16_t arity, const uint16_t offset, const uint16_t value) {
    return (0b01 << 30) | (((0x3FFF ^ (arity-offset )) << 16) + value);
}

static int getOffsetAOVC(const uint32_t aovc, const uint16_t arity) {
    if (aovc >> 30 == 0 || aovc >> 30 == 3) {
        return -1;
    }
    if (aovc >> 29 == 0b011) { // Negative
        return arity - (((aovc >> 16) & 0x3FFF) ^ 0x3FFF);
    } else {
        return arity - (aovc >> 16) & 0x3FFF;
    }
}

static uint16_t getValueAOVC(const uint32_t aovc) {
    if (aovc >> 30 == 0 || aovc >> 30 == 3) {
        return 0;
    }
    return aovc & 0x0000FFFF;
}

