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
#define KEY_COLS 4

enum KeyButton {
    NUM_1 = 0,
    NUM_2,
    NUM_3,
    NUM_A,
    NUM_4,
    NUM_5,
    NUM_6,
    NUM_B,
    NUM_7,
    NUM_8,
    NUM_9,
    NUM_C,
    NUM_STAR,
    NUM_0,
    NUM_POUND,
    NUM_D,
    NUM_INVALID
};

const char KEY_LETTERS[16] = {
        '1',
        '2',
        '3',
        'A',
        '4',
        '5',
        '6',
        'B',
        '7',
        '8',
        '9',
        'C',
        '*',
        '0',
        '#',
        'D'
};

const KeyButton KEYPAD[KEY_ROWS][KEY_COLS] = {
        {NUM_1, NUM_2, NUM_3, NUM_A},
        {NUM_4, NUM_5, NUM_6, NUM_B},
        {NUM_7, NUM_8, NUM_9, NUM_C},
        {NUM_STAR, NUM_0, NUM_POUND, NUM_D}};

const uint SX1508_ADDRESS = 0x3E;

class Keypad {
private:
    uint8_t readKeyData();

    uint8_t getRow(uint8_t keyData);

    uint8_t getCol(uint8_t keyData);

public:
    Keypad();

    bool validate();

    void setup(uint8_t rows, uint8_t columns, uint8_t scanTime, uint8_t debounceTime);

    bool inputAvailable();

    KeyButton getKeyInput();
};

#endif //SC_BATTERY_TEST_JIG_KEYPAD_H
