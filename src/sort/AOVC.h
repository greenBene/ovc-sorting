#pragma once

#include <cstdint>

/*
    (Negative) Ascending Offset-value coding (32bit)
    [2bit] - Flag
    [14bit] - Offset
    [16bit] - Value

    Flag:

 */


// static uint32_t offset(const uint32_t ovc) {
//     if ((ovc >> 30) == 0)
//         return -1;
//     return (ovc >> 16) & 0x3FFF;
// }
//
// static uint16_t value(const uint32_t ovc) {
//     if ((ovc >> 30) == 0) {
//         return 0;
//     }
//     return 0xFFFF - (ovc & 0x0000FFFF);
// }

static uint32_t genAOVC(const uint16_t arity, const bool negative, const uint16_t offset,  const uint16_t value) {

    if (!negative) {
        return (0b01 << 30) | (((arity - offset) << 16) + value);
    }
    else {
        return (0b01 << 30) | (((0x3FFF ^ (arity-offset )) << 16) + value);
    }

}

static int offsetAOVC(const uint32_t aovc, const uint16_t arity) {
    if (aovc >> 30 == 0) {
        return -1;
    }
    if (aovc >> 29 == 0b011) { // Negative
        return arity - (((aovc >> 16) & 0x3FFF) ^ 0x3FFF);
    } else {
        return arity - (aovc >> 16) & 0x3FFF;
    }
}

static uint16_t valueAOVC(const uint32_t aovc) {
    if (aovc >> 30 == 0 || aovc >> 30 == 3) {
        return 0;
    }
    return aovc & 0x0000FFFF;
}

