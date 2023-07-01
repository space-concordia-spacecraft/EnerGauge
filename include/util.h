//
// Created by william on 01/07/23.
//

#ifndef SC_BATTERY_TEST_JIG_UTIL_H
#define SC_BATTERY_TEST_JIG_UTIL_H

#include "pico/binary_info.h"

uint8_t constrain(uint8_t value, uint8_t low, uint8_t high) {
    return value > high ? high : value < low ? low : value;
}

#endif //SC_BATTERY_TEST_JIG_UTIL_H
