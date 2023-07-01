//
// Created by william on 22/06/23.
//

#ifndef SC_BATTERY_TEST_JIG_KEYPAD_H
#define SC_BATTERY_TEST_JIG_KEYPAD_H

#include <stdio.h>
#include "pico/stdlib.h"
#include "pico/binary_info.h"
#include "hardware/i2c.h"

#define KEY_ALERT_PIN 19

#define KEY_ROWS 4
#define KEY_COLS 2

const char KEYPAD[KEY_ROWS][KEY_COLS] = {
        {'1', '2'},
        {'3', '4'},
        {'5', '6'},
        {'*', '#'}};

const uint SX1508_ADDRESS = 0x3E;

class Keypad {
private:
    uint8_t readKeyData();

public:
    Keypad();

    bool validate();

    void setup(uint8_t rows, uint8_t columns, uint8_t scanTime, uint8_t debounceTime);

    bool inputAvailable();
};

#endif //SC_BATTERY_TEST_JIG_KEYPAD_H
