//
// Created by william on 22/06/23.
//

#include "interfaces/Keypad.h"
#include "Definitions.h"
#include "interfaces/SX1508BRegisters.h"
#include "comm_busses/I2CBus.h"

using namespace SX1508B::DeviceAndIO;
using namespace SX1508B::DebounceAndKeypadEngine;

Keypad::Keypad() {
    gpio_init(KEY_ALERT_PIN);
    gpio_set_dir(KEY_ALERT_PIN, GPIO_IN);
}

bool Keypad::validate()
{
    // Communication test. We'll read from a registers to verify communication.
    uint8_t testRegisters = I2C::readByte(SX1508_ADDRESS, RegInterruptMask); // This should return 0xFF00

    // Then read a byte that should be 0x00
    return testRegisters == 0xFF;
}

void Keypad::setup(uint8_t rows, uint8_t columns, uint8_t scanTime, uint8_t debounceTime) {
    // Enable interrupt on NINT pin
    I2C::writeByte(SX1508_ADDRESS, RegInterruptMask, 0x00);

    // Each IO should be setup as inputs by default

    // Config debouncing
    uint8_t debounceTimeBits = debounceTime & 0b111;
    I2C::writeByte(SX1508_ADDRESS, RegDebounceConfig, debounceTimeBits);
    I2C::writeByte(SX1508_ADDRESS, RegDebounceEnable, 0xFF); // Enable debounce on all keys

    // Config keys
    uint8_t numRowsBits = (rows & 0b11) << 5; // Number of rows is 6:5
    uint8_t numColumnsBits = (columns & 0b11) << 3; // Number of columns is 3:4
    uint8_t scanTimeBits = scanTime & 0b111; // Scan time is bits 2:0
    uint8_t keyConfigByte = numRowsBits | numColumnsBits | scanTimeBits;
    I2C::writeByte(SX1508_ADDRESS, RegKeyConfig, keyConfigByte);
}

bool Keypad::inputAvailable() {
    return gpio_get(KEY_ALERT_PIN) == LOW;
}

KeyButton Keypad::getKeyInput() {
    if (!inputAvailable()) {
        return NUM_INVALID;
    } else {
        uint8_t keyData = readKeyData();

        uint8_t row = getRow(keyData);
        uint8_t col = getCol(keyData);

        return KEYPAD[row][col];
    }
}

uint8_t Keypad::readKeyData() {
    return (0xFFFF ^ I2C::readByte(SX1508_ADDRESS,RegKeyData));
}


uint8_t Keypad::getRow(uint8_t keyData) {
    uint8_t rowData = uint8_t(keyData & 0x0F);

    for (uint8_t i = 0; i < 4; i++)
    {
        if (rowData & (1 << i))
            return i;
    }
    return 0;
}

uint8_t Keypad::getCol(uint8_t keyData) {
    uint8_t colData = uint8_t((keyData & 0xF0) >> 4);

    for (uint8_t i = 0; i < 4; i++)
    {
        if (colData & (1 << i))
            return i;
    }
    return 0;
}