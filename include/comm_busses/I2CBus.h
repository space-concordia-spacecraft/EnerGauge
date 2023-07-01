//
// Created by william on 22/06/23.
//

#ifndef SC_BATTERY_TEST_JIG_I2CBUS_H
#define SC_BATTERY_TEST_JIG_I2CBUS_H

#include <stdio.h>
#include "pico/stdlib.h"
#include "pico/binary_info.h"
#include "hardware/i2c.h"

namespace I2C {
    void init();

    uint8_t readByte(uint8_t deviceAddress, uint8_t registerAddress);

    /*
     * A 16-bit uint16_t will be returned.
     *  - The msb of the return value will contain the value read from registerAddress
     *  - The lsb of the return value will contain the value read from registerAddress + 1
    */
    uint16_t readWord(uint8_t deviceAddress, uint8_t registerAddress);

    /*
     *  - writeValue is written to registerAddress
     *  - Return value: true if succeeded, false if failed
    */
    bool writeByte(uint8_t deviceAddress, uint8_t registerAddress, uint8_t writeValue);
}

#endif //SC_BATTERY_TEST_JIG_I2CBUS_H
