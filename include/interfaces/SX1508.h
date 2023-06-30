//
// Created by william on 22/06/23.
//

#ifndef SC_BATTERY_TEST_JIG_SX1508_H
#define SC_BATTERY_TEST_JIG_SX1508_H

#include <stdio.h>
#include "pico/stdlib.h"
#include "pico/binary_info.h"
//#include "hardware/i2c.h"

#define KEY_ALERT_PIN 19

namespace _SX1508 {
    void initSX1508();

    uint8_t fetchKeyPresses();
}

#endif //SC_BATTERY_TEST_JIG_SX1508_H
