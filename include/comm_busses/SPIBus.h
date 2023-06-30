//
// Created by william on 30/06/23.
//

#ifndef SC_BATTERY_TEST_JIG_SPIBUS_H
#define SC_BATTERY_TEST_JIG_SPIBUS_H

#include <stdio.h>
#include "pico/stdlib.h"
#include "pico/binary_info.h"

#define SPI_SCLK_PIN 24
#define SPI_MOSI_PIN 25

namespace SPI {
    void init();

    void dataWrite(unsigned char d, uint CS);
}

#endif //SC_BATTERY_TEST_JIG_SPIBUS_H
